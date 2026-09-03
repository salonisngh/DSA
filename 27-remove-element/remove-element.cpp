class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int i=0; int cnt=0;
    for(int j=0; j< nums.size(); j++){
        if(nums[i]==val && nums[j]!=val){
            swap(nums[i],nums[j]);
            i++;
            cnt++;
        }
        else if(nums[i] != val) {
                i++;
            }
        }
    
    return i;
    }
};