#!/usr/bin/python3
"""Program that given a list of non-negative integers
representing walls of width 1, calculate how much water
will be retained after it rains."""


def rain(walls):
    """Function that given a list of non-negative integers
    representing walls of width 1, calculate how much water
    will be retained after it rains."""
    if(not len(walls)):
        return 0
    n = len(walls)
    ans = 0
    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        ans = ans + (min(left, right) - walls[i])
    return ans
