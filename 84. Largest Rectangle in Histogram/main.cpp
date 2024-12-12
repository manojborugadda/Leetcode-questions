class Solution {
public:
    vector<int> nextSmallerINDEX(vector<int>& heights, int n) {
        stack<int> s;
        vector<int> res(n); // Fix: Pre-size the vector
        s.push(n); // Push an out-of-bound index to represent no smaller elements

        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != n && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            res[i] = s.top(); // Directly assign to the correct position
            s.push(i);
        }
        return res;
    }

    vector<int> prevSmallerINDEX(vector<int>& heights, int n) {
        stack<int> s;
        vector<int> res(n); // Fix: Pre-size the vector
        s.push(-1); // Push -1 to represent no smaller elements on the left

        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            res[i] = s.top(); // Directly assign to the correct position
            s.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // Processing for NEXT SMALLER ELEMENT indices
        vector<int> nextSmall = nextSmallerINDEX(heights, n);
        vector<int> prevSmall = prevSmallerINDEX(heights, n);

        int ans = 0; // Fix: Initialize to 0 instead of INT_MIN
        for (int i = 0; i < n; i++) {
            int lengthOfBuilding = heights[i];
            int breadth = (nextSmall[i] == n ? n : nextSmall[i]) - prevSmall[i] - 1; // Handle out-of-bound cases
            ans = max(ans, lengthOfBuilding * breadth);
        }
        return ans;
    }
};
