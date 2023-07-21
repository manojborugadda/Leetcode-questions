class Solution {//TC:O(nlogn) sc:o(1)
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long newMass = mass;
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0;i<n;i++) {
            if(newMass < asteroids[i]) {
                return false;
            }
            newMass+= asteroids[i];
        }
        return true;
    }
};
