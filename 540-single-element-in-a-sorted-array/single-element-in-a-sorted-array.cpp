class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ele=0; int cnt=0;
        int i=0; 
        for(int j=0; j<nums.size();j++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(ele==nums[j]){
                cnt--;
                i=j+1;
            }
        }
        return ele;
        

    }
};