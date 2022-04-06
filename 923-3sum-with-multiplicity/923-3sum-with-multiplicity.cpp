class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        unordered_map<int,long>map;
        int n = arr.size();
        int m  = 1e9+7;
        
        for(int i  = 0;i<n;i++){
            map[arr[i]]++;
        }
        
        for(auto t1:map )
        {
            for(auto t2:map){
                int x = t1.first;
                int y = t2.first;
                int z = target - x - y;
                if(map.find(z)!=map.end())
                {
                    if(x == y and y == z)
                    {
                        ans = ans+((map[x])*(map[x]-1)*(map[x]-2))/6;
                    }
                    else if(x==y and y!=z)
                    {
                        ans = ans+(map[x]*(map[x]-1))/2 * (map[z]);
                    }
                    else if(x < y and y < z)
                    {
                        ans = ans+((map[x])*(map[y])*(map[z]));
                    }
                }
            }
            ans = ans%m;
        }
        return ans;
    }
                
};