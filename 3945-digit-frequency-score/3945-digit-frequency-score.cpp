class Solution {
public:
    int digitFrequencyScore(int n) {
        int copy=abs(n);
        vector<int>freq(10,0);
        while(copy!=0){
            freq[copy%10]++;
            copy=copy/10;
        }
        int sum=0;
        for(int i=0;i<10;i++){
            sum+=freq[i]*i;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna