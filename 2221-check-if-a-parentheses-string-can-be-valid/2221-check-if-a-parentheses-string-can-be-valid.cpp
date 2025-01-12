class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        if(s.size()%2)   //if the odd size is of the string then valid parenthiss is not possible
        {
            return false;
        }  

        //TO checking the validness we have to se the parse tecnhiq; 
        //parse 1:left->right:(wildcard+opening>=closing) 

        int opening=0,closing=0,wildcard=0; 
        for(int i=0;i<locked.size();i++)
        {
            if(locked[i]=='0')
            {
                wildcard++;
            } 
            else if(s[i]=='(')
            {
                opening++;
            } 
            else if(s[i]==')')
            {
                closing++;
            } 
            if(wildcard+opening<closing)
            {
                return false;
            }
        } 

        //parse2:right->left(wildcard+closing>=opening) 
  
          opening=0,closing=0,wildcard=0;
        for(int i=locked.size()-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                wildcard++;
            } 
            else if(s[i]=='(')
            {
                opening++; 
            } 
            else if(s[i]==')')
            {
                closing++;
            } 
            if(wildcard+closing<opening)
            {
                return false;
            }
        } 
        return true;
        
        
    }
};