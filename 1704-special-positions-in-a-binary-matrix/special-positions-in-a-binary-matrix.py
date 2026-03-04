class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m,n=len(mat),len(mat[0])
        col=[0]*n
        row=[0]*m

        for i in range(m):
            for j in range(n):
                col[j]+=mat[i][j]
                row[i]+=mat[i][j]


        return sum(
            mat[i][j]==1 and row[i]==1 and col[j]==1
            for i in range(m)
            for j in range(n)
        )        


        