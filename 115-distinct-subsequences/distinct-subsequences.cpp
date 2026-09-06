class Solution {
public:

    int solve(int ind1, int ind2, string &s, string &t, vector<vector<long long>> &dp){
        if(ind2 <0) return 1;
        if(ind1 <0) return 0;

        if(dp[ind1][ind2] !=-1) return dp[ind1][ind2];

        //int pick, NotPick;
        if(s[ind1]==t[ind2]){
            int pick = solve(ind1-1, ind2-1, s, t, dp);
            int NotPick = solve(ind1-1,ind2,s,t, dp);
            return dp[ind1][ind2]=pick + NotPick;
        }
        else{
            return dp[ind1][ind2]=solve(ind1-1,ind2,s,t, dp);
        }
        
        
    }
 
    int numDistinct(string s, string t) {
        int ind1= s.length();
        int ind2= t.length();
        vector<vector<long long>>dp(ind1, vector<long long>(ind2,-1));
        return solve(ind1-1, ind2-1, s, t, dp);
    }
};