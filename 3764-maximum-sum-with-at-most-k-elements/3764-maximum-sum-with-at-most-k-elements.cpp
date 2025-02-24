#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) 
    {
        priority_queue<int> pq; // Max-heap to store all top elements

        for (int i = 0; i < grid.size(); i++)
        {
            int size = min(limits[i], (int)grid[i].size()); // Take min to avoid overflow
            
            // Sort only the required `limits[i]` elements in descending order
            sort(grid[i].rbegin(), grid[i].rend()); 

            for (int j = 0; j < size; j++) 
            {   
                pq.push(grid[i][j]); // Push top elements into max-heap
            }
        } 

        long long sum = 0;
        for (int i = 0; i < k ; i++) 
        {
            sum += pq.top();
            pq.pop();
        } 
        return sum;
    }
};
