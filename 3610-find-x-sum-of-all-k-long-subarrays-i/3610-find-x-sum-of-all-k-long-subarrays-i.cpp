class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)  
    {
        int n = nums.size(); 
        vector<int> store;

        int left = 0;
        int right = k - 1;

        while (right < n)
        {
            int res = check(left, right, nums, x);
            store.push_back(res);
            left++;
            right++;
        }

        return store;
    }

    int check(int start, int end, vector<int>& nums, int x)
    {
        map<int,int> freq;
        for (int i = start; i <= end; i++)
        {
            freq[nums[i]]++;
        }

        vector<pair<int,int>> vct(freq.begin(), freq.end());

        sort(vct.begin(), vct.end(), [&](auto &a, auto &b){
            if (a.second == b.second)
                return a.first > b.first;  // higher value preferred when freq equal
            return a.second > b.second;    // sort by frequency desc
        });

        // keep only top x elements
        int sum = 0;
        int cnt = 0;

        for (auto &p : vct)
        {
            if (cnt == x) break;
            sum += (p.first * p.second);
            cnt++;
        }

        return sum;
    }
};