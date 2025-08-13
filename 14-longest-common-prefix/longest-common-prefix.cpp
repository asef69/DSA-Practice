class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()>=ans.size()){
                for(int j=0;j<ans.size();j++){
                    if(strs[i][j]==ans[j]) continue;
                    else{
                        ans.erase(j);
                        break;
                    }
                }
            }
            else{
                ans.erase(strs[i].size());
                for(int j=0;j<ans.size();j++){
                    if(strs[i][j]==ans[j]) continue;
                    else{
                        ans.erase(j);
                        break;
                    }
                }
            }

        }
        return ans;
    }
};