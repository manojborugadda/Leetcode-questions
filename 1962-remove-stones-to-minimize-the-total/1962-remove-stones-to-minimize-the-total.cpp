class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<double>pq;
        for(int i = 0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        
        while(k--){
            double x = pq.top();
            pq.pop();
            x = ceil(x/2);
            pq.push(x);
            
        }
        double sum = 0;
        while(pq.empty()==false){
            sum = sum+pq.top();
            pq.pop();
        }
        
        return sum;
    }
};