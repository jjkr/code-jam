import sys


def guess_cards(products, n, m, k):
    all_divisors = []
    for p in products:
        divisors = []
        for i in range(2, m+1):
            if p % i == 0:
                divisors.append(i)
        all_divisors.append(divisors)

    print(all_divisors)


def main():
    sys.stdin.readline()
    params = [int(s) for s in sys.stdin.readline().split()]
    r = params[0]
    n = params[1]
    m = params[2]
    k = params[3]
    for i in range(r):
        products = [int(s) for s in sys.stdin.readline().split()]
        guess_cards(products, n, m, k)

if __name__ == '__main__':
    main()
