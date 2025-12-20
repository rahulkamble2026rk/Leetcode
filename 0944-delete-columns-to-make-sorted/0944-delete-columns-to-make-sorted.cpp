class Solution {
public:
    int minDeletionSize(vector<string>& strs)  
    {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            char ch = strs[0][i];
            if (compare(ch, 1, n, strs, i))
            {
                count++;
            }
        }
        return count;
    } 

    bool compare(char ch, int ind, int size, vector<string>& strs, int char_ind)
    {
        for (int i = ind; i < size; i++)
        {
            if (strs[i][char_ind] < ch)
            {
                return true;   // column is NOT sorted → delete
            }
            ch = strs[i][char_ind];
        }
        return false;  // column is sorted
    }
};
