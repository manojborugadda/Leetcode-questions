class Solution {///TC:O(nlogn) sc:O(1)
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long sum = 0;
        for(int i: bat) {
            sum += i;
        }
        long l=1,r=sum/n;
        long mid = 0;

        while(l < r) {
            mid = (l+r+1)/2;
            long t = 0;
            for(int i: bat) t += min(long(i),mid);

            if(t >= mid*n)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
