class Solution {
public:
    bool dfs(int m, int n, vector<vector<char>>& board, string word,vector<vector<int>>&visited,int curr){
        if(curr==word.size()) return true;
        int row=board.size();
        int col=board[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int x=m+dx[i];
            int y=n+dy[i];
            if(x>=0 && y>=0 && x<row && y<col && !visited[x][y]){
                if(board[x][y]==word[curr]){
                    visited[x][y]=1;
                    if(dfs(x,y,board,word,visited,curr+1)) return true;
                    visited[x][y]=0;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int curr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[curr]==board[i][j] && !visited[i][j]){
                    visited[i][j]=1;
                    if(dfs(i,j,board,word,visited,curr+1)) return true;
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};
