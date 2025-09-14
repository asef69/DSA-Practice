class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:

        perfect_match = {}
        for i in range(0, len(wordlist)):
            word = wordlist[i]
            perfect_match[word] = i

        result = []

        cap_match = {}

        for i in range(0, len(wordlist)):
            word = wordlist[i].lower()
            if word in cap_match:
                cap_match[word].append(i)
            else:
                cap_match[word]=[i]


        def devowel(word):
            res = ''
            for ch in word:
                if ch not in ('a', 'e', 'i', 'o', 'u','A','E','I','O','U'):
                    res += ch
                else:
                    res+='*'
            
            return res
        
        devowel_map = {}

        for i in range(0, len(wordlist)):
            word = wordlist[i]
            dv_word = devowel(word).lower()
            if dv_word in devowel_map:
                devowel_map[dv_word].append(i)
            else:
                devowel_map[dv_word] = [i]
        
        result = []
        for word in queries:
            if word in perfect_match:
                result.append(word)

            elif word.lower() in cap_match:
                result.append(wordlist[cap_match[word.lower()][0]])

            elif devowel(word.lower()) in devowel_map:
                t_w = devowel(word.lower())
                index = devowel_map[t_w][0]
                result.append(wordlist[index])
            else:
                result.append("")
        
        return result