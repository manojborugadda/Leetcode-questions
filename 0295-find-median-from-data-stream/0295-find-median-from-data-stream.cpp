class MedianFinder { ///TC:O(N)  SC:O(1)
public:
     priority_queue<int>maxHeap;
     priority_queue<int,vector<int>,greater<int>>minHeap;
 
    MedianFinder() {
        
    } 
    
    void addNum(int num) {
        //if the MAXHEAP size is greater than 0 and its top element is less than incoming element we PUSH it to MINHEAP
        if( maxHeap.size() > 0 and num > maxHeap.top() ) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        //if the size of MAXHEAP is greater than 1 + size of MINHEAP we 
        //push the top element to the MINHEAP and pop that element in MAXHEAP
        if(maxHeap.size() > minHeap.size()+1 ) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        //if the size of MINHEAP is greater than 1 + size of MAXHEAP we 
        //push the top element to the MAXHEAP and pop that element in MINHEAP

        if(minHeap.size() > maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        //if the size of the both priority queues is same then we simply add top elements
        //of the both the queues and divide by 2
        if( maxHeap.size() == minHeap.size() ) {
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
        }
        
        if( maxHeap.size() > minHeap.size() ){
            return maxHeap.top();
        }else {
            return minHeap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
