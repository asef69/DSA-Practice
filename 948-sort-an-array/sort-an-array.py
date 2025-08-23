class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        heapq.heapify(nums)
        st=[]
        while nums:
            x=heapq.heappop(nums)
            st.append(x)
        return st    