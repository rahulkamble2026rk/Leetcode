class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {  
        int n = graph.size();
        vector<vector<int>> adjList(n);  
        vector<int> outdegree(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adjList[it].push_back(i); 
            }
            outdegree[i] = graph[i].size(); 
        }

        queue<int> que; 
   
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                que.push(i);
            }
        }

        // Process nodes in topological order
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            ans.push_back(node); 
            for (auto it : adjList[node]) {
                outdegree[it]--; 
                if (outdegree[it] == 0) {
                    que.push(it); 
                }
            }
        }

        sort(ans.begin(), ans.end()); 
        return ans;
    }
};
