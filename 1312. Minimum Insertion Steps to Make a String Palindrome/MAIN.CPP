class Solution {//TC:O(N^2)  SC:O(N^2)+RECURSIVE STACK
public:
    vector<vector<int>>memo;
    int recur(string &s, int start ,int end) {
        if(start >= end) {//terminating condition for checking PALINDROME
            return 0;
        }else if(memo[start][end] != -1) {//if it is already computed
            return memo[start][end];
        }else {
            if(s[start] == s[end]) {//if it is satisfying for PALINDROME
                return memo[start][end] = recur(s,start+1,end-1);
            }else {
                int insertBegin = recur(s,start,end-1);
                int insertEnd = recur(s,start+1,end);
                return memo[start][end] = min(insertBegin,insertEnd)+1;
            }
        }


    }
    int minInsertions(string s) {
        int n = s.length();
        memo  =  vector<vector<int>>(n,vector<int>(n,-1));
        return recur(s,0,n-1); 
    }
};
