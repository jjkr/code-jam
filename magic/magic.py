#!/bin/python3
import sys


def read_int():
    return int(sys.stdin.readline())


def read_arrangement():
    a = {}
    for row in range(1, 5):
        for s in sys.stdin.readline().split():
            a[s] = row
    return a


def find_cards(answers, card_arrs):
    possible = []
    winners = []
    for ans, arr in zip(answers, card_arrs):
        p = [card_number for card_number in arr if arr[card_number] == ans]
        # print('p ' + str(p))
        for c in p:
            if c in possible:
                winners.append(c)
            else:
                possible.append(c)
    return winners


def main():
    T = read_int()
    for i in range(0, T):
        a1 = read_int()
        board1 = read_arrangement()
        a2 = read_int()
        board2 = read_arrangement()
        cards = find_cards([a1, a2], [board1, board2])
        case_prefix = 'Case #' + str(i+1) + ': '
        num_cards = len(cards)
        if num_cards == 1:
            msg = str(cards[0])
        elif num_cards == 0:
            msg = 'Volunteer cheated!'
        else:
            msg = 'Bad magician!'
        print(case_prefix + msg)

if __name__ == '__main__':
    main()
