class Solution {//TC:O(N)  SC:O(N)
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        //The values in the two lists should be returned in increasing order.
        //as they asked in INCREASING ORDER we used MAP otherthan UNORDERED_MAP
        map<int,int> loser,winner;
        
        for(int i=0;i<m.size();i++){
            loser[m[i][1]]++;
            winner[m[i][0]]++;
        }
        
        vector<int> win;
        vector<int> lose;
        for(auto x:winner){
            if(loser.count(x.first) == false){//checking the losers in winning MAP. if present we dont push those into our temporary win vector
                win.push_back(x.first);
            }
        }
        
        for(auto x:loser){
            if(x.second==1){//pushing all those losers who lost Exactly ONCE
                lose.push_back(x.first);
            }
        }
        
        vector<vector<int>> ans; //aswer vector
        ans.push_back(win);
        ans.push_back(lose);
        return ans;
        
    }
};