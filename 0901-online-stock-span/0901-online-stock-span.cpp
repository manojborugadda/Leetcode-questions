class StockSpanner {  //TC:O(1) SC:O(N)
public:                                  //just like NEXT GREATER ELEMENT problem
    
    //declare a stack of pair {price, count}
    // count will keep track of no. of consecutive elements less than or equal to price

    stack<pair<int,int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count  = 1;
        // find no. of elements less than or equal to curr price
        while(s.empty()== false and s.top().first <= price) {
            //update count
            count += s.top().second;
            s.pop(); // pop the smaller element
        }
        // push the {price, count} into stack
        s.push({price,count});
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */