class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //MIN HEAP
        priority_queue<int, vector<int>, greater<int>> numbers;
        
        int m  = matrix.size();
        int n = matrix[0].size();
        //pushing the values of matrix into the Priority QUEUE
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                numbers.push(matrix[i][j]);
            }
        }
        ///traversing the Priority Queue (MIN HEAP)
         int a = 0;
        while(numbers.empty() == false and k != 0){
             a = numbers.top();
            numbers.pop();
            k--;
        }
        return a;
    }
};