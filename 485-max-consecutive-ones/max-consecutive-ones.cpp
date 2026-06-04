class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0; int r=0;
        int cnt=0; int maxcnt=0;
        while(r<nums.size()){
            if(nums[r]==1){
                cnt++;
                r++;
                maxcnt=max(cnt, maxcnt);
            }
            else{
                l=r+1;
                r++;
                cnt=0;
            }

        }
    return maxcnt;
    }
};