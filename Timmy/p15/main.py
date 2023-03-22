def genBlankGrid(n):
    grid = []
    for r in range(n):
        row = []
        for c in range(n):
            row.append(0)
        grid.append(row)
    return grid

def getPathsForGridSizeN(n):
    n = n+1
    grid = genBlankGrid(n)
    for r in range(n):
        r_num = n - (1+r)
        for c in range(n):
            c_num = n - (1+c)
            paths = 0
            if r_num != n - 1:
                paths += grid[r_num + 1][c_num]
            if c_num != n - 1:
                paths += grid[r_num][c_num + 1]
            if r_num == n-1 and c_num == n-1:
                paths = 1
            grid[r_num][c_num] = paths
    return grid

def main():
    print(getPathsForGridSizeN(20))

main()