class Solution:
    def minimumDeletions(self, s: str) -> int:
        res=0
        b_count=0

        for char in s:
            if char=='b':
                b_count+=1

            else:
                res=min(res+1,b_count)    
        return res        