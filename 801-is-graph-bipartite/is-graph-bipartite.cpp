class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>V(n,-1);
        queue<int>Q;
        for(int i=0;i<n;i++){
            int start=i;
            if(V[start]!=-1) continue;
            V[start]=1;
            Q.push(start);
            while(!Q.empty()){
                int parent=Q.front();
                int next_color=!V[parent];
                Q.pop();
                for(auto child:graph[parent]){
                    if(V[child]==-1){
                        V[child]=next_color;
                        Q.push(child);
                    }
                    else{
                        if(V[child]!=next_color) return false;
                    }
                }
            }
        }
        return true;
    }
};