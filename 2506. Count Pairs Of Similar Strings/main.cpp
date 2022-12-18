class Solution {// TC:O(max.len of the string * logN)    SC:O(N)
public:
    int similarPairs(vector<string>& words) {
        map<set<char>,int>map;
        int ans = 0; //answer variable
        for(auto x: words) { //taking the string in the SET which will have the UNIQUE characters in it
            set<char>st;
            for(char ch : x) { 
                st.insert(ch);
            }
            map[st]++;
        }
        for(auto x: map) { //searching for the string which will have the 
            if(x.second > 1) {
                int n = x.second;
                ans += n*(n-1)/2; //calculating the number of pairs
            }
        }
        return ans;
    }
};

// TC:O(max.len of the string * logN)    SC:O(N)
