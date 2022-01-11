class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        reverse(digits.begin(), digits.end());
        int carry=0;
        for(int i=0;i<digits.size();i++){
            if((digits[i]+1)>9){
                carry=1;
                digits[i]=0;
            }
            else{
                digits[i]++;
                carry=0;
                break;
            }
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
        
    }
};