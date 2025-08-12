class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> ans;
        deque<int> dq;

        while (j < n) {
            while (!dq.empty() && nums[j] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if (j - i + 1 == k) {
                ans.push_back(nums[dq.front()]);

                if (dq.front() == i) {
                    dq.pop_front();
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};
