class Solution {
public:
    bool containsZero(int num) {
    if (num == 0) return true; // special case
    
    while (num > 0) {
        int digit = num % 10;  // extract last digit
        if (digit == 0) {
            return true;
        }
        num /= 10; // remove last digit
    }
    return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 0;i<n;i++) {
            int a = i;
            int b = n-i;
            if(containsZero(a) or containsZero(b)) {
                continue;
            }else {
                return {a,b};
            }
        }
        return {};
    }
};
