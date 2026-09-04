class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]

        for i in range(numRows-1):
            curr = [0] + res[-1] + [0]
            row = []
            for j in range(len(curr)-1):
                row.append(curr[j]+curr[j+1])
            res.append(row)
        return res