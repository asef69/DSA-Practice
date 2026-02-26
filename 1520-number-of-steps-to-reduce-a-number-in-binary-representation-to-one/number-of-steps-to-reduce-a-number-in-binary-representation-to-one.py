class Solution:
    def numSteps(self, s: str) -> int:
        steps=0
        carry=0

        for i in range(len(s)-1,0,-1):
            bit=ord(s[i])-ord('0')
            current=bit+carry

            if current==1:
                steps+=2
                carry=1
            else:
                steps+=1
                carry=1 if current==2 else 0

        return steps+carry                       
        