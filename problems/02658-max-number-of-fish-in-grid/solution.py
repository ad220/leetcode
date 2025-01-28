class Solution:
    result : List[List[int]]

    def findMaxFish(self, grid: List[List[int]]) -> int:
        self.result = [[-1] * len(grid[0]) for _ in grid]
        max_result = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if self.result[i][j]==-1:
                    searched_cells = [[False] * len(grid[0]) for _ in grid]
                    n_fish = self.fishFromCell(grid,i,j, searched_cells)
                    self.applyToResult(searched_cells, n_fish)
                    if n_fish>max_result:
                        max_result = n_fish
        return max_result
    
    def fishFromCell(self, grid, i, j, searched_cells):
        if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]): return 0
        if grid[i][j]==0: return 0
        if searched_cells[i][j]: return 0
        
        searched_cells[i][j] = True
        return grid[i][j]\
        + self.fishFromCell(grid, i+1, j, searched_cells) \
        + self.fishFromCell(grid, i-1, j, searched_cells) \
        + self.fishFromCell(grid, i, j+1, searched_cells) \
        + self.fishFromCell(grid, i, j-1, searched_cells)

    def applyToResult(self, searched_cells, n_fish):
        for i in range(len(self.result)):
            for j in range(len(self.result[i])):
                if searched_cells[i][j]: self.result[i][j] = n_fish
