class Solution {
public:
    bool checkValidString(string s) 
    {
        //by using the parsing 
        int open=0,close=0,star=0; 
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                star++;
            } 
            else if(s[i]=='(')
            {
                open++;
            } 
            else if(s[i]==')')
            {
                close++;
            } 
            if(star+open<close)
            {
                return false;
            }
        } 

        open=0,close=0,star=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='*')
            {
                star++;
            } 
            else if(s[i]=='(')
            {
                open++;
            } 
            else if(s[i]==')')
            {
                close++;
            } 
            if(close+star<open)
            {
                return false;
            }
        } 
        return true;
    }
};