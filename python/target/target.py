import sys
import math


def paint_needed(r, n):
    first_ring = n*(2*r + 1)
    if n == 1:
        return first_ring
    return first_ring + 4 * math.factorial(n-2)


def target_rings(r, t):
    n = 1
    while paint_needed(r, n) < t:
        n = n * 2
    for i in range(n // 2, n + 1):
        print('i ' + str(i))
        if paint_needed(r, i) > t:
            return i-1
    return n


def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        inputs = [int(s) for s in sys.stdin.readline().split()]
        print(target_rings(inputs[0], inputs[1]))

if __name__ == '__main__':
    main()
    print(paint_needed(3, 3))
