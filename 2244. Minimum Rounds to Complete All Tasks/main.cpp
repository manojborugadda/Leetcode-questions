class Solution {  //TC:O(N)  SC:O(N)
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int>mp;
        
        for(int i = 0;i<tasks.size();i++){
                mp[tasks[i]]++;   
        }
        
        int count = 0;
        
        for(auto x: mp){
            if(x.second==1){
                return -1;
            }
            else
            {
                if(x.second %3 == 0){
                    count = count+ x.second/3;
                }
                else{
                    count = count+ x.second/3 + 1;
                }
            }
        }
        return count;
    }
};
