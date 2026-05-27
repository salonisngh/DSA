class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n= nums.size();
        k = k%n;
        vector<int> temp(k);
        for (int i =0; i < k ; i++){
            temp[i]= nums[n-k+i];
        }

        for (int j= n-k-1; j>=0 ; j--){
            nums[j+k]= nums[j];
        }

        for(int t=0 ; t<k ; t++){
            nums[t]=temp[t];
        }
    }
};