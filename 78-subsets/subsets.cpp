class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); i++){
            vector<int>Subset;

            for(int j=0;j<nums.size(); j++){
                if(i & (1<<j)){
                  Subset.push_back(nums[j]);
                }  
            }
        ans.push_back(Subset);
        }
        return ans;
    }
};