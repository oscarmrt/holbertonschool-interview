#!/usr/bin/python3
"""method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """Function to unlock all the boxes"""
    lengthBoxes = len(boxes)
    if not lengthBoxes:
        return False
    unlocked = [0]
    for key in unlocked:
        for box in boxes[key]:
            if box not in unlocked and box < lengthBoxes:
                unlocked.append(box)
    if len(unlocked) == lengthBoxes:
        return True
    return False
