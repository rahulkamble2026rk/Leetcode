class Solution {
public:
    int dfs(vector<int>& arr, unordered_set<int>& s, int x, int y) {
    int next = x + y;
    if (s.find(next) == s.end()) return 0;  // If next number is not present, stop
    return 1 + dfs(arr, s, y, next);
}

int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), maxLen = 0;
    unordered_set<int> s(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int length = 2 + dfs(arr, s, arr[i], arr[j]);
            maxLen = max(maxLen, length);
        }
    }
    return (maxLen >= 3) ? maxLen : 0;
}
};