class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        r, c = len(matrix), len(matrix[0])
        zero = []
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    zero.append([i,j])
        for z in zero:
            for i in range(r):
                matrix[i][z[1]] = 0
            for j in range(c):
                matrix[z[0]][j] = 0
        
