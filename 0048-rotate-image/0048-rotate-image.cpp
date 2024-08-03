class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();   
            vector<vector<int>> arr(rows, vector<int>(cols));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
matrix[i][j] = arr[rows-1-j][i];            }
        }
    }
};