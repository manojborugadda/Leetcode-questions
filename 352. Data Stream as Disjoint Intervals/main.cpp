class SummaryRanges {
public:
    set<int>set;
    SummaryRanges() {
        
    }
    
    //TC:O(logn)
    void addNum(int value) {
        set.insert(value);
    }
    
    //TC:O(N)
    vector<vector<int>> getIntervals() {
        if(set.size() == 0) return {};
        int right  = -1,left = -1;
        vector<vector<int>>ans;
        for(auto x : set) {
            if( left < 0) {
                right = left = x;
            }else if(x == right + 1) {
                right = x ;
            }else {
                ans.push_back({left,right});
                right = left = x;
            }
        }
        ans.push_back({left,right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
