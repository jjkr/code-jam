from sys import stdin


def read():
    return stdin.readline()


def main():
    num_cases = int(read())
    for num in range(num_cases):
        prefix = 'Case #' + str(num+1) + ': '

        read()
        s = 0
        v1 = sorted([int(s) for s in read().split()])
        v2 = sorted([int(s) for s in read().split()])
        #print('v1 ' + str(v1))
        #print('v2 ' + str(v2))
        for j in range(len(v1)):
            s += v1[j] * v2[len(v1)-1-j]

        print(prefix + str(s))


if __name__ == '__main__':
    main()
