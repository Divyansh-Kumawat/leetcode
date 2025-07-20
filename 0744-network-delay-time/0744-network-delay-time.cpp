class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        pq.push({0,k});
        while(!pq.empty()){
            int currdist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(currdist>dist[node]) continue;
            for(auto it: adj[node]){
                int weight=it.second;
                int neighbour=it.first;
                if (currdist + weight < dist[neighbour]) {
                    dist[neighbour] = currdist + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }

        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;



    }
};