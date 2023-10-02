class Solution {//TC:O(N)  SC:O(1)
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob   = 0;
        for(int i = 1;i<colors.length()-1;i++) {
            if(colors[i-1] == colors[i] and colors[i] == colors[i+1]) {
                if(colors[i] == 'A') {
                    alice++;
                }else {
                    bob++;
                }
            }
        }
        return alice > bob;
    }
};
