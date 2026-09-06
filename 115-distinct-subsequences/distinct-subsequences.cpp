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
        int n= s.length();
        int m= t.length();
        vector<vector<unsigned long long>>dp(n + 1, vector<unsigned long long>(m + 1,0));
        //return solve(n-1, m-1, s, t, dp);
        int ans=0;
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1]+ dp[i-1][j];
                    //if (dp[i][j] > INT_MAX){
                      //  dp[i][j]= INT_MAX;
                    //}
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};