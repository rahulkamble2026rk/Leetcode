class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string res;  
        stack<int>stk;
        while(columnNumber>26)
        {
            int rem=columnNumber%26;  
            if(rem==0)
            {
                stk.push(26); 
                columnNumber=(columnNumber/26)-1;
            } 
            else 
            {
             stk.push(rem);  
              columnNumber=columnNumber/26;
            }
            
        } 
        stk.push(columnNumber);
        while(!stk.empty())
        {    
            cout<<stk.top()<<endl;
            res+=(char)(64+stk.top());

            stk.pop();
        } 
        return res;
    }
};