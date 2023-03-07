class Solution { //TC:O(NLOGN)  SC:O(1)
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long left = 0 ;
        long right = time[0] * (long long )totalTrips;
        while(left < right) {
            long mid = (right+left)>>1;
            //how many trips can we do
            long long  total = totalTripsGivenTime(time,mid);
            if(total < totalTrips) {//We cannot reach totalTrips, means mid is too small
                left = mid+1;
            }else {
                right = mid;
            }
        }
        return left;
    }

    long totalTripsGivenTime(vector<int>& time,long givenTime) {
        long totalTime = 0;
        for(auto t: time) {
            totalTime = totalTime + (givenTime/t);
        }
        return totalTime;
    }
    
};
