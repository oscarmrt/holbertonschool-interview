#!/usr/bin/python3
"""Program that Given a pile of coins of different values, determine
the fewest number of coins needed to meet a given amount total"""


def makeChange(coins, total):
    """Function that Given a pile of coins of different values, determine
    the fewest number of coins needed to meet a given amount total"""
    if total <= 0:
        return 0
    ct = 0
    coins.sort(reverse=True)
    for value in coins:
        tmp = int(total / value)
        total -= tmp * value
        ct += tmp
        if total == 0:
            return ct
    if total != 0:
        return -1
