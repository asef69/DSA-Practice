class Solution:
    def minOperations(self, s: str) -> int:
        count0=0
        count1=0

        for i,c in enumerate(s):
            if i%2==0:
                if c!='0':
                    count0+=1
                if c!='1':
                    count1+=1

            else:
                if c!='0':
                    count1+=1
                if c!='1':
                    count0+=1
        return min(count0,count1)            

        