class Solution { //TC:O(N)  SC:O(N)
public:
    int candy(vector<int>& ratings) {
        vector<int>distribution(ratings.size(),1);
        int minim_candies  = 0;
        //updating the distribution vector by checking ratings array from LEFT to RIGHT
        for(int i =0;i<ratings.size()-1;i++){
            if(ratings[i+1] > ratings[i]){
                distribution[i+1] = distribution[i]+1;
            }
        }
        //updating the distribution vector by checking ratings array from RIGHT to LEFT
        for(int i = ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                if(distribution[i-1] <= distribution[i]){
                    distribution[i-1] = distribution[i]+1;
                }   
            }
        }
        
        minim_candies = accumulate(distribution.begin(),distribution.end(),0);
      // for(int i = 0;i<ratings.size();i++){
      //     minim_candies += distribution[i];
      // }
        
        return minim_candies;
    }
};