class Solution {
public:
    bool function(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return true;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i] == s[j])
        {
            return dp[i][j] = function(s,i+1,j-1,dp);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int size = s.length();
        string temp = "";
        int maxLength = INT_MIN;
        vector<vector<int>>dp(size,vector<int>(size,-1));
        for(int i = 0;i<size;i++)
        {
            for(int j = i;j<size;j++)
            {
                if(function(s,i,j,dp))
                {
                    if(maxLength < (j-i+1))
                    {
                        maxLength = (j-i+1);
                        temp = s.substr(i,maxLength);
                    }
                }
            }
        }
        return temp;
    }
};