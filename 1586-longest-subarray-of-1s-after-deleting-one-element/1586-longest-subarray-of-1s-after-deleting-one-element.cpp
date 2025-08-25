class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        vector<int> store; 
        int n = (int)nums.size();

        // collect indices of zeros
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) store.push_back(i);
        }

        // if no zero, must delete one element
        if (store.empty()) return n - 1;

        // add sentinels to handle edges uniformly
        store.insert(store.begin(), -1);
        store.push_back(n);

        int ans = 0;
        // delete each zero once: sum of 1's run before + after that zero
        for (int j = 1; j + 1 < (int)store.size(); ++j) {
            int leftOnes  = store[j]   - store[j-1] - 1;
            int rightOnes = store[j+1] - store[j]   - 1;
            ans = max(ans, leftOnes + rightOnes);
        }

        return ans;
    }
};
