class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        memo = {}
        
        def dp(i, j):
            if j - i < 2:
                return 0
            
            if (i, j) in memo:
                return memo[(i, j)]
            
            result = float('inf')
            for k in range(i + 1, j):
                cost = values[i] * values[k] * values[j] + dp(i, k) + dp(k, j)
                result = min(result, cost)
            
            memo[(i, j)] = result
            return result
        
        return dp(0, n - 1)