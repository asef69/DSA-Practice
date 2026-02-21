class Solution:
    def is_prime(self,num):
        if num<2:
            return False
        if num==2:
            return True

        if num%2==0:
            return False    
        for i in range(3, int(num**0.5) + 1, 2):
            if num%i==0:
                return  False
        return True                

    def countPrimeSetBits(self, left: int, right: int) -> int:
        count=0
        for i in range(left,right+1):
            if(self.is_prime(bin(i).count('1'))):
                count+=1
        return count
        
        