class Solution {
public:

    int lcs(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
        if(ind1< 0 || ind2 <0) {
                    return 0;
        }

        if( dp[ind1][ind2]!= -1) return dp[ind1][ind2];
        if( s1[ind1] == s2[ind2]) return dp[ind1][ind2]= 1 + lcs(ind1-1, ind2-1, s1, s2, dp);

        int left = lcs(ind1-1, ind2, s1, s2, dp);
        int right =  lcs(ind1, ind2-1, s1, s2, dp);

        return dp[ind1][ind2]= max(left, right);
    }

    int minInsertions(string s) {
        string rs=s; int n= s.length();
        reverse(rs.begin(),rs.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int l= lcs(n-1,n-1,s,rs,dp);
        return n-l;
    }
};