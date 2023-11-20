class Solution {//TC:O(N*M)  N-- length of the garbage and M --- length of the string 'str'
public://SC:O(1)
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int>prefix(travel.size(),0);
        int n = travel.size();
        int m = garbage.size();
        prefix[0] = travel[0];
        for(int i = 1;i<n;i++) {
            prefix[i] = prefix[i-1] + travel[i];
        }

        int metal = 0 , paper = 0 , glass = 0;
        int ans = 0;
        for(int i = 0;i<m;i++) {
            string str = garbage[i];
            for(char ch : str) {
                if(ch == 'G') glass = i;
                if(ch == 'P') paper = i;
                if(ch == 'M')  metal = i;
            }
            ans += str.length();
        }
        if(glass >= 1) ans += prefix[glass-1];//travel time for glass
        if(paper >= 1) ans += prefix[paper-1]; // trvael time for paper
        if(metal >= 1) ans += prefix[metal-1]; // travel time for metal
        return ans;
    }
};
