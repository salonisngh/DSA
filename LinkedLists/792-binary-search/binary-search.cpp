class Solution {
public:
    int BinarySearch(vector<int>& arr,int low,int high,int target) {
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(arr[mid]== target) return mid;
        if(arr[mid]>target){
           return BinarySearch(arr,low,mid-1,target);
        }
        else{ 
           return BinarySearch(arr,mid+1,high,target);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
       return BinarySearch(nums,0,nums.size()-1,target);
    }
};