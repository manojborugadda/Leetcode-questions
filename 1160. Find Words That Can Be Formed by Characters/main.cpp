
class Solution {//TC:O(N^2)  SC:O(N)
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char,int>map;
        for(auto ch : chars) {
            map[ch]++;
        }

        for(int i = 0;i<words.size();i++) {
            unordered_map<char,int>tempMap;
            string temp = words[i];
            for(auto ch : temp) {
                tempMap[ch]++;
            }
            bool flag = true;
            for(int k = 0;k<temp.length();k++) {
                if(tempMap[temp[k]] > map[temp[k]]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans += temp.length();
            }
        }
        return ans;
    }
};
