class Solution {
public:
         vector<string>result;
        void helper(int open,int close,int n,string current){
            if(current.length()==2*n)
            {
                result.push_back(current); // if the length of current string is 2*n we will insert into the result vector // or we can say if the length of both "(" and ")" becomes equal to "n" we will insert the current string into the result vector
                return; // since it is void
            }
            if(open < n) helper(open+1,close,n,current+"(");
            if(close < open) helper(open,close+1,n,current+")");
            
        }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");  
        return result;
    }
};