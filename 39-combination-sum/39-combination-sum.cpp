class Solution {
public:
        vector<vector<int>> result;
         vector<int> temp; // current combination vector
    void backtrack(vector<int>& candidates, int target, int i)
    {
        if(target == 0)
        {
            result.push_back(temp);
        }
        else if(target > 0)
        {
            for(int j = i; j < candidates.size(); j++)
            {
                temp.push_back(candidates[j]);
                backtrack(candidates, target - candidates[j], j);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        backtrack(candidates, target, 0);
        return result;
    }
};