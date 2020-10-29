#!/usr/bin/python3
"""Program that solves the N queens puzzle"""
import sys
K = 1

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)


def printSolution(board):
    """Function to print the solution"""
    solutionList = []
    global K
    K = K + 1
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                solutionList.append([i, j])
    print(solutionList)


def isSafe(board, row, col):
    """Function to check if we can place a queen on board"""
    for i in range(col):
        if board[row][i]:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < N:
        if board[i][j]:
            return False
        i = i + 1
        j = j - 1
    return True


def solveNQUtil(board, col):
    """Recursive function to solve N queen"""
    if col == N:
        printSolution(board)
        return True
    ans = False
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            ans = solveNQUtil(board, col + 1) or ans
            board[i][col] = 0
    return ans


def solveNQ():
    """Backtraining for N queen"""
    board = [[0 for j in range(N)] for i in range(N)]
    if solveNQUtil(board, 0) is False:
        pass
        return
    return


solveNQ()
