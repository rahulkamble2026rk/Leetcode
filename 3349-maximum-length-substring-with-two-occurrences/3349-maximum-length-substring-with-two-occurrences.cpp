class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        //we have to find such substring such that which containging the most of the characters + at most two  

        int l=0,r=0; 
        int n=s.size(); 
        map<int,int>stdmap; 

   
        int maxi=0;
        while(r<n)
        {   
            stdmap[s[r]]++; //add the new char 
            while(stdmap[s[r]]>2)  //jab tak s[r] ka count less than 2 nahi hota tab tak reduce kare e.g "abcbdb"
            {
                stdmap[s[l]]--; 
                if(stdmap[s[l]] ==0)
                {
                    stdmap.erase(s[l]);
                } 
                l++; 
            } 
            maxi=max(maxi,r-l+1);
            r++;
             
        } 

        return maxi;
    }
};