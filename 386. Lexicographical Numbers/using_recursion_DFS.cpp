class Solution {//TC:O(N)  SC:O(no. of digits in given "n") -- O(1)
public:
    void recursion(int currNum,int n,vector<int>&ans) {
        if(currNum > n) {
            return;
        }
        ans.push_back(currNum);
        for(int append = 0;append <= 9;append++) {
            int newNum = currNum*10+append;
            if(newNum > n) {
                return;
            }
            recursion(newNum,n,ans);    
        }
    }
    vector<int> lexicalOrder(int n) {
        // using DFS 
        vector<int>ans;
        for(int startNum =1 ; startNum <= 9 ; startNum++) {
            recursion(startNum,n,ans);
        }
        return ans;      
    }
};

//As the recursion depth is bounded by the logarithm of n, which is constant for the given problem constraints (maximum depth of approximately 15 for n up to 50,000), the space complexity can be considered O(1).
