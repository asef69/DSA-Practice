class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        for(const auto& pair:ump){
            if(pair.second>=2){
                return true;
            }
        }
        return false;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna