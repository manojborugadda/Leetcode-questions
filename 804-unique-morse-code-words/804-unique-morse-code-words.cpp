class Solution { //TC:O(NMlogN) (where M - length of the word) to O(N*M) ... SC:O(N)
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>code  = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        set<string>st;
        for(int i = 0;i<words.size();i++) {
            string transform;
            for(int j = 0;j<words[i].size();j++){
                //          for example---->    g i n
                //'g' - 'a' gives the 7 and code[7] is "--." and we concatenate like that for rest of the strings in the Vector
                transform += code[ words[i][j] - 'a'];
            }
            st.insert(transform);
        }
        return st.size();
    }
};

//An improvement: we can use hashmap(unordered_map in c++) to reduce complexity from O(NMlogN) (where M - length of the word) to O(N*M) as adding to the hashmap works in O(1)complexity.