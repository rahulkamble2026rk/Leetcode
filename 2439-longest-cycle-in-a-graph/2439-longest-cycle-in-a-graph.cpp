class Solution {
public:
    int ans = -1;
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> depth(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, edges, visited, depth, 0);
            }
        }
        return ans;
    }
    void dfs(int node, vector<int>& edges, vector<int>& visited, vector<int>& depth, int d) {
        if (node == -1) return;

        if (visited[node] == 0) { 
            visited[node] = 1;   // mark as visiting
            depth[node] = d;

            dfs(edges[node], edges, visited, depth, d + 1);

            visited[node] = 2;   // mark as fully processed
        } 
        else if (visited[node] == 1) {
            // found a cycle
            ans = max(ans, d - depth[node]);
        }
        // if visited[node] == 2 → already processed, ignore
    }

};