#!/usr/bin/python3
"""Program that determines if a given data
set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """Function that determines if a given data
    set represents a valid UTF-8 encoding"""
    ct = 0
    for i in data:
        if  ct == 0:
            if (i >> 5) == 0b110:
                ct = 1
            elif (i >> 4) == 0b1110:
                ct = 2
            elif (i >> 3) == 0b11110:
                ct = 3
            elif (i >> 7):
                return False
        else:
            if (i >> 6) != 0b10:
                return False
            ct -= 1
    return  ct == 0
