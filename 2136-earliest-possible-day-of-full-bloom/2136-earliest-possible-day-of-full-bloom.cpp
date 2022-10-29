class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>>v;
        
        for(int i = 0;i<plantTime.size();i++){
            v.push_back({growTime[i],plantTime[i]});   
        }
        
        //sorting the vector in DECREASING order
        sort(begin(v),end(v),greater<>());
        
        int time = 0 , maxi = 0;
        for(int i = 0;i<plantTime.size();i++) {
            time += v[i].second;
            maxi = max(maxi,time+v[i].first);
        }
        return maxi;
    }
};