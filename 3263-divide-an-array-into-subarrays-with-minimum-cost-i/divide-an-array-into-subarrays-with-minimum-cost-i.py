class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        min_cost=float('inf')
        n=len(nums)
        for first_split in range(1,n-1):
            for second_split in range(first_split+1 , n):
                cost1=nums[0]
                cost2=nums[first_split]
                cost3=nums[second_split]
                total_cost=cost1+cost2+cost3
                if total_cost<min_cost:
                    min_cost=total_cost

        return min_cost            
        