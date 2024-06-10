class Solution {//tc:o(n*logn) sc:o(n)
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected = heights;
        sort(begin(expected),end(expected));
        int i = 0,j = 0;
        int count = 0;
        while(i < heights.size() and j < expected.size()) {
            if(heights[i] != expected[j]) {
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};
