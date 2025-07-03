class Solution {
public:
void dfs(vector<int> &vis,vector<vector<int>>& adj,int i){
    vis[i]=1;
    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(vis,adj,it);
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }  
            }
              
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){     
                count++;         
                dfs(vis,adj,i);
                
            }
        }
        return count;
    }
};