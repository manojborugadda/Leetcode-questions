typedef pair<int,int> P;
typedef long long ll;

class Solution { //TC:O(nlogn)  SC:O(n)
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>ans;//to store the answer

        priority_queue<P,vector<P>,greater<>>pq;//MIN HEAP

        //inserting the index in the TASKS
        for(int i = 0;i<n;i++) {
            tasks[i].push_back(i);
        }
        //sort according to the ENQUEUE time
        sort(begin(tasks),end(tasks));

        //traverse through the tasks
        int i = 0;
        ll currTime = 0;
        while( i < n or !pq.empty() ) {
            if(pq.size() == 0) {// if pq is empty no task is there , insert one task so time will shift to that task 's enqueue time.
                currTime = max(currTime,(ll)tasks[i][0]);
            }

            while(i < n and tasks[i][0] <= currTime) {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
             //  now take out the first job. among them.
            auto [processingTime,index] = pq.top();
            pq.pop();
            currTime += processingTime;
            ans.push_back(index);
        }  
        return ans;
    }
};
