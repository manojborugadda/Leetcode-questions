class Solution { //TC:O(nlogn)  SC:O(1)
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
//Adding 0 and h , 0 and w to the horizontal and vertical vectors as they aslo acts as CUTS
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        int hc = horizontalCuts.size();
        int vc = verticalCuts.size();
        //sorting the vectors
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        //finding the maximum distance between the cuts in two vectors
        long length = 0 , breadth = 0;
        for(int i = 1;i<hc;i++){// it gives the length
            if( length < horizontalCuts[i] - horizontalCuts[i-1] ){
                length =  horizontalCuts[i] - horizontalCuts[i-1];
            }
        }
        
        for(int i = 1;i<vc;i++){ //it gives the max distance between the columns which is BREADTH
            if(breadth < verticalCuts[i]-verticalCuts[i-1] ){
                breadth = verticalCuts[i]-verticalCuts[i-1];
            }
        }
        
        return (length*breadth)%(1000000007);
    }
};