struct comparator{//custom comparator for SET
    bool operator()(pair<int,string> a , pair<int,string> b)const{
        if(a.first > b.first){ //Returns the name of the food item that has the highest rating for the given type of cuisine.
            return 1;
        }
        if(a.first < b.first){
            return 0;
        }
        return (a.second < b.second);///return the item with the lexicographically smaller name.
    }
    
};




class FoodRatings {
public:
    
    ///CUISINE-----to------ RATING and FOOD
    unordered_map<string , set<pair<int,string> , comparator>>map1;
    
    ///"foods"---to------"cuisine" and "rating"
    unordered_map<string,pair<string,int>>map2;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i<n;i++){
            map2[foods[i]] = {cuisines[i],ratings[i]};
            map1[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        //we have to change the existing rating for Food. For that we should have cuisine and oldrating to get DELETED
        string cuisine = map2[food].first;
        int oldRating = map2[food].second;
        
        map1[cuisine].erase({oldRating,food});
        
        map2[food] = {cuisine,newRating}; // updating the newRating for that particular CUISINE
        map1[cuisine].insert({newRating,food}); //adding the newRating and food to the map1
        
    }
    
    string highestRated(string cuisine) {
        return (*map1[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
