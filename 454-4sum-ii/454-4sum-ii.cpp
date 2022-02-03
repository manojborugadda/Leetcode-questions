class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
       
        unordered_map<int,int> map;
        for(int x : nums1){
            for(int y : nums2){
                map[x+y]++;
            }
        }
        int cnt = 0;
        for(int x : nums3){
            for(int y : nums4){
    //The map::count() is a built-in function in C++ STL which returns 1 if the element with key K  is present in the map container. It returns 0 if the element with key K is not present in the container.
                if(map.count((-(x+y)))==1){
                    cnt+= map[(-(x+y))];
                }
            }
        }
        return cnt;
    }
};