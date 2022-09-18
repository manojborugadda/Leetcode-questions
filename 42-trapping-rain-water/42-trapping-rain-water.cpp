class Solution {
public:
    int trap(vector<int>& height) 
    {
    if(height.empty())
        return 0;
    
   	int area = 0;
	
   int n = height.size();
	int leftmax[n] ,rightmax[n] ;
    
    memset(leftmax,0,n);
    memset(rightmax,0,n);
        
	leftmax[0] = height[0];
	
	for(int i = 1;i<n;i++)
	{
		leftmax[i] = max(leftmax[i-1],height[i]);
	}
	
	 rightmax[n-1] = height[n-1];
	
	for(int i = n-2;i>=0;i--)
	{
		rightmax[i] = max(rightmax[i+1],height[i]); 
	}
	
	for(int i = 0;i<n;i++)
	{
		area += min(rightmax[i],leftmax[i]) - height[i];
	}
        
    return area;   
    }
};