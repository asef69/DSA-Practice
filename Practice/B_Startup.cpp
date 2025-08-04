#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        unordered_map<int, vector<int>> brand_prices;

        // Read bottles and group by brand
        for (int i = 0; i < k; i++) {
            int brand, price;
            cin >> brand >> price;
            brand_prices[brand].push_back(price);
        }

        vector<int> top_brand_earnings;

        // Calculate maximum earnings for each brand
        for (auto& entry : brand_prices) {
            auto& prices = entry.second;
            sort(prices.rbegin(), prices.rend()); // Sort in descending order

            // Calculate earnings by taking top prices up to the limit of `n`
            int brand_sum = 0;
            for (int i = 0; i < min(n, (int)prices.size()); ++i) {
                brand_sum += prices[i];
            }
            top_brand_earnings.push_back(brand_sum);
        }

        // Sort earnings of brands and pick the top `n`
        sort(top_brand_earnings.rbegin(), top_brand_earnings.rend());

        int max_profit = 0;
        for (int i = 0; i < min(n, (int)top_brand_earnings.size()); ++i) {
            max_profit += top_brand_earnings[i];
        }

        cout << max_profit << '\n';
    }

    return 0;
}
