class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edges = []
        
        # Generate all possible edges
        for i in range(n):
            xi, yi = points[i]
            for j in range(i + 1, n):
                xj, yj = points[j]
                edges.append((abs(xi - xj) + abs(yi - yj), i, j))
        
        # Sort by distance
        edges.sort()
        
        parent = list(range(n))
        rank = [0] * n
        total_cost = 0
        edges_used = 0
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            nonlocal edges_used
            root_x = find(x)
            root_y = find(y)
            
            if root_x == root_y:
                return False
            
            if rank[root_x] > rank[root_y]:
                parent[root_y] = root_x
            elif rank[root_x] < rank[root_y]:
                parent[root_x] = root_y
            else:
                parent[root_y] = root_x
                rank[root_x] += 1
            
            edges_used += 1
            return True
        
        for cost, u, v in edges:
            if edges_used == n - 1:
                break
            if union(u, v):
                total_cost += cost
        
        return total_cost