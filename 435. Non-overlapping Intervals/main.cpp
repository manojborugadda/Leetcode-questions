class Solution { //TC:O(NLOGN) SC:O(1)
public:
    static bool comp(vector<int>&a,vector<int>&b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int endTime = INT_MIN;
        sort(begin(intervals),end(intervals),comp);
        for(int i = 0;i<intervals.size();i++) {
            if(intervals[i][0] < endTime) {
                ans++;
            }else {
                endTime = intervals[i][1];
            }
        }
        return ans;    
    }
};
