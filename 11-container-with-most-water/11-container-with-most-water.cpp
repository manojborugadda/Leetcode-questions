class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n-1;
        int max_area = 0;
        
        while(low < high){
            int width = high-low; 
            max_area = max(max_area , width * min( height[low] , height[high]));
            
            if(height[low] < height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        
        return max_area;
    }
};