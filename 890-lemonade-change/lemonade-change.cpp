class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;

        for(int i=0; i<bills.size();i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                ten++;
                if(five>0) five--;
                else return false;
            }
            else{
                if(ten >=1& five>=1) {
                    twenty++;
                    ten--; five--;
                }
                else if(five>=3){
                    five= five-3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};