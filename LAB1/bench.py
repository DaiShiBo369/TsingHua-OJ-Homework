#!/usr/bin/env python3
import sys
import subprocess
import time

def bench(exe, infile, runs=5):
    times = []
    for i in range(runs):
        start = time.perf_counter()
        # run executable, silence stdout
        p = subprocess.run([exe], stdin=open(infile,'rb'), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        end = time.perf_counter()
        times.append(end-start)
    return times

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print('Usage: bench.py <exe> <input> <runs>')
        sys.exit(2)
    exe = sys.argv[1]
    infile = sys.argv[2]
    runs = int(sys.argv[3])
    t = bench(exe, infile, runs)
    for v in t:
        print('{:.6f}'.format(v))