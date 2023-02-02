class Solution { //Time complexity: O(n)
                //Space complexity: O(1) //as we are using constant space
public:
    unordered_map<char,int> mp;
    bool compare(string& first,string& second) {
        int m=first.length(),n=second.length();
        for(int i=0;i<min(m,n);i++) {
            
            if(mp[first[i]]<mp[second[i]])
                return true;
            else if(mp[first[i]]>mp[second[i]])
                return false;
        }
        if(n>=m) {
            return true;
        }
        return false;
    }

    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0;i<order.length();i++) 
            mp[order[i]]=i;
        int n=words.size();
        for(int i=0;i<n-1;i++){
            if(!compare(words[i],words[i+1])) {
                return false;
            }
        }
        return true;
    }
};
