class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        from collections import defaultdict
        
        rows = defaultdict(set)
        cols = defaultdict(set)
        squares = defaultdict(set)
        ROWS, COLS = len(board), len(board[0])

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] != '.':
                    val = int(board[r][c])
                    rows[r].add(val)
                    cols[c].add(val)
                    squares[(r//3, c//3)].add(val)

        def fillboard(r, c):
            if r == ROWS:
                return True
            if c == COLS:
                return fillboard(r + 1, 0)
            
            if board[r][c] == '.':
                for n in range(1, 10):
                    if (n not in rows[r] and 
                        n not in cols[c] and 
                        n not in squares[(r//3, c//3)]):
                        
                        board[r][c] = str(n)
                        rows[r].add(n)
                        cols[c].add(n)
                        squares[(r//3, c//3)].add(n)
                        
                        if fillboard(r, c + 1):
                            return True
                        
                        board[r][c] = '.'
                        rows[r].remove(n)
                        cols[c].remove(n)
                        squares[(r//3, c//3)].remove(n)
                
                return False
            else:
                return fillboard(r, c + 1)

        fillboard(0, 0)