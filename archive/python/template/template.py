from sys import stdin


def read():
    return stdin.readline()


def main():
    num_cases = int(read())
    for num in num_cases:
        prefix = 'Case #' + str(num) + ': '

        inputs = [int(s) for s in read().split()]

        print(prefix)


if __name__ == '__main__':
    main()
