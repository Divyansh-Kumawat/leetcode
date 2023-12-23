class Solution {
    public void rotate(int[][] matrix) {
        int i = matrix.length;
        int j = matrix[0].length;
        int [][] arr=new int[i][j];
        for (int a=0;a<i;a++){
            for (int b=0;b<j;b++){
                arr[j-1-b][a]=matrix[a][b];
            }
        }
        for (int a=0;a<i;a++){
            for (int b=0;b<j;b++){
                matrix[i-1-a][j-1-b]=arr[a][b];}}
        
    }
}