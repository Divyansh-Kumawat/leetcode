class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i:arr){
            minHeap.push(i);
        }
        unordered_map<int,int> rankmap;
        int rank=1;
        while(!minHeap.empty()){
            int current=minHeap.top();
            minHeap.pop();
            if((rankmap.find(current)==rankmap.end())){
                rankmap[current]=rank;
            rank++;
            }
            
        }
        vector<int>ans;
        for(int num:arr){
            ans.push_back(rankmap[num]);
        }
        return ans;
    }
};