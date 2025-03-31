#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {   
        unordered_map<char, pair<int, int>> charMap; 
        
        // Step 1: Populate the map with first and last occurrences of each character
        for (int i = 0; i < s.size(); i++) {   
            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = {i, i};  // First occurrence
            } else {
                charMap[s[i]].second = i;  // Update last occurrence
            }
        }

        vector<int> result;
        int compare = 0, start = 0;

        // Step 2: Iterate through the string and determine partitions
        for (int i = 0; i < s.size(); i++) {
            compare = max(compare, charMap[s[i]].second);

            // When reaching the furthest last occurrence, create a partition
            if (i == compare) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }  
};
