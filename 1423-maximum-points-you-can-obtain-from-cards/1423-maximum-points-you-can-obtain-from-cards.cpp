class Solution { //TC:O(K) SC:O(1)
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n = cardPoints.size();
        
        for(int i=0;i<k;i++){ // taking sum of first K elements
            sum+=cardPoints[i];
        }
        
        int maxsum=sum;
        
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[n-k+i];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};