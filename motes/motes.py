import sys


def min_moves(a, motes):
    i = 0
    edits = 0
    while i < len(motes):
        #print('a ' + str(a))
        d = a - motes[i]
        if d > 0:
            a += motes[i]
            i += 1
        else:
            if len(motes) - i < d / a:
                edits += len(motes) - i
                break
            edits += 1
            a += motes[i] - 1
    return edits


def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        prefix = 'Case #' + str(i+1) + ': '
        inputs = [int(s) for s in sys.stdin.readline().split()]
        a = inputs[0]
        if a == 1:
            print(prefix + str(inputs[1]))
            continue
        motes = sorted([int(s) for s in sys.stdin.readline().split()])
        print(prefix + str(min_moves(a, motes)))


if __name__ == '__main__':
    main()
