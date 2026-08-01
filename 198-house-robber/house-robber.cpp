class Solution {
public:

    int solve(int ind, vector<int>& nums, vector<int>& dp){
        dp[0]=nums[0];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];
        for(int i= 1; i<nums.size(); i++){
            int pick= nums[i];
            if(i>1) pick+= dp[i-2];
            int notPick= 0+ dp[i-1];
            dp[i]=max(pick, notPick);
        }
        
        return dp[nums.size()-1];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1, nums, dp);
    }
};