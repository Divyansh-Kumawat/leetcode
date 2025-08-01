class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int j=1;j<numRows;j++){
            
            vector<int> sub;
            for(int k=0;k<=j;k++){
                if(k==0) sub.push_back(ans[j-1][0]);
                else if(k==j) sub.push_back(ans[j-1][k-1]);
                else sub.push_back(ans[j-1][k-1]+ans[j-1][k]);

            }
            ans.push_back(sub);
        }
        return ans;
    }
};