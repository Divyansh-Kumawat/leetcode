class Solution {
public:
    void combination(vector<int> & candidates,int target,vector<vector<int>>& ans,vector<int>& temp,int i){
        
        int sum=accumulate(temp.begin(),temp.end(),0);
        if(i==candidates.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        
        if(sum<=target){
            temp.push_back(candidates[i]);
            combination(candidates,target,ans,temp,i);
            temp.pop_back();
        }
        combination(candidates,target,ans,temp,i+1);        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(candidates,target,ans,temp,0);
        return ans;
    }
};