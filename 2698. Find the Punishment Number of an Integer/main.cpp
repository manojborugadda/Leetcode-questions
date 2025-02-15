class Solution {
public:
    bool isPossible(string s, int target) {
        if(s ==  "" and target == 0) return true;
        if(target < 0) return false;
        bool ans = false;
        for(int i = 0;i<s.length();i++) {//trying all possible pivotal positions
            string left = s.substr(0,i+1); // keeps the left part of string
            string right = s.substr(i+1); // we recurse the RIGHT part of the PIVOT location
            int leftNum = stoi(left);
            bool isValid = isPossible(right, target-leftNum);
            if(isValid) {
                ans = true;
                break;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1;i<=n;i++) {
            int sqr = i * i;
            if(isPossible(to_string(sqr),i)) {
                sum += sqr;
            }
        }
        return sum;
    }
};
