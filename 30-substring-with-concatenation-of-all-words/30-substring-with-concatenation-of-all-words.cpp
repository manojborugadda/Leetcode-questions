class Solution { 
public:
    
    bool check(unordered_map<string,int>hash , string current , int n ) {
        // we traverse in the substring in the actual string S for size equal to 'n'
        for(int i = 0;i<current.size(); i += n) {
            string word = current.substr(i,n);
            if(hash[word] == 0){ //if we dont find the word in the HASHMAP we return False
                return false;
            }
                hash[word]--; // decrementing the freq value in the MAP 
        }
         return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n  = words[0].size();
        int size  = words.size() * words[0].size(); // it is the actual window size we check
        vector<int>ans;//answer vector
        unordered_map<string,int>map;
        if(s.size() < size) return {};
        
        for(string  x : words){
            map[x]++;
        }
        
        //we are checking the SUBSTRING length of given input string Words in string S
        for(int i = 0; i <= s.size() - size; i++){
            if(check(map, s.substr(i, size),n)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
