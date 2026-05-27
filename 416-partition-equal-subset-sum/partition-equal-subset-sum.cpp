class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }
        if(totalSum%2!=0) return false;

        int targetSum=totalSum/2;

        bitset<10001>dp;

        dp[0]=1;

        for(int num:nums){
            dp|=(dp<<num);
        }

        return dp[targetSum];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna