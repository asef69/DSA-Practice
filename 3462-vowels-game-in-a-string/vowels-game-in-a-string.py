class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels_set=set("aeiou")
        vowels=[i for i in s if i in vowels_set]
        if len(vowels)==0:
            return False
        if len(vowels)//2 !=0:
            return True

        return True    

        