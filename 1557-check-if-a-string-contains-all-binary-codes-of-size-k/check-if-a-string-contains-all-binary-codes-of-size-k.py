class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        available=set()
        for i in range(len(s)-k+1):
            available.add(s[i:i+k])

        return len(available)==2**k    
        