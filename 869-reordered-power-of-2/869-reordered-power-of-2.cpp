class Solution {  //using SORTING we have done this problem
public://TC:O(nlogn) SC:O(N)
    bool reorderedPowerOf2(int n) {
        vector<string>v;
        for(int i = 0;i<31;i++){
            int p = pow(2,i);
            v.push_back( to_string(p) );
        }
        
        for(int i = 0;i<31;i++){
            sort(v[i].begin(),v[i].end());
        }
        
        string s = to_string(n);
        sort(begin(s),end(s));
        for(int i = 0;i<31;i++){
            if(v[i] == s) return true;
        }
        return false;
    }
};