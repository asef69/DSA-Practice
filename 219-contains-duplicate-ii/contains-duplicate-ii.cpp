class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int,int>num_indices;
       for(int i=0;i<nums.size();i++){
        if(num_indices.find(nums[i])!=num_indices.end() && i-num_indices[nums[i]]<=k){
            return true;
        }
        num_indices[nums[i]]=i;
       }
       return false;
    }
}; 




// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna