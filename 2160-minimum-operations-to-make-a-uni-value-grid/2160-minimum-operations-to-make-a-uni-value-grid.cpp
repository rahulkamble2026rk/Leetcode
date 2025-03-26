class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int>vct;  
        int total=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                vct.push_back(grid[i][j]); 
                total++;
            }
        } 
        sort(vct.begin(),vct.end()); 
        int base = vct[0] % x;
        for (int num : vct) {
            if (num % x != base) return -1; // If remainder is different, return -1
        }  

        int median = vct[vct.size() / 2];

        // Calculate operations required
        int operations = 0;
        for (int num : vct) 
        {
            operations += (abs(num - median) / x);
        }

        return operations;


    }
};