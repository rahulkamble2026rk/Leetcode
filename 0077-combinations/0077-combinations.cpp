class Solution {
public:
    vector<vector<int>> combine(int n, int k)  
    { 
        vector<vector<int>> result;
        vector<int> combination;
        generateCombinations(1, n, k, combination, result);
        return result;
    }

private:
    void generateCombinations(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) 
    {
        if (combination.size() == k) 
        {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i <= n; i++) 
        {
            combination.push_back(i);
            generateCombinations(i + 1, n, k, combination, result);
            combination.pop_back(); // Backtrack
        }
    }
};
