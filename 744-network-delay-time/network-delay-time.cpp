class Solution {
public:
    vector<vector<pair<int,int>>> adj_list(int n,vector<vector<int>>&times){
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int>&edge:times){
            int node1=edge[0];
            int node2=edge[1];
            int cost=edge[2];
            adj[node1].push_back({node2,cost});
        }
        return adj;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjacent=adj_list(n,times);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> front=pq.top();
            pq.pop();
            int v=front.second;
            int weight=front.first;
            if(weight>dist[v]) continue;
            for(pair<int,int>u_v:adjacent[v]){
                int node=u_v.first;
                int cost=u_v.second;
                if(weight+cost<dist[node]){
                    dist[node]=weight+cost;
                    pq.push({dist[node],node});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
        }
        int maxTime = 0;
        for(int i=1;i<=n;i++){
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};