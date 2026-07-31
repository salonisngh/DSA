class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0; int rsum=0;
        int n=cardPoints.size();

        for(int i=0; i<k; i++){
            lsum= lsum+cardPoints[i];
        }
        int maxSum= lsum;
        int i=k-1;
        for(int j=n-1; j>=n-k; j--){
            lsum=lsum- cardPoints[i];
            rsum=rsum + cardPoints[j];
            maxSum= max(lsum+rsum, maxSum);
            i--;
        }
        return maxSum;
    }
};