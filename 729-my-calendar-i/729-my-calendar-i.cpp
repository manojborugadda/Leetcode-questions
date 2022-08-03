class MyCalendar {  //TC:O(N)  SC:O(N)

public:
    vector<pair<int,int>>v1;
    
    MyCalendar() {
        
    }
    
    // 10--------20 -- event previously exists in the vector
    //      15-----------25         incoming event
    //      start        end
    bool book(int start, int end) {
        for(auto x : v1){
            if(start < x.second and x.first < end){
                return false;
            }
        }
        
        v1.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */