class Solution {//TC:O(NLOGN)  SC:O(N)
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings),end(meetings));//times to keep track of the end time of each room's last meeting.
        vector<int>ans(n,0);//to keep track of the number of meetings each rooms has 
        vector<long long>time(n,0);

        for(auto meeting : meetings) {
            int start = meeting[0] , end = meeting[1];
            long long maxi = 1e18; 
            int idx = -1;
            bool flag = false;
            for(int currRoom = 0;currRoom < n;currRoom++) {
                if(maxi > time[currRoom]) {
                    maxi = time[currRoom];
                    idx = currRoom;// room id which has the earliest end time among all rooms
                }
                /*
                If there's a room available (i.e., their last meeting ends before the current meeting starts), we assign them to attend the meeting and update their end time.
                */
                if(time[currRoom] <= start) {
                    flag= true;
                    ans[currRoom]++;
                    time[currRoom] = end;
                    break;
                } 
            }
            //If no room is available, we find the room which has the earliest end time among all rooms and assign them to attend the meeting. We also update their end time accordingly.
            if(!flag) {
                time[idx] += (1ll * (end-start));
                ans[idx]++;
            }
        }

        //traversing the ans vector
        int mx = 0 , res = 0;
        for(int i = 0;i<n;i++) {//processing the vector for finding the room id which has maximum no.of meeting happened
            if(ans[i] > mx) {
                mx = ans[i];
                res = i; //storing room which has most meeting happened
            }
        }
        return res;
    }
};
