class Solution {
public:
    // Helper function to calculate the minimum number of swaps to sort an array
    int minimumSwaps(vector<int> nums) {
        vector<int> sorted = nums; // Create a sorted copy of the array
        unordered_map<int, int> map; // Map to store the current indices of elements
        int swaps = 0;

        sort(begin(sorted), end(sorted)); // Sort the array

        // Build the mapping of element to its index in the original array
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        // Iterate through the array and perform swaps
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sorted[i]) { // If the element is not in the correct position
                swaps++;

                // Get the index of the correct element
                int currIdx = map[sorted[i]];

                // Update the mapping after the swap
                map[nums[i]] = currIdx;

                // Swap the elements in the array
                swap(nums[i], nums[currIdx]);
            }
        }

        return swaps;
    }

    // Main function to calculate the minimum number of operations
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int minSwaps = 0;

        // Perform level order traversal
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                // Add children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate the swaps needed for the current level
            minSwaps += minimumSwaps(temp);
        }

        return minSwaps;
    }
};
