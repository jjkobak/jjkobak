import random
import numpy as np
bigarray = [[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16],
            [5, 6, 7, 8, 1, 2, 3, 4, 13, 14, 15, 16, 9, 10, 11, 12],
            [9, 10, 11, 12, 13, 14, 15, 16, 1, 2, 3, 4, 5, 6, 7, 8],
            [13, 14, 15, 16, 9, 10, 11, 12, 5, 6, 7, 8, 1, 2, 3, 4],
            [2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15],
            [6, 5, 8, 7, 2, 1, 4, 3, 14, 13, 16, 15, 10, 9, 12, 11],
            [10, 9, 12, 11, 14, 13, 16, 15, 2, 1, 4, 3, 6, 5, 8, 7],
            [14, 13, 16, 15, 10, 9, 12, 11, 6, 5, 8, 7, 2, 1, 4, 3],
            [3, 4, 1, 2, 7, 8, 5, 6, 11, 12, 9, 10, 15, 16, 13, 14],
            [7, 8, 5, 6, 3, 4, 1, 2, 15, 16, 13, 14, 11, 12, 9, 10],
            [11, 12, 9, 10, 15, 16, 13, 14, 3, 4, 1, 2, 7, 8, 5, 6],
            [15, 16, 13, 14, 11, 12, 9, 10, 7, 8, 5, 6, 3, 4, 1, 2],
            [4, 3, 2, 1, 8, 7, 6, 5, 12, 11, 10, 9, 16, 15, 14, 13],
            [8, 7, 6, 5, 4, 3, 2, 1, 16, 15, 14, 13, 12, 11, 10, 9],
            [12, 11, 10, 9, 16, 15, 14, 13, 4, 3, 2, 1, 8, 7, 6, 5],
            [16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]]

for i in range(16):
    for j in range(16):
        bigarray[i][j]*=(random.randint(0,1))

print(np.matrix(bigarray))

def possible(y, x, n):
    global bigarray

    for i in range(16):
        if bigarray[y][i] == n:
            return False

    for i in range(16):
        if bigarray[i][x] == n:
            return False
    y0 = (y // 4) * 4
    x0 = (x // 4) * 4
    for i in range(4):
        for j in range(4):
            if bigarray[y0 + i][x0 + j] == n:
                return False
    return True

def solve():
    global bigarray

    for y in range(16):

        for x in range(16):
            if bigarray[y][x] == 0:
                for n in range(1, 17):
                    if possible(y, x, n):
                        bigarray[y][x] = n
                        solve()
                        bigarray[y][x] = 0
                return
    print(np.matrix(bigarray))
    input("More?")

solve()