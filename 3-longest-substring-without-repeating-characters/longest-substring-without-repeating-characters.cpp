class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,maxLenght=0;
        unordered_set<char> mp;
        for(right=0;right<s.size();right++){
            while(mp.count(s[right])){
                mp.erase(s[left]);
                left++;
            }
            {
                mp.insert(s[right]);
                maxLenght=max(maxLenght,right-left+1);
            }
        }
    return maxLenght;
    }
};