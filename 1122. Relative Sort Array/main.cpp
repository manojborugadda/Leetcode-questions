class Solution {//TC:O(N*f) f -- is the max freq of any element, SC:O(N)
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int,int>map;
        for(auto x:arr1) {
            map[x]++;
        }
        //picking each element from arr2 and sorting the elements in arr1 such that relative ordering  of items in arr1 and arr2 are same
        for(int i =0 ;i<arr2.size();i++) {
            int k = arr2[i];
            int freq = map[arr2[i]];
            while(freq--) {
                if(freq == 0) map.erase(k);//if the freq of any key is 0 we will remove that
                ans.push_back(arr2[i]);
            }
        }
        //for getting elements which do not appear in arr2
        for(auto [a,b]:map) {
            while(b--) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};
