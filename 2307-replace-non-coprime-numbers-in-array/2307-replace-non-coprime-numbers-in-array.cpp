class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st; // use long long to avoid overflow in LCM

        for (int num : nums) {
            long long curr = num;

            // Keep merging with stack top while non-coprime
            while (!st.empty()) {
                long long g = std::gcd(st.top(), curr);
                if (g == 1) break; // coprime → stop merging

                // merge: replace with LCM
                curr = (st.top() / g) * curr; // avoid overflow: (a*b)/gcd
                st.pop();
            }
            st.push(curr);
        }

        // Build result vector from stack
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
