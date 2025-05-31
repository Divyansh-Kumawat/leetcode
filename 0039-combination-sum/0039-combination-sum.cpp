class Solution {
public:
    void generate(vector<int>& candidates,int  target, vector<int>&ds,vector<vector<int>> &ans,int i ){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target){
            
            ds.push_back(candidates[i]);
            generate(candidates,target-candidates[i],ds,ans,i);
            ds.pop_back();
        }
        
        generate(candidates,target,ds,ans,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(candidates,target,ds,ans,0);
        return ans;
    }
};