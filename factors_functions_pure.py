#!/usr/bin/python3
import sys
from resource import getrusage as resource_usage, RUSAGE_SELF
from time import time as timestamp

def unix_time(function):
	start_time, start_resources = timestamp(), resource_usage(RUSAGE_SELF)
	function()
	end_resources, end_time = resource_usage(RUSAGE_SELF), timestamp()
	return "\nreal: {}\nuser: {}\nsys: {}\n".format(
		end_time - start_time,
		end_resources.ru_utime - start_resources.ru_utime,
		end_resources.ru_stime - start_resources.ru_stime)


def trial_division(n: int) -> int:
	while n % 2 == 0:
		return 2

	fNum = 3
	while fNum * fNum <= n:
		if n % fNum == 0:
			return fNum
		else:
			fNum += 2

	return 1

def print_factors():
	with open(sys.argv[1], 'r') as prime:
		line = prime.readline()
		while line != '':
			n = int(line)
			rep = trial_division(n)
			print("{}={}*{}".format(n, n//rep, rep))
			line = prime.readline()
