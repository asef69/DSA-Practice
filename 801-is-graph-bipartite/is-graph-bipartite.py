from collections import deque
from typing import List

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n 
        
        for start in range(n):
            if color[start] == -1: 
                queue = deque([start])
                color[start] = 0
                
                while queue:
                    node = queue.popleft()
                    for nei in graph[node]:
                        if color[nei] == -1:
                            color[nei] = 1 - color[node]
                            queue.append(nei)
                        elif color[nei] == color[node]:
                            return False
        return True