class Solution {//TC:O(nlogn) SC:O(1)
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //as minimum speed of eating must be 1
        int start = 1 ;
        // Maximum speed of eating
        // is the maximum bananas in given piles
        int end = *max_element(piles.begin(), piles.end());
        while(start<end){
            int mid = start + (end-start)/2;
            if(check(piles, h, mid)){
                end = mid;//// If valid continue to search
                            // lower speed
            }
            else
                start = mid+1;// If cant finish bananas in given
            // hours, then increase the speed
        }
        return start;
    }

    bool check(vector<int>& bananas, int H, int mid_val) {
    int time = 0;
    for (int i = 0; i < bananas.size(); i++) {
 
        // to get the ceil value
        if (bananas[i] % mid_val != 0) {
 
            // in case of odd number
            time += ((bananas[i] / mid_val) + 1);
        }
        else {
 
            // in case of even number
            time += (bananas[i] / mid_val);
        }
    }
 
    // check if time is less than
    // or equals to given hour
    if (time <= H) {
        return true;
    } else {
        return false;
    }
}

};
