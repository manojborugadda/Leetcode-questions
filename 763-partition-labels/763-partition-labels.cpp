class Solution {  // TC:O(N)   SC:O(N)
public:
        vector<int> partitionLabels(string s){
                vector<int>ans;
                unordered_map<char,int>mp;

                for(int i = 0;i<s.length();i++){
                    char ch = s[i];
                     mp[ch] = i;
                }

            int prev = -1 , mx = 0;

            for(int i = 0;i<s.length();i++){
                    mx = max(mx,mp[s[i]]);
                    if(mx == i){  // partition time
                        ans.push_back(mx-prev);
                        prev = mx;
                    }
            }

            return ans;
         }
    };