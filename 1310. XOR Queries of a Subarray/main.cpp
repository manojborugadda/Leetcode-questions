class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        //calculating the cumulative XOR's
        vector<int>cumXOR(n,0); //sc:o(n)
        cumXOR[0] = arr[0];
        for(int i = 1;i<arr.size();i++) {//tc:o(n)
            cumXOR[i] = cumXOR[i-1]^arr[i];
        }
        vector<int>ans;
        for(int i = 0;i<queries.size();i++) {//tc;o(queries)
            int left = queries[i][0];
            int right = queries[i][1];
            int xorVal = cumXOR[right]^(left == 0 ? 0 : cumXOR[left-1]);
            ans.push_back(xorVal);
        }
        return ans;
    }
};
