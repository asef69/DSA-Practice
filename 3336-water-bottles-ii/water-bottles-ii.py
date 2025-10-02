class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        drunk,empty,full=numBottles,numBottles,0
        while empty>=numExchange or full>0:
            if empty>=numExchange:
                empty-=numExchange
                full+=1
                numExchange+=1
            elif full>0:
                drunk+=full
                empty+=full
                full=0

        return drunk