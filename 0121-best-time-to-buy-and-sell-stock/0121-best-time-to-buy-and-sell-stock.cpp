class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int buy=0;
        
        for(int i=1;i<n;i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            profit=max(profit,prices[i]-prices[buy]);

        }
        return profit;
    }
};