class Solution:
    def maxFreqSum(self, s: str) -> int:
        from collections import Counter
        vowels="aeiou"
        counter = Counter(s)
    
        vowel_counts = {char: count for char, count in counter.items() if char in vowels}
        consonant_counts = {char: count for char, count in counter.items() if char not in vowels}
        max_vowel = max(vowel_counts.items(), key=lambda x: x[1]) if vowel_counts else (None, 0)
        max_consonant = max(consonant_counts.items(), key=lambda x: x[1]) if consonant_counts else (None, 0)
        return max_vowel[1]+max_consonant[1]
        