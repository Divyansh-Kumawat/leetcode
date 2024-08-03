class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // get the number of rows
        vector<vector<int>> arr;
        int rows = matrix.size();

        // Get the number of columns 
        int cols = matrix[0].size();   
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<cols;k++){
                        if(matrix[i][k]==0){
                            continue;             
                        }
                        else{
                            matrix[i][k]=-1000;
                        }
                    }
                    for(int k=0;k<rows;k++){
                        if(matrix[k][j]==0){
                            continue;             
                        }
                        else{
                            matrix[k][j]=-1000;
                        }
                    }
                }
            }
        }     
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(matrix[i][j]==-1000){
                        matrix[i][j]=0;
                    }
                }
           }
        //
        
        
        
        
    }
};