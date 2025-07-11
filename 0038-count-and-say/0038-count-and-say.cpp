class Solution {
public:
    string countAndSay(int n)  
    {
        if(n==1)
        {
            return "1";
        } 

        string str="1";
        for(int i=2;i<=n;i++)
        {
            str=count_check(str);
        } 
        return str;
    } 

    string count_check(string str)
    {
        string ans="";  
        int count=1;
        for (int i = 1; i <= str.size(); i++) {
            if (i < str.size() && str[i] == str[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += str[i - 1];
                count = 1;
            }
        } 

        return ans;
    }
};