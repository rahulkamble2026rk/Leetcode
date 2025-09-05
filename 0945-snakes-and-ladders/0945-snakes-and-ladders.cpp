#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n * n + 1, -1);
        int idx = 1, dir = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (dir == 1) {
                for (int j = 0; j < n; j++) arr[idx++] = board[i][j];
            } else {
                for (int j = n - 1; j >= 0; j--) arr[idx++] = board[i][j];
            }
            dir *= -1;
        }

        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == n * n) return dist[u];
            for (int dice = 1; dice <= 6 && u + dice <= n * n; dice++) {
                int v = u + dice;
                if (arr[v] != -1) v = arr[v];
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};
