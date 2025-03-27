#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums)  
    {
        int totalsize = nums.size();  
        map<int, int> stdmap;
        
        // Count occurrences of each element
        for (int num : nums) {
            stdmap[num]++;
        }  
        
        // Find dominant element
        int dominant = -1;
        for (const auto &entry : stdmap) {
            if (entry.second * 2 > totalsize) {
                dominant = entry.first; 
                break;
            }
        }    
        
        if (dominant == -1) {
            return -1;
        }
        
        // Record prefix count of dominant element
        vector<int> record(totalsize, 0);
        int count = 0; 
        for (int i = 0; i < totalsize; i++) {
            if (nums[i] == dominant) {
                count++;
            } 
            record[i] = count;
        } 
        
        // Find the minimum valid split index
        for (int i = 0; i < totalsize - 1; i++) {
            if (split(i, i + 1, totalsize, dominant, record)) {
                return i;
            }
        } 
        
        return -1;      
    } 

    bool split(int i, int j, int total, int x, vector<int>& record) {
        int left_size = i + 1;
        int right_size = total - j;
        
        // Check left subarray dominance
        if (record[i] * 2 <= left_size) {
            return false;
        }
        
        // Check right subarray dominance
        int right_count = record[total - 1] - record[i];
        if (right_count * 2 <= right_size) {
            return false;
        }
        
        return true;
    }
};
