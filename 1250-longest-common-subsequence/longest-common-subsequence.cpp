class Solution {
public:

    int solve(int ind1, int ind2, string text1, string text2, vector<vector<int>> dp){
        if(ind1 <0 || ind2 < 0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]== text2[ind2]) 
                   return dp[ind1][ind2]= 1+solve(ind1-1, ind2-1, text1, text2, dp);
        
        int lh= 0 + solve(ind1-1, ind2, text1, text2, dp);
        int rh= 0 +solve(ind1, ind2-1, text1, text2, dp);

        return dp[ind1][ind2]= max(lh,rh);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m= text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //return solve(n-1,m-1, text1, text2, dp)

        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(text1[i-1]== text2[j-1]) 
                dp[i][j]= 1+ dp[i-1][j-1];
                else{
                    int lh= dp[i-1][j];
                    int rh= dp[i][j-1];
                    
                    dp[i][j]= max(lh,rh); 
                }

            }
        }
        return dp[n][m];
    }
};