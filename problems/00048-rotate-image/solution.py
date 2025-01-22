class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n//2):
            for j in range(i, n-i-1):
                element = matrix[i][j]
                for _ in range(4):
                    i,j = j,n-i-1
                    element, matrix[i][j] = matrix[i][j], element