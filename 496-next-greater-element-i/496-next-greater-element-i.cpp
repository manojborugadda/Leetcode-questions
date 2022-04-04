class Solution {  // here we using monotonic stack and unorder map
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        
    unordered_map<int,int> m;
    stack<int> s;
    vector<int> ans;
    
    for(int n:a2)
    {
        while(!s.empty() && n>s.top())
        {
            m[s.top()]=n;
            s.pop();
        }
        s.push(n);
    }
    
    for(int n:a1)
    {
        if(m.count(n))
            ans.push_back(m[n]);
        else
            ans.push_back(-1);
    }
    
    return ans;

    }
};