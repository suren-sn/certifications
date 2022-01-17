#python3
class Solution:
    def numIslands(self, grid: 'List[List[str]]') -> int:
        m = len(grid)
        if m<1: return 0
        n = len(grid[0])
        if n<1: return 0

        visited = [[False]*n for i in range(m)]
        islandCount = 0

        for row in range(m):
            for col in range(n):
                if visited[row][col] == True: continue

                if grid[row][col] == "1":
                    islandCount+=1
                    self.traceIsland(grid, m, n, row, col, visited)
        return islandCount

    def traceIsland(self, grid, m, n, row, col, visited) -> None:
        #BFS
        queue = [(row, col)]

        while queue:
            row,col = queue.pop(0)
            visited[row][col] = True
            for r,c in [(0,-1), (0,1), (-1,0), (1,0)]:
                r=row+r
                c=col+c

                if r<0 or r>=m or c<0 or c>=n: continue
                if visited[r][c]: continue
                if grid[r][c] == "1": queue.append((r,c))

    def numIslandsWrongLogic(self, grid: 'List[List[str]]') -> int:
        m = len(grid)
        if m<1: return 0
        n = len(grid[0])
        if n<1: return 0

        visited = [[False]*n for i in range(m)]
        islandCount = 0
        for i in range(m):
            for j in range(n):
                if visited[i][j]: continue
                visited[i][j] = True
                if grid[i][j] == '0': continue

                # An island is possible
                for r,c in [(0,1), (0,-1), (1,0), (-1,0)]:
                    r=i+r
                    c=j+c

                    if r<0 or r>=m: continue
                    if c<0 or c>=n: continue
                    if visited[r][c]: continue
                    if grid[r][c] == '1': break

                    visited[r][c] = True
                else:
                    islandCount += 1

        return islandCount

def t0(s):
    grid = [
        ["0", "1"],
        ["1", "0"]
    ]
    return s.numIslands(grid)

def t1(s):
    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    return s.numIslands(grid)

def t2(s):
    grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    return s.numIslands(grid)

if __name__ == '__main__':
    s = Solution()
    print(f"exp:2   result:{t0(s)}")
    print(f"exp:1   result:{t1(s)}")
    print(f"exp:3   result:{t2(s)}")
