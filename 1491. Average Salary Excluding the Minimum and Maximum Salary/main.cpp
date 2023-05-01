class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary),end(salary));
        double sum = accumulate(salary.begin(),salary.end(),0);
        sum -= salary[0] + salary[salary.size()-1];
        //cout<<sum;
        return sum/(salary.size()-2);
    }
};
