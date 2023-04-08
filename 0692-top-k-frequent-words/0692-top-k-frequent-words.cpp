class Solution { //TC:O(NLOGN)  SC:O(N)
public:
    //Custom comparator function 
    struct comparator {
    bool operator()(const pair<string,int> p1 , const pair<string,int> p2) {
        return (p1.second == p2.second) ? (p1.first > p2.first) : (p1.second  < p2.second);
        //syntax in MinHeap is shown int the implementation of comparator and it is different
    }
};
    
    vector<string> topKFrequent(vector<string>& words, int k) {
          unordered_map<string,int>map;
          for(auto x:words) {
            map[x]++;
        }
priority_queue<pair<string,int>, vector<pair<string,int>>, comparator> pq(map.begin(),map.end()); 
        vector<string>ans;
        while( pq.empty() == false and ans.size() < k ) {
            string temp =  pq.top().first;
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
}; 
