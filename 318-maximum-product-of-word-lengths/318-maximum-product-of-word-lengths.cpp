class Solution {  ///Using Bit Manipulation

                    // Time Complexity : O(N * N)

                    // Space Complexity : O(N)
public:
    /*
    Basically we find HASH for each Word in the string array and we do AND operation (&) for HASH of both words and If it is comes equal to ZERO then definitely they contains no common letter, so we update our 
    
    ans = max(size(words[i])*words[j])
    */
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<int>mask(n,0);
        
        for(int i = 0;i<n;i++){
            int hash = 0; 
            for(int j = 0;j < words[i].size() ; j++ ){
                hash |= 1<<(words[i][j]-'a');  //OR operation
            }
            mask[i] = hash;
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(( mask[i] & mask[j] ) == 0 ){
                    int product = words[i].size()*words[j].size();
                 ans = max(ans , product );
                }
            }
        }
        
        return ans;
    }
};