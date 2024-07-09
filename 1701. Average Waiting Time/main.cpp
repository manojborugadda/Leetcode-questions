class Solution {//TC:O(N) SC:O(1)
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double timeFinish = customers[0][0];//// totalTime is initialised with arrival time of first customer
        double timeWaiting = 0;
        for(int i = 0;i<n;i++) {
            if(timeFinish > customers[i][0]) {// when the chef is busy making other orders
                timeFinish += customers[i][1];
                timeWaiting += timeFinish - customers[i][0];
            }else { //when chef is FREE
                timeFinish =  customers[i][0]+customers[i][1];
                timeWaiting +=  customers[i][1];
            }
        }
        return timeWaiting/n;
    }
};
