class Solution { //TC:O(nlogn) SC:O(N)
public:
   static bool compare(vector<int>a , vector<int>b){
       if(a[0] < b[0]) return true;
       if(a[0] == b[0]){//If multiple values have the same frequency, sort them in decreasing order.
           return a[1] > b[1];
       }
       return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
         vector<int>ans;//answer vector
        unordered_map<int,int>map;//taking the Frequency map
        for(auto x:nums){
            map[x]++;
        }
        
        vector<vector<int>>arr;
        for(auto x:map){
            arr.push_back({x.second,x.first});    
        }
        //sort the array in increasing order based on the frequency of the values. 
        sort(begin(arr),end(arr),compare); ///sorting the Array with the use of CUSTOM comparator
        
        for(auto x:arr){
            int freq = x[0];
            while(freq--){
                ans.push_back(x[1]);
            }
        }
        return ans;
    }
};


/*
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const int &it : nums)
            mp[it]++;
        vector<pair<int, int>> arr;
        for(const int &it : nums)
            arr.push_back({mp[it], it});
        sort(arr.begin(), arr.end(), cmp);
        for(int i=0; i<arr.size(); i++)
            nums[i] = arr[i].second;
        return nums;
    }
};
*/
