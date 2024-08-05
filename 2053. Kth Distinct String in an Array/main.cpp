class Solution {//TC:O(N) SC;O(N)
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> seen;      // To track all seen strings
        unordered_set<string> duplicates; // To track duplicate strings

        // First pass: Identify duplicates
        for (const string& item : arr) {
            if (seen.count(item)) {
                duplicates.insert(item); // Mark as duplicate
            } else {
                seen.insert(item); // Mark as seen
            }
        }

        // Second pass: Find the k-th distinct string
        int count = 0;
        for (const string& item : arr) {
            if (seen.count(item) && !duplicates.count(item)) { // Check if it's distinct
                count++;
                if (count == k) {
                    return item; // Return the k-th distinct string
                }
            }
        }

        return ""; // Return empty string if not found
    }
};
