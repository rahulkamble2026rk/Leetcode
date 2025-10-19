class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;
        // double the length of s for convenience in extracting the rotated
        // string t
        s = s + s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n) {
            vis[i] = 1;
            for (int j = 0; j < 10; j++) {
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) {
                    // before each accumulation, re-truncate t
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};

//even length string , consisiting of 0 to 9 and two integers a and b 

//add a to all odd indieces of s 
//rotate the s by b 
//then we have to return the lexiographically smallest string ,  can obtain by applying the above oprations any number of times on s.
