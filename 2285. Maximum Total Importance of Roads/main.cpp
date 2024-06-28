class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        cout << n;
        vector<long long>links(n, 0);
        for (auto& cities : roads) {
            links[cities[0]]++;
            links[cities[1]]++;
        }
        sort(links.begin(), links.end(), greater<long long>());

        long long res = 0;
        for (long long ct_appearances : links) {
            res += (ct_appearances * n);
            n--;
        }

        return res;
    }
};
