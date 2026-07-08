class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0; int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if (ele==nums[i]) cnt1++;
            if(cnt1>(nums.size()/2)){
            return ele;
        }
        }
        
        return -1;
    }
};