class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0; int len=0; int maxi=0;
        int zeros=0;
        for(int j=0; j<nums.size();j++){
            if(nums[j]==0){
                zeros++;
                while(zeros>k){
                    if(nums[i]==0) zeros--;
                    i++;
                }
            }
            len=j-i+1;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};