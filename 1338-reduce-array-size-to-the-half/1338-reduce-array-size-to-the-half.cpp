class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {          // for example arr = [3,3,3,3,5,5,5,2,2,7]
            //3 -> 4
            //5 -> 3
            //2 -> 2
            //7 -> 1
        
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        int min_count = 0;  //the min count that counts the set of integers to be removed
        int halfsize = arr.size()/2; // taking half size -> for further use
        
        for(auto x:arr){
            mp[x]++;
        }
        
        for(auto t:mp){
            pq.push(t.second);
        } 
        	/*
			priority queue has the following (increasing order):
			4 3 2 1
		*/
        
        while(halfsize > 0){
            halfsize -= pq.top();
            pq.pop();
            min_count++;
        }
        
        return min_count;
    }
};