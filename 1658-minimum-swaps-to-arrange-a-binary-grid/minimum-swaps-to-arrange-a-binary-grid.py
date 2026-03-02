class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n=len(grid)
        values=[]

        for row in grid:
            val=0
            for j in range(n-1,0,-1):
                if row[j]==1:
                    val=j
                    break
            values.append(val)

        steps=0
        for v in range(n):
            i=v+1
            while v<values[v]:
                if i==n:
                    return -1
                values[i],values[v]=values[v],values[i]
                i+=1
                steps+=1

        return steps                        
        