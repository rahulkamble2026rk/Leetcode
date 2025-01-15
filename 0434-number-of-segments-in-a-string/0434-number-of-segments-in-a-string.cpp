class Solution {
public:
    int countSegments(string s) {
        stack<string> stk;
        string str = "";
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] == ' ') 
            {
                if (!str.empty()) 
                { 
                    stk.push(str);
                    str.clear(); 
                }
            } else {
                 str += s[i];
            }
            i++;
        }
        if (!str.empty()) {
            stk.push(str);
        }

        return stk.size();
    }
};