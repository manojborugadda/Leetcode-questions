// 873. Length of Longest Fibonacci Subsequence

class Solution {//TC:O(N^3)  SC:O(N)
public:// n^3  = n^2 is for loop and n is checking in the map(worst case)
    int recursion(int j , int k, vector<int>&arr, unordered_map<int,int>&map) {
        // int result = 0;
        int target = arr[k] - arr[j];
        if(map.count(target) and map[target] < j) {
            int i = map[target];
            return recursion(i,j,arr,map) + 1;
        }
        return 2; // if only j , k are in FIBONACCI series and 'i' is not we return this 2 as length of those (j , k )
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // int result = 0;
        unordered_map<int,int>map;
        for(int i = 0;i<n;i++) {
            map[arr[i]] = i; // element --> index
        }

        int mx_length = 0;
        // j < k --------> in sequence of i < j < k
        for(int j =1;j<n;j++) {
            for(int k = j+1;k<n;k++) {
                int length = recursion(j,k,arr,map);
                if(length >= 3) {
                    mx_length = max(mx_length,length);
                }
            }
        }
        return mx_length;
    }
};
