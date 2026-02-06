class Solution {
public:
    void dfs(vector<vector<int>>& adj,int & cnt,vector<int>& vis,int node){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(adj,cnt,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,cnt,vis,i);
                cnt++;
            }
           
        }
        
        return cnt;

    }
};