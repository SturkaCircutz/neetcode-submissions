class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        ROW, COL = len(matrix), len(matrix[0])
        self.summat = [[0] * (COL+1) for i in range(ROW+1)]
        for i in range(ROW):
            prefix = 0
            for j in range(COL):
                prefix += matrix[i][j]
                self.summat[i+1][j+1] = prefix + self.summat[i][j+1]
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1, col1, row2, col2 = row1+1, col1+1, row2+1, col2+1
        upperright = self.summat[row1-1][col1-1]
        curr = self.summat[row2][col2]
        left = self.summat[row2][col1-1]
        upper = self.summat[row1-1][col2]
        return curr - left - upper + upperright


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)