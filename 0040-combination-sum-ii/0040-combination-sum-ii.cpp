class Solution {
public:
    void generate(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &ds,int i){
        
        if(target==0){
            ans.push_back(ds); 
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])  continue;
            if(candidates[j]>target)break;
                ds.push_back(candidates[j]);
                generate(candidates,target-candidates[j],ans,ds,j+1);
                ds.pop_back();
            
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        generate(candidates,target,ans,ds,0);
        return ans;
    }
};