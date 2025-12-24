class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        totalApples = sum(apple)
        capacity.sort(reverse=True)  
        
        count = 0
        for c in capacity:
            if totalApples <= 0:
                break
            totalApples -= c
            count += 1
        
        return count