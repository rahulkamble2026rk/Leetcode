class Solution {
public:
    vector<int> parent, depth;

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Initialize parent and depth
        parent.resize(n);
        depth.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Union-Find for connected components
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Store minimum cost for each component
        vector<unsigned int> componentCost(n, -1);
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> answer;
        for (auto& q : query) {
            int start = q[0], end = q[1];

            // If in different components, return -1
            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                int root = find(start);
                answer.push_back(componentCost[root]);
            }
        }
        return answer;
    }

private:
    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int node1, int node2) {
        int root1 = find(node1), root2 = find(node2);
        if (root1 == root2) return;

        if (depth[root1] < depth[root2]) swap(root1, root2);
        parent[root2] = root1;
        if (depth[root1] == depth[root2]) depth[root1]++;
    }
};
