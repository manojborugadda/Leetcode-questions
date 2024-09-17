class Solution {//TC:O(n)  auxiliary space :O(N)
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       unordered_map<string,int>map;

       stringstream ss(s1);
       string word;
       while(ss >> word) {
        map[word]++;
       }

       stringstream s(s2);
       string w;
       while(s >> w) {
        map[w]++;
       }

        vector<string>ans;
       for(auto &[a,b] : map) {
        if(b == 1) {
            ans.push_back(a);
        }
       }
       return ans;
    }
};
//A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)

//operator >>       Read something from the stringstream object.
