class Solution {//TWO POINTER APPROACH---------------We are not using PREFIX TREE(TRIE)
    //TC: O(nlogn + n + m) where n is size of products, and m is length of searchWord.
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        vector<vector<string>>result;
        sort(products.begin(),products.end()); //it takes NlogN Time complexity
        int l = 0 , r = products.size()-1;
        for(int i = 0;i<searchWord.size();i++){
            char ch = searchWord[i];
            
// we are moving the left and right pointer such that the below conditions does not satisfy
            while( l <= r and ( products[l][i] != ch or products[l].size() <= i ) ){
                l++;
            }
            
            while( l <= r and ( products[r][i] != ch or products[r].size() <= i ) ){
                r--;
            }
            
            result.push_back(vector<string>()); // initially inserting empty List
            
//system that suggests at most three product names from products after each character of searchWord is typed.
            int system_size = min(r-l+1,3); 
            
            for(int k = 0 ; k < system_size ; k++){
                result.back().push_back(products[l+k]);
            } 
        }
        return result;
    }
};