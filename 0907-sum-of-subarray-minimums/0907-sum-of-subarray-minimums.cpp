class Solution {//Time Complexity : O(N + N + N) = O(3N) ~ O(N)
                //Space Complexity : O(3N) ~ O(N)
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n) , right(n);
        int MOD = 1e9+7;
        // for every i finding the Next smaller element to left and right
        
        // Left
        stack<int>st;
        st.push(0);
        left[0] = 1;
        for(int i  = 1;i<n;i++) {
            while(st.empty() == false and arr[i] < arr[st.top()]) {
                st.pop();
            }
            if(st.empty()==true) {
                left[i] = i+1;
            }else {
                left[i] = i - st.top();
            }
            st.push(i);
        }
        
        while(st.size()) {
            st.pop();
        }
        
        //RIGHT
        //we see from right to left side finding the just smaller than current
        st.push(n-1);
        right[n-1] = 1; // distance = 1, right not found, this is distance multiplied with num, so it can't be zero
        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                right[i] = n-i; // distance
            else 
                right[i] = st.top()-i;
            
            st.push(i);
        }
        
        //calculating the answer
         int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
};