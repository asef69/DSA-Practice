class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD=10**9+7
        result=""

        for i in range(1,n+1):
            result+=bin(i)[2:]

        return (int)(result,2)%MOD    
        