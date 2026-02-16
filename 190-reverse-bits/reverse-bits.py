class Solution:
    def reverseBits(self, n: int) -> int:
        bit=0
        result=0

        for i in range(31):
            result|=n&1
            n>>=1
            result<<=1

        return result    
        