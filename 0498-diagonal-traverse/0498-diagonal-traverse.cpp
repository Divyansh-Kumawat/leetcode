class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n=mat.size();
        int m =mat[0].size();
        int d=0;
        for(int j=0;j<m;j++){
            int r=0;
            int col=j;
            vector<int> temp;
            while(col>=0 && r<n){
                temp.push_back(mat[r][col]);
                r++;
                col--;
            }
            if (d % 2 == 0) reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
            d++;
            
        }    
        for(int i=1;i<n;i++){
            int r=i;
            int col=m-1;
            vector<int> temp;
            while(col>=0 && r<n){
                temp.push_back(mat[r][col]);
                r++;
                col--;
            }
            if (d % 2 == 0) reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
            d++;
        }    
          
        return ans;

    }
};