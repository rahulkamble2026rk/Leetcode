class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        
        int diff = sum2 - sum1;
        if (diff == 0) return 0;
        
        vector<int> changes;
        for (int num : nums1) {
            changes.push_back(6 - num); 
        }
        for (int num : nums2) {
            changes.push_back(num - 1);
        }
        
        sort(changes.rbegin(), changes.rend()); 
        int operations = 0;
        for (int change : changes) {
            diff -= change;
            operations++;
            if (diff <= 0) {
                return operations;
            }
        }
        
        return -1;
    }
};
