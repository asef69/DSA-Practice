class Solution:
    def sortVowels(self, s: str) -> str:
        vowels_set=set("AEIOUaeiou")
        vowels=[i for i in s if i in vowels_set]
        vowels.sort()
        string_list=list(s)
        i=len(vowels)-1
        for index in range(len(string_list)-1,-1,-1):
            if string_list[index] in vowels_set:
                string_list[index]=vowels[i]
                i-=1

        return "".join(string_list)        
        