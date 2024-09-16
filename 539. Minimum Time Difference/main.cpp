class Solution {//tc:o(nlogn+n) sc:o(n)
public:
    int findMinDifference(vector<string>& timePoints) {
        // we need to change hours to minutes 
        vector<int>v;//minutes vector
        for(int i = 0;i<timePoints.size();i++) {
            string s = timePoints[i];
            int hrs = (10*s[0]-'0'+s[1]-'0')*60;//// 2*10 + 3 = 23*60 //converting the hrs to minutes from input
            int mins = (10*s[3]-'0' + s[4]-'0');//// 5*10 + 9 = 59
            v.push_back(hrs+mins);
        }

        sort(begin(v),end(v));
        int mini = INT_MAX;
        for(int i = 0;i<v.size()-1;i++) {
            mini = min(mini,v[i+1]-v[i]);
        }

        // Also, check the difference between the first and last time, considering the 24-hour wraparound
        int n = v.size();
        mini = min(mini, 1440 - (v[n-1] - v[0]));//24*60 = 1440
        return mini;
    }
};
