class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0;i<details.size();i++) {
            string g = details[i].substr(11,2);
            cout<<g<<endl;
            int age = stoi(g);
            if(age > 60) {
                ans++;
            }
        }
        return ans;
    }
};
