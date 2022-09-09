class Solution { //TC:O(nlogn) SC:O(N)
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0]; //handling the "attack" and keep the order(HIGH---->LOW)
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0;
        sort(begin(properties),end(properties),comp);
        int maxTillNow = INT_MIN; // handling the second element only i.e "defense".
        for(auto p : properties){
            if(maxTillNow > p[1]) count++;
            else{ //(maxTillNow > p[1])
                maxTillNow = p[1];
            }
        }
        return count;
    }
};