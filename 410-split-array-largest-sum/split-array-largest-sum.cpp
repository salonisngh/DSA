class Solution {
public:

    int countPartition(vector<int>& arr, int Maxsum){
        int partition=1; long long SubarraySum=0;
        for(int num:arr){
            if(SubarraySum+num <= Maxsum){
                SubarraySum +=num;
            }
            else{
                partition++;
                SubarraySum= num;
            }
        }
        return partition;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);
        int sum=0;
        while(low<=high){
            int mid=(low+high)/2;
            int P=countPartition(nums,mid);
            if(P<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};