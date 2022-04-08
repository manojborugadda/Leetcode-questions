class KthLargest {
public:
       /*
        Whenever there is a question says 'kth largest' 
        'kth smallest' we'll use priority queue
        
        here, we'll make min_heap
    */
    priority_queue<int,vector<int>,greater<int>>pq;
    
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        size = k;  // for the sake of the keeping the Kth largest elements size
        
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }   
    }
    
     int add(int val) {
        pq.push(val);
        
        // maintaining the size k of the pq
        if(pq.size() > size)  {  
            pq.pop();
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */