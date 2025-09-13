class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m)  
    {
         
        int n=arrivals.size(); 
        map<int,int>stdmap; 
        
        int ans=0; 
        vector<int>dis(n,0); 

        for(int i=0;i<w;i++)
        {
            stdmap[arrivals[i]]++; 
            if(stdmap[arrivals[i]] >m)
            {
                ans++; 
                stdmap[arrivals[i]]--; 
                dis[i]=1;
            }
        } 

        for(int i=w;i<n;i++)
        {
            int element=arrivals[i-w];  
            if(dis[i-w]!=1)
            {
                stdmap[element]--;
            }
            stdmap[arrivals[i] ]++; 
            if(stdmap[arrivals[i]] >m)
            {
                ans++; 
                stdmap[arrivals[i]]--; 
                dis[i]=1;
            }

        } 

        return ans;
       
    } 

  
};