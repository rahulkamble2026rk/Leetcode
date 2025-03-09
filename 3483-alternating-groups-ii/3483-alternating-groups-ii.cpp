class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        
        int left = 0;
        int right = 1;

        while (right < length) {
            if (colors[right] == colors[right - 1]) {
                // Pattern breaks, reset window from the current position
                left = right;
                right++;
                continue;
            }

            // Expand the window to the right
            right++;

            // Skip counting sequence if its length is less than k
            if (right - left < k) continue;

            // Record a valid sequence and shrink window from the left to search
            // for more
            result++;
            left++;
        }

        return result;
    }
};