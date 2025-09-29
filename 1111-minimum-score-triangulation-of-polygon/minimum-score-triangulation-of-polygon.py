from typing import List

class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        if n < 3:
            return 0
        
        # dp[i][j] = minimum cost to triangulate polygon from vertex i to j
        dp = [[0] * n for _ in range(n)]
        
        # Build up from smaller segments to larger ones
        for length in range(3, n + 1):  # Try all segment lengths
            for i in range(0, n - length + 1):  # Starting vertex
                j = i + length - 1  # Ending vertex
                dp[i][j] = float('inf')
                
                # Try each vertex k between i and j as the third point
                for k in range(i + 1, j):
                    # Cost = left subproblem + right subproblem + current triangle
                    cost = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]
                    dp[i][j] = min(dp[i][j], cost)
        
        return dp[0][n - 1]