class Solution {
public:
    int minDeletions(string s) {
        map<char, int> stdmap;
        
        
        for (int i = 0; i < s.size(); i++) {
            stdmap[s[i]]++;
        }

        
        vector<pair<int, int>> freq;
        for (const auto& i : stdmap) {
            freq.push_back(make_pair(i.second, i.first));  
        }

        // Sort the vector based on frequency (descending order)
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        int deletions = 0;
       
        for (int i = 1; i < freq.size(); i++) 
        {
            if (freq[i].first >= freq[i - 1].first) 
            {
                int new_freq = max(0, freq[i - 1].first - 1);
                deletions += freq[i].first - new_freq;
                freq[i].first = new_freq;
            }
        }

        return deletions;
    }
};
