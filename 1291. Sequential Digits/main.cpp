class Solution {//TC:O(8*8) SC:O(1)
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string str = "123456789";
        for(int i = 2;i<=9;i++) {
            for(int startIdx = 0;startIdx <= 9 - i;startIdx++) {
                string temp = str.substr(startIdx,i);
                int num = stoi(temp);//if the constraint's high is 10^18 we would have used "stoll" instead of "stoi"
                if(num > high) break;
                if(num >= low and num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};
