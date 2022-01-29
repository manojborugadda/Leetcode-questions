class Solution {
public:
    string truncateSentence(string s, int k) {
         stringstream s1(s); // Used for breaking words
         string word; // to store individual words
  
            vector<string>ans;
    while (s1 >> word){
        ans.push_back(word);
    }
        string res;
    for(int i=0;i<k;i++){
         res = res+ans[i]+" ";
    }
        
        return res.substr(0, res.length()-1);
}
    
};