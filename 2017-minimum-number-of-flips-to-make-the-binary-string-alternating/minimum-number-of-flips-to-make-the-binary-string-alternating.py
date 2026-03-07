class Solution:
    def minFlips(self, s: str) -> int:
        n=len(s)
        s=s+s

        pattern1,pattern2="",""
        for i in range(len(s)):
            pattern1+="1" if i%2==0 else "0"
            pattern2+="0" if i%2==0 else "1"

        res=len(s)
        diff1,diff2=0,0
        l=0

        for r in range(len(s)):
            if s[r]!=pattern1[r]:
                diff1+=1

            if s[r]!=pattern2[r]:
                diff2+=1

            if r-l+1>n:
                if s[l]!=pattern1[l]:
                    diff1-=1

                if s[l]!=pattern2[l]:
                    diff2-=1

                l+=1

            if r-l+1==n:
                res=min(res,diff1,diff2)

        return res                

        