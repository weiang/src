#! /usr/bin/python

import sys

def repeat(name, flag):
	"""Return the string name repeated 3 times
	If flag is true, add !!!
	"""

	result = name * 3
	if flag:
		result = result + '!!!'
	return result


def main(name):
	if name == 'weiang':
		print repeat(name, True)
	else:
		print repeat(name, False)

if __name__ == '__main__':
	main(sys.argv[1])