class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    { 
        // Step 1: Formation of the Adjacency List
        vector<vector<pair<int, int>>> adjList(n); 
        for (int i = 0; i < roads.size(); i++) {
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]}); 
            adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        } 

        // Step 2: Priority queue and finding the minimum distance to the last node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que; // {dist, endnode}
        vector<long long> distance(n, LLONG_MAX); 
        vector<int> ways(n, 0); 
        int mod = (int)(1e9 + 7);

        distance[0] = 0; 
        ways[0] = 1; 
        que.push({0, 0}); 

        while (!que.empty()) {
            auto it = que.top(); 
            long long dist = it.first; 
            int node = it.second; 

            que.pop(); 

            for (auto it2 : adjList[node]) {
                int adjNode = it2.first; 
                int edgeWeight = it2.second; 

                if (dist + edgeWeight < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWeight; 
                    que.push({distance[adjNode], adjNode}); 
                    ways[adjNode] = ways[node];
                } 
                else if (dist + edgeWeight == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        } 

        return ways[n - 1] % mod; 
    }
};
