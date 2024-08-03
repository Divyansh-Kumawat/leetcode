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
matrix[j][rows - 1 - i] = arr[i][j];            }
        }
    }
};