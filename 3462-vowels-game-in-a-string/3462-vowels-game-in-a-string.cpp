class Solution {
public:
    bool doesAliceWin(string s)  
    {
        //store: storing the index of the vowels from the string s 

        vector<int>store;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='e' || s[i]=='u')
            {
                store.push_back(i);
            }
        } 

        if(store.size()==0)
        {
            return false;
        } 

          return true;  //beacause in one shot alice will delete the whole 

        

    }
};