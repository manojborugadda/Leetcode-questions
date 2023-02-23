class Solution {//  TC:O(N log N + K log N) = O(N log N), SC:O(N)
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>projects(n);
        for(int i = 0;i<n;i++) {
            projects[i] = {capital[i],profits[i]};
        }
        sort(begin(projects),end(projects));
        priority_queue<int>maximizedCapital;
        int i = 0;
        while(k--) {
            while( i < n and projects[i].first <= w) {
                maximizedCapital.push(projects[i].second);
                i++;
            }
            if(maximizedCapital.size() == 0) {
                break;
            }

            w += maximizedCapital.top();
            maximizedCapital.pop();
        }
        return w;
    }
};

//maximum possible profit with available captial
