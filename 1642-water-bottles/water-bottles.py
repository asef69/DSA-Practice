class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        total=numBottles
        empties=numBottles

        while empties>=numExchange:
            new_bottle=empties//numExchange
            total+=new_bottle
            empties=new_bottle+(empties%numExchange)

        return total    

        