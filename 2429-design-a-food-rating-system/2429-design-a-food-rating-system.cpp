// class FoodRatings {
// public: 
    

//     multimap<string,pair<string,int>>stdmap;
//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)  
//     {
//         for(int i=0;i<foods.size();i++)
//         {
//             stdmap.insert({cuisines[i],{foods[i],ratings[i]} } );
//         } 

//     }
    
//     void changeRating(string food, int newRating)  
//     {
//         for(auto &it:stdmap)
//         {
//             if(it.second.first==food)
//             {
//                 it.second.second=newRating;
//             }
//         } 
//     }
    
//     string highestRated(string cuisine) 
//     {
//         //highest rated cusine madla  
//         vector<pair<int,string>>vct;
//         for(auto &it:stdmap)
//         {
//             if(it.first==cuisine)
//             {
//                 vct.push_back({it.second.second,it.second.first});
//             }
//         } 

//         sort(vct.begin(),vct.end(),cmp);  
//         return vct[0].second;

//     } 

//     bool static cmp(pair<int,string>p1,pair<int,string>p2)
//     {
//         if(p1.first==p2.first)
//         {
//             return p1.second<p2.second;    
//         } 
//         return p1.first>p2.first;
//     }
// };  

// //1. modify the rating food  
// //food[i]=food of the ith food
// //cuisines[i]=is the type of th cuisine 
// /**
//  * Your FoodRatings object will be instantiated and called as such:
//  * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
//  * obj->changeRating(food,newRating);
//  * string param_2 = obj->highestRated(cuisine);
//  */


// class FoodRatings {
// public: 
//     multimap<string, pair<string, int>> stdmap;
//     unordered_map<string, multimap<string, pair<string, int>>::iterator> foodPos; 

//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for (int i = 0; i < foods.size(); i++) {
//             auto it = stdmap.insert({cuisines[i], {foods[i], ratings[i]}});
//             foodPos[foods[i]] = it; // store iterator for O(1) lookup
//         }
//     }
    
//     void changeRating(string food, int newRating) {
//         auto it = foodPos[food];  // O(1) find food
//         it->second.second = newRating; // directly update rating
//     }
    
//     string highestRated(string cuisine) {
//         int maxRating = INT_MIN;
//         string bestFood;

//         auto range = stdmap.equal_range(cuisine);
//         for (auto it = range.first; it != range.second; ++it) {
//             int rating = it->second.second;
//             string food = it->second.first;

//             if (rating > maxRating || 
//                 (rating == maxRating && food < bestFood)) {
//                 maxRating = rating;
//                 bestFood = food;
//             }
//         }
//         return bestFood;
//     }
// };


class Food {
public:
    // Store the food's rating.
    int foodRating;
    // Store the food's name.
    string foodName;

    Food(int foodRating, string foodName) {
        this->foodRating = foodRating;
        this->foodName = foodName;
    }

    // Overload the less than operator for comparison
    bool operator<(const Food& other) const {
        // If food ratings are the same sort on the basis of their name. (lexicographically smaller name food will be on top)
        if (foodRating == other.foodRating) {
            return foodName > other.foodName;
        }
        // Sort on the basis of food rating. (bigger rating food will be on top)
        return foodRating < other.foodRating;
    }
};

class FoodRatings {
    // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with the cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;
    
    // Store all food of a cuisine in priority queue (to sort them on ratings/name)
    // Priority queue element -> Food: (foodRating, foodName)
    unordered_map<string, priority_queue<Food>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(rating, name)' element in current cuisine's priority queue.
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    } 
    
    void changeRating(string food, int newRating) {
        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(new rating, name)' element in respective cuisine's priority queue.
        auto cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        // Get the highest rated 'food' of 'cuisine'.
        auto highestRated = cuisineFoodMap[cuisine].top();
        
        // If the latest rating of 'food' doesn't match the 'rating' on which it was sorted in the priority queue,
        // then we discard this element of the priority queue.
        while (foodRatingMap[highestRated.foodName] != highestRated.foodRating) {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.foodName;
    }
};