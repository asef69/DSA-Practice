class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n=len(graph)
        colored=[-1]*n


        def dfs(node,color):
            colored[node]=color
            for neighbour in graph[node]:
                if colored[neighbour]==-1:
                    if not dfs(neighbour,1-color):
                        return False
                elif colored[neighbour]==color:
                    return False
            return True

        for i in range(n):
            if colored[i]==-1:
                if not dfs(i,0):
                    return False

        return True                                
        