class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n= nums.size();
        int sum=nums[0];
        int maxsum= INT_MIN;
        int j=0;
        for(int i=1; i<n; i++){
            if(nums[i]== nums[i-1]+1){
                sum+=nums[i];
            }
            else {
                break;
            }
        }
        
        unordered_set<int> st(nums.begin(), nums.end());

        while(st.count(sum)){
            sum+=1;
        }
        

        return sum;
    }
};