class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<int> maxValues(n);
        maxValues[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            maxValues[i]=max(maxValues[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int currValue=events[i][2];
            int nextStart=events[i][1]+1;

            int left=i+1,right=n-1,index=-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(events[mid][0]>=nextStart){
                    index=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            if(index!=-1){
                currValue+=maxValues[index];
            }
            ans=max(ans,currValue);
            ans = max(ans, events[i][2]); 
        }
        return ans;
    }
};