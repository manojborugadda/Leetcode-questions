class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        
        int maxarea = -1, l, b, maxdia = -1, dia;
        
        for(int i=0; i<d.size(); ++i)
        {
            l = d[i][0]; b = d[i][1];
            dia = l*l + b*b;
            
            if(dia > maxdia)
            {
                maxdia = dia;
                maxarea = l*b;
            }
            
            else if(dia == maxdia)  //if length of diameter is same, then pick the maximum area among the two.
            {
                if(maxarea < l*b)
                    maxarea = l*b;           
            }
        }
        
        return maxarea;
    }
};
//If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.
