class Solution {//TC:O(N+1)  SC:O(N)
public://it is evident that two input arrays will have same numbers but in permutated way, so we can just take the freq of every element and see increase the COUNT when the element's frequency in the two vetors reaches 2
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();//It is guaranteed that A and B are both a permutation of n integers.
        vector<int>freq(n+1,0);
        vector<int>ans(n,0);
        int count = 0;
        for(int i =0;i<n;i++) {
            freq[A[i]]++;
            if( freq[A[i]] == 2) count++;
            freq[B[i]]++;
            if( freq[B[i]] == 2) count++;
            ans[i] = count;
        }
        return ans;
    }
};
