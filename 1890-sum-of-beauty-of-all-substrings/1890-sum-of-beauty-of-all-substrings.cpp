class Solution {
public: 

    static bool cmp(pair<char,int>p1,pair<char,int>p2)
    {
        return p1.second>p2.second;
    }
    int beautySum(string s)  
    {  
          
        int count=0;
        for(int i=0;i<s.size();i++)
        {    
            map<char,int>stdmap; 
            for(int j=i;j<s.size();j++)
            {   
                 stdmap[s[j]]++;
               
                    // vector<pair<char,int>>vct(stdmap.begin(),stdmap.end());              
                    // sort(vct.begin(),vct.end(),cmp); 
                    // pair<char,int>pt=vct[0]; 
                    // int maxi=pt.second; 
                    // int mini=vct[vct.size()-1].second;  
                    //above code is giving tle that every time form the vector and create the value 

                    int maxi=INT_MIN; 
                    int mini=INT_MAX; 
                    for(const auto it:stdmap)
                    {
                        maxi = max(maxi, it.second);
                       mini = min(mini, it.second);
                    }
                    count += (maxi - mini); 
                   
                
               
            }
        } 

        return count;
    }
};