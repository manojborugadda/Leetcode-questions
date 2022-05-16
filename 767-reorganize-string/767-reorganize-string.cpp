class Solution {  // TC:O(N)  SC:O(N)
public:
    string reorganizeString(string s) {
        map<char,int>mp; // taking the frequency map of the character in the string
        for(auto &x:s){
            mp[x]++;
        }
        
        priority_queue<pair<int,char>>pq;  //pushing into the PRIORITY QUEUE 
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        
        string ans = "";
        // we are taking the top two freq characters and adding it to the answer string i.e why we maintain the size greater than 1
        while(pq.size() > 1)
        {
            auto p = pq.top();
            pq.pop();
            auto q = pq.top();
            pq.pop();
            ans += p.second ;
            ans += q.second;
            p.first--;
            q.first--;
            if(p.first > 0){
                pq.push(p);
            }
            if(q.first > 0){
                pq.push(q);
            }
            
        }
        
        //if there are any elements left in the PRIORITY QUEUE we add to the ANSWER string
        if(pq.empty()==false) 
        {
            if(pq.top().first==1){ 
                ans+=pq.top().second;
            }
            else{
                return "";
            }
        }
        
        return ans;
    }
};