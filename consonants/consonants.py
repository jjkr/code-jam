import sys


def is_vowel(c):
    vowels = ['a', 'e', 'i', 'o', 'u']
    try:
        vowels.index(c)
        return True
    except:
        return False


def nvalue(s, n):
    print('NVAL')
    print(s + str(n))
    substrs = []
    i=0
    while i<= len(s)-n:
        # print( 'I LOOP' )
        j = 0
        while not is_vowel(s[i+j]):
            #print(s[i+j])
            j += 1
            if i+j > len(s)-1:
                break
        if j >= n:
            substrs.append([i,j])
        i += j + 1
    print(substrs)
    return count_substrs(substrs, len(s), n)

def count_substrs(cstrs, l, n):
    count = 0
    low = 0
    for r in cstrs:
        for i in range(r[1]-n+1):
            print('i ' + str(i))
            for j in range(low, r[0]+i+1):
                print('substr ' + str(i) + ', ' + str(j))
                count += 1
        last = r
    return count


def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        prefix = 'Case #' + str(i+1) + ': '
        inputs = [s for s in sys.stdin.readline().split()]
        s = inputs[0]
        n = int(inputs[1])
        print(prefix + str(nvalue(s, n)))


if __name__ == '__main__':
    #print(nvalue('quartz', 3))
    main()
