from sys import stdin


def read():
    return stdin.readline()

def main():
    n = int(read())
    for l in range(n):
        count = 0
        s = int(read())
        se = []
        for i in range(s):
            se.append(read())
        qn = int(read())
        qu = []
        for i in range(qn):
            qu.append(read())
        queried = {}
        for q in qu:
            #print('q ' + str(queried))
            queried[q] = True
            if len(queried) >= len(se):
                count += 1
                queried = {}
                queried[q] = True

        print('Case #' + str(l+1) + ': ' + str(count))

if __name__ == '__main__':
    main()
