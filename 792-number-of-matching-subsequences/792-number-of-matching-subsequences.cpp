class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        map<char,vector<int>>map;
        int i = 0;
        
        for(auto x :s){//key as character and Value as the indexes of those characters in VECTOR
            map[x].push_back(i++);
        }
        
        int count = 0;
        for(int i = 0;i<words.size();i++){
            string curr = words[i];
            int latest = -1;
            for(int j = 0;j<curr.size();j++){
                //upper bound gives the next element which is greater than or equal to 
                auto it = upper_bound(map[curr[j]].begin(),map[curr[j]].end(),latest);
                if(it == map[curr[j]].end()){//if latest value is last index of the vector in MAP
                    break;
                }
                latest = *it; //updating the latest value
                if(j==curr.size()-1){//if we comes to last index we have that subsequence in given string as matching
                    count++;
                }
            }
        }
        return count;
    }
};