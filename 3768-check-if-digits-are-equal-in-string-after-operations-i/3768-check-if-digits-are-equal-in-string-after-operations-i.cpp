class Solution {
public:
    bool hasSameDigits(string s)  
    {  
        string temp=s; 
        stack<char>stk; 
        int i=0;
        while (temp.size() > 1) 
        {
             while(i+1<temp.size())
            {
                int x=temp[i]-48; 
                int y=temp[i+1]-48; 
                stk.push((x+y)%10); 
                i++;
            } 
            i=0;  
            string dupli="";
            if(stk.size()>2)
            {   
                while(!stk.empty())
                {
                    dupli+=stk.top(); 
                    stk.pop();
                }  
                reverse(dupli.begin(),dupli.end());
            } 
            else if(stk.size()==2)
            {
                char x1=stk.top(); 
                stk.pop(); 
                char y1=stk.top(); 
                if(x1==y1)
                {
                    return true;
                } 
            } 
            temp=dupli;
        }
        
        return false;
    }
};