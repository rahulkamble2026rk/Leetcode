class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                position[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowcheck(rows, 0);
        vector<int> colcheck(cols, 0);
         
         int ans=0;
        for (int i = 0; i < arr.size(); i++) {
            auto [row, col] = position[arr[i]];
            rowcheck[row]++;
            colcheck[col]++;
            if (rowcheck[row] == cols || colcheck[col] == rows) {
                ans=i; 
                break;
            }
        }

        return ans;
    }
};
