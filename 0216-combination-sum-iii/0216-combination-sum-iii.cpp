class Solution {
public:
    void generate(vector<vector<int>> &ans,vector<int>&ds,int k,int n,int ind,int sum){
        if(sum>n) return;
        if(k==0){
            if(sum==n){
                ans.push_back(ds);
            }
            return;
        }
        if(ind>=10) return;
        sum+=ind;
        ds.push_back(ind);
        generate(ans,ds,k-1,n,ind+1,sum);
        sum-=ind;
        ds.pop_back();
        generate(ans,ds,k,n,ind+1,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(ans,ds,k,n,1,0);
        return ans;
    }
};