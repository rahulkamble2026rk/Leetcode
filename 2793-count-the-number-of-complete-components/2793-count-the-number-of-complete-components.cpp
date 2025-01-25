class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {   
        if(edges.empty()) return n; // If there are no edges, all nodes are disconnected

        vector<int> visited(n, 0); 
        int count = 0;

        // Create adjacency list
        vector<vector<int>> adjList(n); 
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0]; 
            int y = edges[i][1]; 
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        // Traverse all nodes and find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> components; 
                int edgeCount = 0;
                dfs(i, visited, adjList, components, edgeCount); 

                // Check if the component is complete
                int numNodes = components.size();
                if (edgeCount == numNodes * (numNodes - 1) / 2) { 
                    count++;
                }
            }
        } 
        return count;
    } 

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, vector<int>& components, int& edgeCount) {
        visited[node] = 1;   
        components.push_back(node); 

        // Iterate over all adjacent nodes
        for (auto it : adjList[node]) {  
            if (!visited[it]) {
                dfs(it, visited, adjList, components, edgeCount); 
            }
            // Count edges, only count once per undirected edge
            if (node < it) {
                edgeCount++; 
            }
        }
    }
};
