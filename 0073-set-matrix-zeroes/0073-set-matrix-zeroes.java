class Solution {
    public void setZeroes(int[][] matrix) {
        // returns the length of the rows in the array
  int i = matrix.length;
  // returns the length of the columns in the array
  int j = matrix[0].length;
        int [][] arr=new int[i][j];
        for (int a=0;a<i;a++){
            for (int b=0;b<j;b++){
                arr[a][b]=-1;}}
        for (int a=0;a<i;a++){
            for (int b=0;b<j;b++){
                if (matrix[a][b]==0){
                    for (int x=0;x<j;x++){
                        arr[a][x]=0;}
                    for (int y=0;y<i;y++){
                        arr[y][b]=0;}
                }
                else if (arr[a][b]==0){
                    continue;
                }
                else {
                    arr[a][b]=matrix[a][b];
                }
            }
        }
        for (int a=0;a<i;a++){
            for (int b=0;b<j;b++){
                matrix[a][b]=arr[a][b];}}
        
    }
}