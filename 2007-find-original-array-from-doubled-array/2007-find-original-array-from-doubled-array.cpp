class Solution { //TC:O(nlogn)  SC:O(N)
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        int n = arr.size();
        if(n%2 != 0){
            return {};
        }
        vector<int> ans; ///answer vector
        unordered_map<int,int>map;
        //sorting the vector
        sort(begin(arr),end(arr));
        //taking the frequencies of the elements in the array
        for(auto x:arr) {
            map[x]++;
        }
        //checking whether the double value of element is present in the HASHMAP
        for(auto x:arr){
            if(map[x] == 0) continue;
            if(map[x*2] == 0) return {};
            //if the element and Double value of that element is present in the MAP 
            //We decrement that freq from Map ans push that Element to the VECTOR
            if( map.find(x*2) != map.end() and map.find(x) != map.end() ){
                ans.push_back(x);
                map[x*2]--;
                map[x]--;
            }
        }
        return ans;
    }
};