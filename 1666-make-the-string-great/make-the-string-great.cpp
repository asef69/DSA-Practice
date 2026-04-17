class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty()&&tolower(st.top()) == tolower(s[i]) && 
((islower(st.top())&&isupper(s[i])) || (isupper(st.top())&&islower(s[i])))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};