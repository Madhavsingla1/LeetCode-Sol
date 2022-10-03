class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        r,c = len(grid),len(grid[0])
        vis = set()
        res=0
        
        def dfs(i,j):
            if i<0 or i>=r or j<0 or j>=c or (i,j) in vis or grid[i][j]!='1':
               return
            
            vis.add((i,j))
            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)
        
        
        for i in range(r):
            for j in range(c):
                if (i,j) not in vis and grid[i][j]=='1':
                    res+=1
                    dfs(i,j)
        
        return res
        