class Solution {
public:
    void merge(vector<int>&nums, int left, int mid , int right, int& pair_count){
        int j=mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && nums[i]>2*(long long)nums[j]){
                j++;
            }
            pair_count+=j-(mid+1);
        }
        int size=right-left+1;
        vector<int>temp (size,0);
        int low=left, high=mid+1,k=0;
        while(low<=mid && high<=right){
            if(nums[low]<nums[high]){
                temp[k++]=nums[low++];
            }
            else{
                 temp[k++]=nums[high++];
            }
        }
        while(low<=mid){
            temp[k++]=nums[low++];
        }
        while(high<=right){
            temp[k++]=nums[high++];
        }
        int m=0;
        for(int i=left;i<=right;i++){
            nums[i]=temp[m++];
        }
    }
    void mergeSort(vector<int>& nums, int left, int right,int& pair_count){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid,pair_count);
        mergeSort(nums,mid+1,right,pair_count);
        merge(nums,left,mid,right,pair_count);
    }
    int reversePairs(vector<int>& nums) {
        int pair_count=0;
        mergeSort(nums,0,nums.size()-1,pair_count);
        return pair_count;
    }
};