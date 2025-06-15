class Solution 
{
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxVersion = s;
        string minVersion = s;

        // Create maximum version by replacing the first non-9 digit with '9'
        for (char c : s) {
            if (c != '9') {
                for (char &ch : maxVersion) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // Create minimum version
        if (s[0] != '1') {
            // If the first digit is not '1', replace all its occurrences with '1'
            char target = s[0];
            for (char &ch : minVersion) {
                if (ch == target) ch = '1';
            }
        } else {
            // Find the first digit (after index 0) that is not '0' or '1' and replace with '0'
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char target = s[i];
                    for (char &ch : minVersion) {
                        if (ch == target) ch = '0';
                    }
                    break;
                }
            }
        }

        int a = stoi(maxVersion);
        int b = stoi(minVersion);
        return a - b;
    }
};
