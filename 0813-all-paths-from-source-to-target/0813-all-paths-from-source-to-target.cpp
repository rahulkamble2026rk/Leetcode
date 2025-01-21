class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, ans, graph, temp, n - 1);
        return ans;
    }
    void dfs(int node, vector<vector<int>>& ans, vector<vector<int>>& graph,
             vector<int>& temp, int n) {
        temp.push_back(node);
        if (node == n) 
        {
            ans.push_back(temp);
        } 
        else {
            for (auto it : graph[node]) 
            {
                dfs(it, ans, graph, temp, n);
            }
        }
        temp.pop_back();
    }
};