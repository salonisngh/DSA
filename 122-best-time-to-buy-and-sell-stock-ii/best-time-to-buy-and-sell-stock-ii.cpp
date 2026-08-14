class Solution {
public:

    int f(int ind, int buy, vector<int>& prices, int n,vector<vector<int>>& dp){

        if(ind==n) return 0;

        if(dp[ind][buy] !=-1) return dp[ind][buy];
        int profit= INT_MIN;

        if(buy){
            profit= max(-prices[ind]+f(ind+1, 0 , prices, n, dp),
                            0 + f(ind+1, 1 , prices, n, dp)); 
        }
        else{
            profit= max( prices[ind] + f(ind+1, 1, prices, n, dp),
                             0 + f(ind+1, 0, prices, n, dp) );
        }
        return dp[ind][buy]= profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        //return f(0, 1, prices , n, dp);
        int buy=1;
        for(int i=0; i<2; i++){
            dp[n][i]=0;
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                int profit=0;
                if(j==1){
                    profit =max(-prices[i]+ dp[i+1][0],
                                 0 + dp[i+1][1] );
                }
                else{
                    profit =max(prices[i] + dp[i+1][1],
                                 0 + dp[i+1][0] );
                }
            dp[i][j]= profit;
            }
        }
        return dp[0][1];
    }
};