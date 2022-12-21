class Solution {  //TC:O(1) SC:O(1)
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int area1 = (ax2-ax1)*(ay2-ay1) , area2 = (bx2-bx1)*(by2-by1);
        
        //calculating the overalapped vertices
        int x2 = min(ax2,bx2) , y2 = min(ay2,by2);
        int x1 = max(ax1,bx1) , y1 = max(ay1,by1);
        
        int len = x2 - x1;
        int brd = y2 - y1;
        int overalapped_area = 0;
        if(len > 0 and brd > 0) {
            overalapped_area = len * brd;
        }
        return area1 + area2 - overalapped_area;
    }
};
