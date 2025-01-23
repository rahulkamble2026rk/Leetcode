class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {  
        int n = grid.size(); 
        int m = grid[0].size();
        vector<int> serverrow(n, 0); 
        vector<int> servercol(m, 0); 

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    serverrow[i]++; 
                    servercol[j]++;
                }
            }
        } 

        set<pair<int, int>> st;

        
        for (int i = 0; i < n; i++) {
            if (serverrow[i] >= 2) {
                for (int j = 0; j < m; j++) {   
                    if (grid[i][j] == 1) { 
                        st.insert({i, j});
                    }  
                }
            }
        } 

       
        for (int j = 0; j < m; j++) {
            if (servercol[j] >= 2) {
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] == 1) {
                        st.insert({i, j});
                    }
                }
            }
        } 

        return st.size();
    }
};
