class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;

        // Continue until the array becomes sorted
        while (!is_sorted(nums.begin(), nums.end())) {
            int n = nums.size();
            vector<pair<int, int>> record; // {sum, index}

            // Rebuild record of all adjacent pair sums
            for (int i = 0; i < n - 1; ++i) {
                record.push_back({nums[i] + nums[i + 1], i});
            }

            // Sort to get the leftmost minimum-sum pair
            sort(record.begin(), record.end());

            int idx = record[0].second;

            // Merge nums[idx] and nums[idx + 1] by replacing them with their sum
            int sum = nums[idx] + nums[idx + 1];
            nums[idx] = sum;
            nums.erase(nums.begin() + idx + 1);

            steps++;
        }

        return steps;
    }
};
