class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        //priority_queue<int>pq(stones.begin(),stones.end());
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(1){
            
            // base cases
            if(pq.size()==0) return 0;
            if(pq.size()==1) return pq.top();
            
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x!=y){
                pq.push(abs(x-y));
            }
        }
    }
};