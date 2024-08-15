class Solution {//TC:O(N)  SC:O(1)
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 , ten = 0;
        for(int x : bills) {
            if(x == 5) {
                five++;
            }else if(x == 10) {
                if(five == 0) {//we dont have five coins to give change for 10 coins
                    return false;
                }
                five--;
                ten++;
            }else {//if the number is 15 or 20
                if(five > 0 and ten > 0) {
                    five--;
                    ten--;
                }else if(five >= 3) {//if we have five rupee coins morethan 3 we can give change to 20 rupees
                    five -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};
