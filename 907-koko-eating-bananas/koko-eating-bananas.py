class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        low,high=1,max(piles)
        result=high
        while low<=high:
            k=(low+high)//2

            total_hour=sum(math.ceil(pile/k) for pile in piles)

            if total_hour<=h:
                result=k
                high=k-1
            else:
                low=k+1
        return result            


            

        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna