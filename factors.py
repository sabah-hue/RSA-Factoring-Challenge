#!/usr/bin/python3
import sys
import time

def factors():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()
    try:
        start = time.time()
        with open(sys.argv[1], 'r') as stream:
            for line in stream:
                number = int(line)
                primary = 2
                if number % primary == 0:
                    print("{}={}*{}".format(number, number // primary, primary))
                    continue
                primary = primary + 1
                while primary < number // 2:
                    if number % primary == 0:
                        print("{}={}*{}".format(number, number // primary, primary))
                        break
                    primary = primary + 2
                    if primary == (number // 2) + 1:
                        print(f"{number}={number}*{1}")
    except (IndexError):
        pass
    if time.time() - start > 5:
        print("Time limitbexceeded")
        exit()

factors()
