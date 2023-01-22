class Solution { //TC:O(N)  SC:O(N)
public:
    int alternateDigitSum(int n) {
        string num = to_string(n);
        int sum = 0;
        for(int i = 0;i<num.length();i++) {
            if(i%2 == 0) {
                sum += num[i]-'0';
            }else {
                sum -= num[i]-'0';
            }
        }
        return sum;
    }
};
