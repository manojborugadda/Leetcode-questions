class Solution {//TC:O(N)  SC:O(1)
public:
    string largestGoodInteger(string num) {
        int ans = -1;//for storing the temporary integer value of same Digit number
        string res = "";//answer string
        for(int i = 2;i<num.length();i++) {
            if(num[i] == num[i-2] and num[i] == num[i-1]) {//checking for unique digit i.e Largest 3-Same-Digit Number in String
                string sub = num.substr(i-2 , 3);//taking the substring of length 3
                int subInNum = stoi(sub);///converting the string into INT
                if(subInNum > ans) ans = subInNum , res = sub;
            }
        }
        return res;
    }
};
