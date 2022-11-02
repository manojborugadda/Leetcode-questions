class Solution { //TC:O(8*N)  SC:O(2*N)
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited{bank.begin(),bank.end()};
        if(visited.find(end) == visited.end()) {//if "end" mutaion is not in list return -1;
            return -1;
        }
        
        int min_count = 0 , n;
        string curr,temp;
        queue<string>q;
        q.push(start);
        
        while(q.empty() == false) {
            
            n = q.size();
            while(n--) {
                 string curr = q.front();
                q.pop();
                if(curr == end) return min_count;
                visited.erase(curr);
                
                for(int i = 0;i<8;i++) {
                    temp = curr;
                    temp[i] = 'A';
                    if(visited.count(temp)) q.push(temp);
                    temp[i] = 'C';
                    if(visited.count(temp)) q.push(temp);
                    temp[i] = 'G';
                    if(visited.count(temp)) q.push(temp);
                    temp[i] = 'T';
                    if(visited.count(temp)) q.push(temp);
                }
            }
            min_count++;
        }
        return -1;
    }
};