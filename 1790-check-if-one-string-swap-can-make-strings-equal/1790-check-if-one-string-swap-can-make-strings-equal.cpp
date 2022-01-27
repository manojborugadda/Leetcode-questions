class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
      if (s1.size() != s2.size()) {
            return false;
        }
        int left = 0;
        int right = s1.size() - 1;
        
        while (left <= right && s1[left] == s2[left]) {
            ++left;
        }
        
        while (left <= right && s1[right] == s2[right]) {
            --right;
        }
        
        if (left < right) {
            swap(s1[left], s1[right]);
        }
        
        return s1 == s2;
    }
};