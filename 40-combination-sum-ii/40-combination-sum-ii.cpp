class Solution {
public:
    void search(vector<int>& num, int next, vector<int>& pSol, int target, vector<vector<int> >& result)
    {
        if(target == 0)
        {
            result.push_back(pSol); //pushing the current combination into the result vector or ANSWER vector
            return;
        }
        
        if(next == num.size() || target - num[next] < 0){
            return;
        }
            
        pSol.push_back(num[next]);
        search(num, next+1, pSol, target - num[next], result);
        pSol.pop_back(); // backtracking 
        while(next < num.size()-1 && num[next] == num[next+1]){
            next++;
        }
        
        search(num, next + 1, pSol, target, result);
    }

    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        vector<int> pSol;
        search(num, 0, pSol, target, result);
        return result;    
    }
};