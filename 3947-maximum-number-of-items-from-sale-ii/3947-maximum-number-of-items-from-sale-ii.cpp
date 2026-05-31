class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int maxFactor=0;
        for(auto& item:items){
            maxFactor=max(maxFactor,item[0]);
        }
        maxFactor++;

        vector<int> factorCount(maxFactor,0);
        for(auto& item:items){
            factorCount[item[0]]++;
        }
        vector<int>divisibleCount(maxFactor,0);
        for(int i=1;i<maxFactor;i++){
            for(int j=i;j<maxFactor;j+=i){
                divisibleCount[i]+=factorCount[j];
            }
        }
        vector<vector<int>> copies=items;
        vector<pair<int,int>> itemData;
        int min_price=INT_MAX;
        for(auto& item:copies){
            int factor=item[0],price=item[1];
            int freeCount=divisibleCount[factor]-1;
            itemData.push_back({price,freeCount});
            min_price=min(min_price,price);
        }
        double ratio=1.0/min_price;

        vector<pair<int, int>> chances;
        for(auto& [price, freeCount] : itemData){
            if(freeCount > 0 && price < 2 * min_price){
                chances.push_back({price, freeCount});
            }
        }
        sort(chances.begin(), chances.end());
        int remaining=budget,total=0;
        for(auto& [price, maxCopies] : chances){
            if(remaining <= 0) break;
            int afford = remaining / price;
            int take = min(afford, maxCopies);
            if(take > 0){
                total += take * 2;
                remaining -= take * price;
            }
        }
        total+=remaining/min_price;
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna