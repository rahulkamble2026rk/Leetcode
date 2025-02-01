class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int, int>>> adj(n); 
        
        // Step 1: Build the bidirectional adjacency list
        for (auto &conn : connections) 
        {
            int from = conn[0], to = conn[1];
            adj[from].push_back({to, 1});  
            adj[to].push_back({from, 0});  
        }

        
        vector<bool> visited(n, false);
        int count = 0;

        dfs(0, adj, visited, count);
        
        return count;
    }
    
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& count) {
        visited[node] = true;
        
        for (auto &neighbor : adj[node]) 
        {
            int nextNode = neighbor.first;
            int isReversed = neighbor.second;  

            if (!visited[nextNode]) 
            {
                if (isReversed == 1) 
                {
                    count++;  
                }
                dfs(nextNode, adj, visited, count);
            }
        }
    }
};
