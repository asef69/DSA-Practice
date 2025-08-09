class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        if (nums[mid] <= nums[mid + 1]) {
            return;
        }

        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int l = left; l <= right; l++) {
            nums[l] = temp[l];
        }
    }

    void insertionSort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= left && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if (right - left <= 16) {
            insertionSort(nums, left, right);
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;

        vector<int> temp(n);
        mergeSort(nums, 0, n - 1, temp);
        return nums;
    }
};