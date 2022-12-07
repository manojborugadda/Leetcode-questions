class Solution {  //TC:O(NLOGN) SC:O(1)
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int i = 0 , j = n-1;
        long long sum = 0;
        sort(begin(skill),end(skill));
        while(i < j) {
            if(skill[i] + skill[j] != skill[i+1] + skill[j-1]) {
                return -1;
            }
            sum += skill[i] * skill[j];
            i++;
            j--;
        }
        return sum;
    }
};
