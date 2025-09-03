class Solution {
public:
    static bool cmp(pair<int,int>One,pair<int,int>Two)
    {
        if(One.first>Two.first)
        {
            return false;
        } 
        return true;
    } 
    vector<int> findOriginalArray(vector<int>& changed)  
    {
        
        if(changed.size()%2==1)
        {
            return {};
        }
        map<int,int>stdmap; 
        for(int i=0;i<changed.size();i++)
        {
            stdmap[changed[i]]++; 
        }   
        vector<pair<int,int>>vct(stdmap.begin(),stdmap.end()); 
        sort(vct.begin(),vct.end(),cmp); 
        vector<int>ans; 

        for(int i=0;i<vct.size();i++)
        {
            pair<int,int>temp=vct[i];   
            int element=temp.first;    

            while(stdmap[element]>0)
            {
                int double_num=element*2; 
                if(stdmap.find(double_num)==stdmap.end() || stdmap[double_num]==0)
                {  
                   return {};
                }  
                ans.push_back(element);
                stdmap[element]--; 
                stdmap[double_num]--;
            }
            
        } 
          return ans;
    
    } 


};