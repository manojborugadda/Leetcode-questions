class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans  = 0;
        for(int i = 0;i<energy.size();i++) {
            if(initialEnergy <= energy[i]) {
                ans = ans + energy[i] - initialEnergy + 1;
                initialEnergy =  energy[i] + 1 ;
            }
            
            if(initialExperience <= experience[i]) {
                ans = ans + experience[i] - initialExperience + 1;
                initialExperience = experience[i] +1 ;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
            
        }
        return ans;
    }
};


//https://leetcode.com/contest/weekly-contest-307/submissions/detail/779022590/
//Sam Lee solution
//21st Aug-2022