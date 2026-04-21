class Solution {
public:
    int solveStartToEnd(vector<int>& colors) {
        int n = colors.size();
        int i = 0 , j  = n-1;
        int maxi = INT_MIN;
        while(i < j) {
            if(colors[i] == colors[j]) j--;
            if(colors[i] != colors[j]) {
                maxi = abs(i-j);
                break;
            }
        }
        cout<<maxi<<endl;
        return maxi;
    }
    int solveEndToStart(vector<int>& colors) {
        int n = colors.size();
        int i = 0 , j  = n-1;
        int maxi = INT_MIN;
        while(i < j) {
            if(colors[i] == colors[j]) i++;
            if(colors[i] != colors[j]) {
                maxi = abs(i-j);
                break;
            }
        }
        cout<<maxi<<endl;
        return maxi;
    }
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int maxd1= solveStartToEnd(colors);
        int maxd2 = solveEndToStart(colors);
        ans = max(maxd1,maxd2);
        return ans;
    }
};

/**
We can maximize the distance between diff colours when you start comparing from Beginning and end points.
(Remeber to traverse the array 2 times(start to end and end to start))

*/
