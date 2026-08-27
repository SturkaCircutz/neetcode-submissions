class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col = defaultdict(set), defaultdict(set)
        square = defaultdict(set)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == ".":
                    continue
                if(board[i][j] in row[i] or
                board[i][j] in col[j] or
                board[i][j] in square[(i//3, j//3)]):
                    return False
                col[j].add(board[i][j])
                row[i].add(board[i][j])
                square[(i//3,j//3)].add(board[i][j])
        return True