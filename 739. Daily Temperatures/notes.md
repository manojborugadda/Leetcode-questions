https://www.youtube.com/watch?v=7MIXlgBfr_U

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        
        int i,j,n=tp.size();
        vector<int> ans(n,0);
        stack<int> s;

        for(i=0;i<n;i++)
        {
            while(!s.empty() &&  tp[s.top()] < tp[i])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
};
```
