class Solution {
public:
    // T.C: O(nlogn) -> as we are using priority queue
    // S.C: O(n) -> max-to-max we might store all the station fuels into our priority queue 
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int currStation = startFuel;
        int refuelCnt = 0;
        
        // max-heap to get the maximum fuel whenever our fuel is exhausted
        priority_queue<int> pq; 
        
        for(int i=0;i<stations.size();i++) {
            int nextStation = stations[i][0];
            int fuelQuantity = stations[i][1];
            
            // exhausted our fuel so refuel
            while(currStation < nextStation) {
                if(pq.empty()) return -1; // as we can't refuel 
                
                currStation += pq.top();
                pq.pop();
                refuelCnt++;
            }
            // as we have fuel to reach the next station
            // so we reach there and collect the fuel
            pq.push(fuelQuantity);
        }
        
        // check if we've reached our destination or not
        while(currStation < target) {
            if(pq.empty()) return -1; // as we can't refuel 
                
            currStation += pq.top();
            pq.pop();
            refuelCnt++;
        }
        
        return refuelCnt;
    }
};