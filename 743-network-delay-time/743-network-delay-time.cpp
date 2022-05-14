class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int>timeForSignal(n+1,INT_MAX); //array or vector which stores the time for signal to travel
        
        for(int i = 0;i<times.size();i++)
        {
            int j = times[i][0];  // it is the SOURCE node
            // times[i][1]----> is TARGET node times[i][2]----> Time takes for a signal
            graph[j].push_back({times[i][1],times[i][2]});
        }
        
        queue<int>q;
        q.push(k);
        timeForSignal[k] = 0;
        while(q.empty()==false)
        {
            int curr = q.front();
            q.pop();
            
            for( pair<int,int>p : graph[curr] ){
                int destination = p.first;
                int time = p.second;
                
                int arrivalTime = timeForSignal[curr]+time;
                
                if(arrivalTime < timeForSignal[destination]){
                    timeForSignal[destination] = arrivalTime;
                    q.push(destination);
                }
            }
        }
        
        
        // for calculating the MAXIMUM time we traverse through the "timeForSignal" vector
        // if the maximum time is found we will return else if all are INT_MAX which means no maximum time found we return -1.
        
        int maximum = 0;
        for(int i = 1;i<=n;i++){
            if(timeForSignal[i] == INT_MAX){
                return -1;
            }
            else{
                maximum = max(maximum,timeForSignal[i]);    
            }
        }
        return maximum;
    }
};