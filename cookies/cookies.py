#!/usr/bin/python3
import sys


def fastest_game(farm_cost, farm_cookie_rate, goal):
    time = 0.0
    farms = 0.0
    cookie_rate = 2.0
    while True:
        current_rate = cookie_rate + farms * farm_cookie_rate
        time_next_farm = farm_cost / current_rate
        time_with_farm = time_next_farm + \
            goal / (current_rate + farm_cookie_rate)
        time_no_farm = goal / current_rate
        if time_with_farm > time_no_farm:
            return time + time_no_farm
        time += time_next_farm
        farms += 1


def main():
    T = int(sys.stdin.readline())
    for i in range(0, T):
        game_inputs = [float(s) for s in sys.stdin.readline().split()]
        prefix = 'Case #' + str(i + 1) + ': '
        print(prefix + str(fastest_game(game_inputs[0],
                                        game_inputs[1],
                                        game_inputs[2])))


if __name__ == '__main__':
    main()
