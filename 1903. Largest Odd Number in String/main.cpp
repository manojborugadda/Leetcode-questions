class Solution {//TC:O(N)  SC:O(1)
public:
    string largestOddNumber(string num) {
        int skipFromEnd = 0;
        for(int i = num.length()-1;i>=0;i--) {
            if((num[i]-'0') % 2 == 1) {
                break;
            }
            skipFromEnd++;
        }
        return string(num.begin(),num.end() - skipFromEnd);
    }
};
