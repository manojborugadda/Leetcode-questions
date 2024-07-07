class Solution {//TC:O(N)  SC:O(1)
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        k = k%n;//we want to decrease the initial K. so we did this
        string temp = s;
        for(int i = 0;i<n;i++) {
            int j = (i+k)%n;
            s[i] = temp[j];
        }
        return s;
    }
};

// need to replace the current 'i' with (i+k) and as they are saying in cyclic we replace it with (i+k)%n
