class Solution {
public:
    int maxDifference(string s)  
    {  
        map<char,int>stdmap;
        for(char i:s)
            {
                stdmap[i]++;
            } 

        int maxodd=-1000001; 
        int mineven=100000; 
        for(const auto it:stdmap)
            {
                if(it.second%2==1 && maxodd<it.second)
                {
                    maxodd=it.second;
                } 
                else if(it.second%2==0 && mineven>it.second)
                {
                    mineven=it.second;
                }
            } 

            return maxodd-mineven;
    }
};