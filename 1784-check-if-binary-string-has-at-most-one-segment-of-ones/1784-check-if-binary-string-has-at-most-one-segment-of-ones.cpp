class Solution {
public:
    bool checkOnesSegment(string s)  
    {
        //we have to check if the string has at most one continu segment of ones  
        //manje sagle one ekach line madhe ekdach ale pahije jar tutak tutak nakoat

        int ind=0; 
        vector<int>vct;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                vct.push_back(i);
            }
            
        } 

        //check if the vector indexes is diff. than 1 then return false; 
        int i=1;
        for(i=1;i<vct.size();)
        {
            if(vct[i]-vct[i-1]!=1)
            {
                return false;
            } 
            else if(vct[i]-vct[i-1]==1)
            {
                i++;
            }
        } 

        if(i==vct.size())
        {
            return true;
        } 
        return false;

        
    }
};