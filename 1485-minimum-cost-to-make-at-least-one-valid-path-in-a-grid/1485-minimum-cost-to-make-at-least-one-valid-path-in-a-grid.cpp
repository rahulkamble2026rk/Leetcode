class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        pq.push({0,0,0});

        result[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(result[i][j] < currCost) continue;
            int k = 0;
            for(auto it : dir){
                int i_ = i + it[0];
                int j_ = j + it[1];

                if(i_ >= 0 && j_ >= 0 && i_ <m && j_ < n){
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir-1 != k) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < result[i_][j_]){
                        result[i_][j_] = newCost;
                        pq.push({newCost,i_,j_});
                    }
                }
                k++;
            }
        }

        return result[m-1][n-1];
    }
};