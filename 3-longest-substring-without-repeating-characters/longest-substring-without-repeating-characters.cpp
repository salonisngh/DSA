class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0, j = 0;
        int n = s.length();

        vector<int> hash(256, -1);

        int maxlen = 0;

        while (j < n) {

            if (hash[s[j]] != -1 && hash[s[j]] >= i) {
                i = hash[s[j]] + 1;
            }

            hash[s[j]] = j;

            maxlen = max(maxlen, j - i + 1);

            j++;
        }

        return maxlen;
    }
};