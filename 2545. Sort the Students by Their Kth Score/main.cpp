class Solution { //TC:O(nlogn)  SC:O(N)
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
         vector<vector<int>> ans;
         priority_queue<pair<int,int>>pq;

        //pushing the value of particular Kth index column along with the index of the ROW
        for(int i =0;i<score.size();i++) {
            pq.push(make_pair(score[i][k],i));
        }
        //we are sorting the students in the DESCENDING order
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ans.push_back(score[x.second]);//pushing the rows of the particular Kth index column
        }

        return ans;
    }
};
