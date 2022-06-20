class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string>set(words.begin(),words.end());
        for(auto word:words){
            int m = word.size();
            for(int i = 1;i<m;i++){ //traversing for the substrings from index 1
                string temp = word.substr(i,m);
                if(set.find(temp)!=set.end()){ //if we found substring of word in words SET
                    set.erase(temp); // we ERASE that from the SET
                }
            }
        }
        
        int sum = 0;
        
        for(auto word : set){//calculating size of every word remained in the SET
            sum = sum + word.size() + 1;
        }
        
        return sum;  
    }
};