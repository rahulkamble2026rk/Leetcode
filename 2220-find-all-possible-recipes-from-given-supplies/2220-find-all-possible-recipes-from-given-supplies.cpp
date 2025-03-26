#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, vector<string>> stdmap; 
        set<string> available(supplies.begin(), supplies.end()); // Convert supplies to set for quick lookup
        vector<string> ans;
        
        // Mapping recipes to their ingredients
        for (int i = 0; i < recipes.size(); i++) {
            stdmap[recipes[i]] = ingredients[i];
        }
        
        bool added = true; // To track if any new recipe was added in a pass
        while (added) {
            added = false;
            
            for (auto it = stdmap.begin(); it != stdmap.end();) {
                string recipe = it->first;
                vector<string> ing = it->second;
                bool canMake = true;

                // Check if all ingredients are available
                for (string i : ing) {
                    if (available.find(i) == available.end()) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    ans.push_back(recipe);
                    available.insert(recipe); // Recipe becomes an available ingredient
                    it = stdmap.erase(it);   // Remove recipe from map since it's processed
                    added = true;
                } else {
                    ++it;
                }
            }
        }
        return ans;
    }
};
