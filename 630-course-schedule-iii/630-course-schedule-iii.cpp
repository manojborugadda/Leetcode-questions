class Solution { //TC:O(nlogn)  SC:O(n)
public: 
    
    //courses[i] = [durationi, lastDayi]
    //sorting on the basis of second element in vector like 
    // before sorting --- [[100,200],[200,1300],[1000,1250],[2000,3200]]
    //after sorting--- [ [100,200],[1000,1250],[200,1300],[2000,3200] ]
    
    bool static comp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        if(n==0) return 0;
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int>pq;//MAX HEAP
        int sum = 0;
        for(auto x:courses)
        {
            sum = sum+x[0];
            pq.push(x[0]);
            if(sum > x[1]){
                sum = sum-pq.top();
                pq.pop();
            }
        }
        return pq.size(); // priority queue size gives us max number of courses at last :)
    }
};