class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxLength = 0;
        int t = 0, f = 0;

        for(int i = 0, j = 0; i < answerKey.size(); i++) {
            if(answerKey[i] == 'T') t++;
            else f++;

            if(t > k && f > k) {
                if(answerKey[j] == 'T') t--;
                else f--;

                j++;
            }
            
            maxLength = std::max(maxLength, t + f);

        }
        return maxLength;
    }
};
