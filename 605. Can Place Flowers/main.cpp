class Solution {//TC:O(N) SC:O(1)
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 0) return true;
        
        // [0,0,1,0,1]
        // for this type testcase we need to insert a 0 at beggining
        flowerbed.insert(flowerbed.begin(),0);

        // [1,0,0,0,1,0,0]
        // for this type testcase we need to insert a 0 at end
        flowerbed.push_back(0);


        for(int i = 1;i<flowerbed.size()-1;i++) {
            //if we have 3 empty plots consecutively we can plant new flowers
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                n--;//reduce the given n
                i++;// move to the next to next zero as we moved already by for loop i++
            }
        }
        return n<=0;//tells us if we are able to plant 'n' flowers
    }
};
