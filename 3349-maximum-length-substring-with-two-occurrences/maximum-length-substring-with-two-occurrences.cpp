class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n= s.length();
        int maxi= INT_MIN;

        int j=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;

            while(mp[s[i]] > 2){
                mp[s[j]]--;
                j++;
            }
        maxi= max(i-j+1, maxi);
        }
        return maxi;
    }
};