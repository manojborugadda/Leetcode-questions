class Solution { //TC:O(N^2) SC:O(N)
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