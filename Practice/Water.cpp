#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxWaterContainer(vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int maxWater = 0;
    pair<int, int> result;
    
    while (left < right) {
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int currentWater = height;
        
        if (currentWater > maxWater) {
            maxWater = currentWater;
            result = {left, right};
        }
        
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        
        pair<int, int> result = maxWaterContainer(heights);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
