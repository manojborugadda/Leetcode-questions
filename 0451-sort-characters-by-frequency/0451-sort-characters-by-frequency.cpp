class Solution { //TC:O(NLOGN)+O(N) SC:O(N)
public:
    string frequencySort(string s) {
        string ans = "";
        map<char,int>map;
        priority_queue<pair<int,char>>pq;
        
        //taking the frequencies of the characters in the string
        for(auto x:s) {
            map[x]++;
        }
        //pushing into the PRIORITY QUEUE by { frequency of character , character}
        for(auto x:map) {
            pq.push(make_pair(x.second,x.first));
        }
        
        //building the resultant string in the frequencies of DESCENDING order
        while( pq.empty() == false) {
            char ch = pq.top().first;
            int times = pq.top().second;
            //ans += string(ch,times);
            ans.append(pq.top().first,pq.top().second);

            pq.pop();
        }      
        return ans;
    }
};