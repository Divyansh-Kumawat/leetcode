class Solution {
public:
    int maxprofit(int ind,int buy,int n,vector<int>& prices,int cnt,vector<vector<vector<int>>> & dp){
        if(cnt==0) return 0;
        if(ind==n) return 0;
        if (dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];
        int profit=0;
        if(!buy){
            profit= max(-prices[ind]+maxprofit(ind+1,1,n,prices,cnt,dp),
            maxprofit(ind+1,0,n,prices,cnt,dp));
        }
        else{
            profit= max(prices[ind]+maxprofit(ind+1,0,n,prices,cnt-1,dp),
            maxprofit(ind+1,1,n,prices,cnt,dp));
        }
        return dp[ind][buy][cnt] =profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return maxprofit(0,0,n,prices,2,dp);
    }
};