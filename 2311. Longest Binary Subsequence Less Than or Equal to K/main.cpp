class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int len = 0;
        int temp = k;

        // Length of binary representation of k
        while (temp > 0) {
            len++;
            temp >>= 1;
        }

        // Count number of zeros in left part (can include freely)
        int count = 0;
        for (int i = 0; i < n - len; i++) {
            if (s[i] == '0') count++;
        }

        // Handle right part: include as much as possible without exceeding k
        int value = 0;
        int power = 0;
        for (int i = n - 1; i >= max(0, n - len); i--) {
            if (s[i] == '1') {
                if (value + (1 << power) > k) break;
                value += (1 << power);
            }
            power++;
            count++;
        }

        return count;
    }
};


/**
count of zeros in left + count of bits in right (which don’t make the number exceed k)
-----------------------------------------------
Let "len" is the length of k in binary format
Split s to 2 halves:
left: range [0, s.length - len)
right: range [s.length-len, s.length)
Remove every 1 in left. GREEDY: always end up removing less than if you remove 1 in right part
Compare right with k in binary format.
---------------------------------------------------
**/
