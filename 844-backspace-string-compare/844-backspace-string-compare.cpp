// We will make use of two pointers (i.e i and j) First pointer to traverse the string and second to store the character given at that position.

// Steps:
// 1. Start traversing the string by first pointer i.e i. if it is pointing to # then decrease the second pointer i.e j Make sure that j is always greater than or equals to 0 (j>=0) .And if it is not pointing to # then increase the second pointer j and store the element at jth position. s[j]=s[i] continue the process until the string ends.

// 2. We will do the same porcess with second string with its two pointers i and k.

// 3. Now after traversing both the strings. If j and k are not equal then it means that the two strings have differnt length. If j and k are same, then compare elements of every index.

// 4. if the two elements of the same index of both the string are different the return false.




class Solution {  //TC:O(N)   SC:O(1)
public:
    bool backspaceCompare(string s, string t) {
        
        int k = 0 , j = 0;
        
        for(int i  = 0;i<s.length();i++){
            if(s[i] != '#')
            {
                s[j]  = s[i];
                j++;
            }
             else
            {
                j--;
                j = max(0,j);  // j must be always POSITIVE
            }
        }
        
        for(int i = 0;i<t.length();i++){
            if(t[i] != '#')
            {
                t[k]  = t[i];
                k++;
            }
             else
            {
                k--;
                k = max(0,k);  // k must be always POSITIVE
            }
        }
        
        // checking if the elements in the processed  strings S and T are Equal or Not
        if(j!=k) return false;
        else
        {
            for(int i = 0;i<k;i++){
               if( s[i]!=t[i]){
                   return false;
               } 
            }
            return true;
        }
    }
    
};