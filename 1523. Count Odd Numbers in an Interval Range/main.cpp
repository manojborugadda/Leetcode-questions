```
class Solution {
public:
    int countOdds(int low, int high) ``{
        // the count of odd numbers between [low, high]
        // = that between [1, high] - that between [1, low) 
        // 1 --- low ---- high
        // [....]
        // [.................]
        // the count of odd numbers between 1 and n is (n + 1) / 2
        // the count of odd numbers between 1 and low - 1 is low / 2
        // the count of odd numbers between 1 and high is (high + 1 ) / 2
        return (high + 1) / 2 - low / 2;
    }
};
```
///BRUTE FORCE
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int i = low;i<=high;i++) {
            if(i%2 != 0) {
                count++;
            }
        }
        return count;
    }
};

