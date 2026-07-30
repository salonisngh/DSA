class Solution {
public:

    int climb(int ind,  vector<int>&dp ){
        if(ind==0) return 1;
        if(ind==1) return 1;
        if(dp[ind]!=-1) return dp[ind];

        int left= climb(ind-1,dp);
        int right= climb(ind-2,dp);

        return dp[ind]=left+right;

    }
    
    int climbStairs(int ind) {
        vector<int>dp(ind + 1, -1);
        return climb(ind, dp);
    }
};