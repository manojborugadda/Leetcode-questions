class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end()); //DECREASING order
        map<char,int>mp;
        
        for(auto x:s){   // insert all elements in map
            mp[x]++;
        }
        
        set<int>UniqFreq; // we want freq to be UNIQUE and SET have freqencies
        int count = 0;
        
       for(auto [i,j] : mp){
          while( UniqFreq.find(j)!=UniqFreq.end()){//if we see the freq of character before we decrement until it becomes unique
              j--;
              count++; //minimum deletions
          }
           if(j>0){ //if the freq of character is not there in SET before we insert
               UniqFreq.insert(j);
           }
       }
        return count;
    }
};