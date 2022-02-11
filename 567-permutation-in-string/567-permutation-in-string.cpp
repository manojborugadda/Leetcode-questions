class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
           vector<int> freq_s(26), window(26); 
            int p = s1.size();
            if(p > s2.size()) return false;
        
        for(int i=0;i< p;i++){  // here we are checking the first window size of length of the string S1 with S2 frequency
            freq_s[s2[i]-'a']++;
            window[s1[i]-'a']++;
        }
        
        if(freq_s == window) return true; 
        
        for(int i = 1;i<s2.size()-p+1;i++){
            freq_s[s2[i-1]-'a']--;   // decrementing the first element in the previous slide window
            freq_s[s2[i+p-1]-'a']++;  // incrementing the last element in the current slide window
            if(freq_s == window) return true;
        }
        
        return false;
    }
    
    // int sz1=s1.size();
    //     int sz2=s2.size();
    //     if(sz1>sz2)return false;
    //     vector<int> v1(26,0);
    //     vector<int> v2(26,0);
    //     for(int i=0;i<sz1;i++){
    //         v1[s1[i]-'a']++;
    //         v2[s2[i]-'a']++;
    //     }
    //     if(v1==v2)return true;
    //     for(int i=sz1;i<sz2;i++){
    //         v2[s2[i]-'a']++;
    //         v2[s2[i-sz1]-'a']--;
    //         if(v1==v2)return true;
    //     }
    //     return false;
};