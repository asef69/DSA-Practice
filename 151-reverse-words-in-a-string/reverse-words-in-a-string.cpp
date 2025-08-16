class Solution {
public:
    string reverseWords(string s) {
        vector<string> check;
        string temp="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' ') temp+=s[i];
            if((s[i]==' ' || i==n-1)&& temp!=""){
                check.push_back(temp);
                temp="";
            }
        }
        string ans="";
        for(int i=check.size()-1;i>=0;i--){
            ans+=check[i];
            if(i!=0) ans+=" ";
        }
        return ans;
    }
};