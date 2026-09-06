class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int left=0;
        int right = citations.size()-1;
        int n= citations.size();;
        int ans=0;
        while(left<= right){
            int mid = left + (right - left) / 2;
            int paper= n-mid;
            if (paper <= citations[mid]){
                ans= paper;
                right= mid-1;
            }
            else left= mid+1;
        }
        return ans;
    }
};