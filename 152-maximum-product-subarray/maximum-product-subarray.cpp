class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi= 1;
        int mini= 1;
        int res = nums[0];

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                maxi=1;
                mini=1;
                res = max(res, 0);
                continue;
            }
            int temp = maxi;

            maxi= max({maxi* nums[i], mini* nums[i], nums[i]});
            mini= min ({temp* nums[i], mini* nums[i], nums[i]});

            res = max(maxi, res);
        }
        return res;
    }
};