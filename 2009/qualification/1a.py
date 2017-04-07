def is_happy(n, base):
    print('is', n, 'happy in base', base)
    acc = 0
    while n > 0:
        print('JJK', acc, n)
        acc += (n % base) ** 2
        n = int(n / base)
    return acc == 1

with open('A-test.in') as f:
    T = int(next(f))
    for i in range(T):
        bases = [int(x) for x in next(f).split()]

        n = 3

        for b in bases:
            print(b)
            print(is_happy(n, b))

