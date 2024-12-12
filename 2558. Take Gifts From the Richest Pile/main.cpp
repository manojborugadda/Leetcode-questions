class Solution {//tc:o(k * nlogn)  sc:o(n)
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq(begin(gifts),end(gifts));
        long long ans = 0;

        while(!pq.empty() and k --) {
            int topElement = pq.top();
           long long temp = floor(sqrt(topElement));
            pq.pop();
            pq.push(temp);
        }

        while(!pq.empty()) {
           ans += pq.top();
           pq.pop(); 
        }
        return ans;
    }
};
