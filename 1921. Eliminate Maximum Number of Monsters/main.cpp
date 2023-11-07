class Solution {//TC:O(nlogn)  sc:o(n)
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<int>time(n,0);
        for(int i = 0;i<n;i++) {
            time[i] = (dist[i]+speed[i]-1)/speed[i];
        }
        sort(begin(time),end(time));
        int result = 0 , curr_time  = 0;
        for(int t : time) {
            if(curr_time >= t) {
                return result;
            }
            result++;
            curr_time++;
        }
        return result;
    }
};
//to calculate value of ceil one of the operand must be of type double..so to avoid type conversion we can use the trick ceil(x/y) = (x+y-1)/y
