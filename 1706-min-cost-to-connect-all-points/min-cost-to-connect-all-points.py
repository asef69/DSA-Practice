class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        min_heap=[[0,points[0][0],points[0][1]]]
        visit=set()
        visit.add((points[0][0],points[0][1]))
        cost=0

        while len(visit)!=len(points):
            curr,x,y=heapq.heappop(min_heap)
            if (x,y) not in visit:
                cost+=curr
            visit.add((x,y))
            for x1,y1 in points:
                if (x1,y1) not in visit:
                    dist=abs(x-x1)+abs(y-y1)
                    heapq.heappush(min_heap,[dist,x1,y1])

        return cost                