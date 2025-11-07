class Solution {
public:
    // int find(string text1, string text2,int ind1,int ind2,vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(text1[ind1]==text2[ind2]){
    //         return dp[ind1][ind2]=1+find(text1,text2,ind1-1,ind2-1,dp);
    //     }
    //     int first = find(text1,text2,ind1-1,ind2,dp);
    //     int second= find(text1,text2,ind1,ind2-1,dp);
    //     return dp[ind1][ind2]=max(first,second);

    // }
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,-1));
        for(int i=0;i<=s2;i++) dp[0][i]=0;
        for(int i=0;i<=s1;i++) dp[i][0]=0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
};