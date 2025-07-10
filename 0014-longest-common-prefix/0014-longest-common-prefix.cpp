class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)  
    {
        // Step 1: Find the minimum length string
        string str = strs[0]; 
        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].size() < str.size())
            {
                str = strs[i];
            }
        }

        string ans = "";
        for (int j = 0; j < str.size(); j++)
        {
            char currentChar = str[j];

            // Check if current character at position j matches for all strings
            for (int i = 0; i < strs.size(); i++)
            {
                if (strs[i][j] != currentChar)
                {
                    return ans;
                }
            }

            ans += currentChar;
        }

        return ans;
    }
};
