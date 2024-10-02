class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0); // To store frequency of remainders

        // Calculate remainder counts
        for (int num: arr) {
            int remainder = ((num % k) + k) % k;
            remainder_count[remainder]++;
        }
        // Check if the pair conditions are met
        if (remainder_count[0] % 2 != 0) return false; // Remainders 0 must form pairs among themselves

        
        for (int i=1; i< (k/2)+1; i++) {
            // Remainder i must have equal count to remainder k-i
            if( remainder_count[i] != remainder_count[k-i] ) return false;
        }
    return true;
    }
};
