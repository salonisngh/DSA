class Solution {
public:

    string solve(int ind1,int ind2,string str1, string str2, vector<vector<string>>& dp){
        if(ind1 < 0) return str2.substr(0,ind2+1);
        if(ind2 < 0) return str1.substr(0, ind1 + 1);

        if(dp[ind1][ind2]!=" ") return dp[ind1][ind2];

        if(str1[ind1]==str2[ind2]) {
            return dp[ind1][ind2] = str1[ind1] + solve(ind1-1, ind2-1, str1, str2,dp);
        }
        string left= str1[ind1] + solve(ind1-1, ind2, str1,str2,dp);
        string right= str2[ind2] + solve(ind1, ind2-1, str1, str2,dp);

        if(left.length() > right.length()){
             return dp[ind1][ind2]= right;
        }
        return dp[ind1][ind2]= left;
        
        
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.length();
        int m= str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //return solve(n-1, m-1, str1, str2, dp);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Construct SCS
        string ans = "";

        int i = n;
        int j = m;

        while(i > 0 && j > 0){

            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }

            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }

            else{
                ans += str2[j-1];
                j--;
            }
        }

        // Remaining characters
        while(i > 0){
            ans += str1[i-1];
            i--;
        }

        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
    
};