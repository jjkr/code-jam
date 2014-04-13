#!/usr/bin/python3
import sys


mines = []
found = False
def expand_front(boundary, area_needed, r, c, m):
    '''front is an array of (length,is_horizontal) tuples'''
    global found
    print(area_needed)
    if area_needed < 2:
        return
    last = boundary[0]
    for i in range(1, len(boundary)):
        p = boundary[i]
        print(p)
        if p[0] == r and last[0] == r:
            continue
        if p[1] == c and last[1] == c:
            continue
        dx = abs(p[0] - last[0])
        dy = abs(p[1] - last[1])
        if dx == 0 and p[1] != c:
            print(area_needed)
            print(dy)
            last[1] += 1
            p[1] += 1
            area_needed -= dy
        if dy == 0:
            print('expanding x')
            last[0] += 1
            p[0] += 1
            area_needed -= dx
        if area_needed == 0:
            print('FOUND!!!!!')
            found = True
        if area_needed < 2:
            continue
        expand_front(boundary, area_needed, r, c, m)

    #print(expansions)


def find_lucky_minefield(r, c, m):
    if r < 1 or c < 1 or m < 0:
        return None
    mines = [[0] * c for i in range(r)]
    if m == 0:
        mines[0][0] = 2
        return mines
    free_spaces = r * c - m
    if free_spaces < 1:
        return None
    if free_spaces > r*c:
        return None
    if free_spaces == 1:
        mines[0][0] = 2
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    continue
                mines[i][j] = 1
        return mines
    if free_spaces == 3:
        if r > 2:
            mines[0][0] = 0
            mines[1][0] = 2
            mines[2][0] = 0
        elif c > 2:
            mines[0][0] = 0
            mines[0][1] = 2
            mines[0][2] = 0
        else:
            return None
        return mines
    if r == 1:
        for i in range(free_spaces, c):
            mines[0][i] = 1
        if free_spaces == 2:
            mines[0][0] = 2
        elif free_spaces == 3:
            mines[0][1] = 2
        else:
            return None
        return mines
    if c == 1:
        for i in range(free_spaces, r):
            mines[i][0] = 1
        if free_spaces == 2:
            mines[0][0] = 2
        elif free_spaces == 3:
            mines[1][0] = 2
        else:
            return None
        return mines
    #bound = [[1, 0], [1, 1], [0, 1]]
    #expand_front(bound, area_needed, r, c, m)
    mines = [[1] * c for i in range(r)]
    mines[0][0] = 2
    mines[0][1] = 0
    mines[1][1] = 0
    mines[1][0] = 0
    area_needed = r*c - m - 4
    if area_needed == 0:
        return mines
    if area_needed < 2:
        return None
    for i in range(2,len(mines)):
        if area_needed == 0:
            return mines
        if area_needed < 2:
            return None
        if area_needed == 3:
            if c <= 2:
                return None
            mines[0][2] = 0
            mines[1][2] = 0
            mines[2][2] = 0
            return mines
        area_needed -= 2
        mines[i][0] = 0
        mines[i][1] = 0
    col = 2
    if area_needed == 0:
        return mines
    if area_needed < 2:
        return None
    while col != c:
        if area_needed == 1:
            mines[r-1][col-1] = 1
            area_needed += 1
        mines[0][col] = 0
        mines[1][col] = 0
        area_needed -= 2
        if area_needed == 0:
            return mines
        if area_needed < 0:
            return None
        if area_needed == 3:
            if c <= col+1:
                return None
            mines[0][col+1] = 0
            mines[1][col+1] = 0
            mines[r-1][col-1] = 1
            return mines
        for i in range(2,len(mines)):
            area_needed -= 1
            mines[i][col] = 0
            if area_needed == 0:
                return mines
            if area_needed < 0:
                return None
            if area_needed == 3:
                if c <= col+1:
                    return None
                mines[0][col+1] = 0
                mines[1][col+1] = 0
                mines[r-1][col-1] = 1
                return mines
        col += 1
        if area_needed == 0:
            return mines

    return mines


def print_minefield(mf):
    mine_chars = ['.', '*', 'c']
    for row in mf:
        print(''.join([mine_chars[m] for m in row]))


def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        inputs = [int(s) for s in sys.stdin.readline().split()]
        print('Case #' + str(i + 1) + ':')
        mf = find_lucky_minefield(inputs[0], inputs[1], inputs[2])
        if mf is not None:
            print_minefield(mf)
        else:
            print('Impossible')

if __name__ == '__main__':
    #mf = find_lucky_minefield(3, 5, 9)
    #print_minefield(mf)
    main()
