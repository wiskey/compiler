#!/usr/bin/env python 

import sys, os
####### Symbol, Env class
Symbol = str

class Env(dict):
	"An environment: a dict of {'var':val } pairs, with an outer Env."
	def __init__(self, parms=(), args=(), outer=None):
		self.update(zip(parms, args))
		self.outer = outer
	def find(self, var):
		"Find the innermost Env where var appers."
		return self if var in self else self.outer.find(var)

def add_globals(env):
	"Add some Scheme standard procedures to an environment."
	import math, operator as op 
	env.update(vars(math)) # sin, sqrt, ...
	env.update(
			{'+':op.add, '-':op.sub, '*':op.mul, '/':op.div, 'not':op.not_,
				'>':op.gt, '<':op.lt, '>=':op.ge, '<=':op.le, '=':op.eq,
				'equal?':op.eq, 'eq?':op.is_, 'length':len,
				'cons':lambda x,y:[x]+y, 'list':lambda *x:list(x), 
				'list?':lambda x: isa(x, list), 'null?':lambda x: x==[],
				'symbol?':lambda x: isa(x, Symbol)}
			)
	return env

isa = isinstance

global_env = add_globals(Env())

####### eval 
def eval(x, env=global_env):
	"Evaluate an expression in an environment."
	if isa(x, Symbol):			# variable reference
		return env.find(x)[x]
	elif not isa(x, list):		# constant literal
		return x
	elif x[0] == 'quote':		# (quote exp)
		(_, exp) = x
		return exp
	elif x[0] == 'if':			# (if test conseq alt)
		(_, test, conseq, alt) = x
		return eval((conseq if eval(test, env) else alt), env)
	elif x[0] == 'set!':		# (set! var exp)
		(_, var, exp) = x
		env.find(var)[var] = eval(exp, env)
	elif x[0] == 'define':	    # (define var exp)
		(_, var, exp) = x
		env[var] = eval(exp, env)
	elif x[0] == 'lambda':		# (lambda (var*) exp)
		(_, vars, exp) = x
		return lambda *args: eval(exp, Env(vars, args, env))
	elif x[0] == 'begin':		# (begin exp*)	
		for exp in x[1:]:
			val = eval(exp, env)
		return val
	else:						# (proc exp*)
		exps = [eval(exp, env) for exp in x]
		proc = exps.pop(0)
		return proc(*exps)

####### parse, read, and user interaction
def read(s):
	"Read a Scheme expression from a string."
	return read_from(tokenize(s))

parse = read

def tokenize(s):
	"Convert a string into a list of tokens."
	return s.replace('(', ' ( ').replace(')', ' ) ').split()

def read_from(tokens):
	"Read an expression from a sequence of tokens."
	if len(tokens) == 0:
		raise SyntaxError('unexpected EOF while reading')
	token = tokens.pop(0)
	if '(' == token:
		L = [ ]
		while tokens[0] != ')':
			L.append(read_from(tokens))
		tokens.pop(0) # pop off ')'
		return L
	elif ')' == token:
		raise SyntaxError('unexpected )')
	else:
		return atom(token)

def atom(token):
	"Numbers become numbers; every other token is a symbol."
	try: return int(token)
	except ValueError:
		try: return float(token)
		except ValueError:
			return Symbol(token)

def to_string(exp):
	"Convert a Python object back into a Lisp-readable string."
	return '('+' '.join(map(to_string, exp))+')' if isa(exp, list) else str(exp)

def repl(prompt='Lispy> '):
	"A prompt-read-eval-print loop."
	while True:
		code, count = '', 0
		try: 
			t = raw_input(prompt)
			while True:
				count += t.count('(') - t.count(')')
				code += ' ' + t
				if count == 0: break 
				t = raw_input()
		except EOFError: return 

		if len(code) < 2 : continue
		val = eval(parse(code))
		if val is not None: print to_string(val)

if __name__ == "__main__":
	repl()
	#argc = len(sys.argv)
	#if argc > 2:
	#	print "Usage: lispy.py [ INFILE ]"
	#elif: argc == 2:
	#	execute(sys.argv[1])
	#else:
	#	repl()

