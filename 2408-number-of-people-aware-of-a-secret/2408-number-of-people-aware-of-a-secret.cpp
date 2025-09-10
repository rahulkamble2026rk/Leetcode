class Solution 
{
    static const int MOD=1e9+7; 
    int MAX; 
    vector<int>mem; 
public:  

    int count(int curr,const int& delay, const int& forget)
    {
        if(mem[curr]!=-1)
        {
            return mem[curr];
        }
        int total=(curr+forget-1>=MAX); 

        for(int i=delay;i<forget;i++)
        {
            if(curr+i>MAX)
            {
                break;
            } 
            total=(total+count(curr+i,delay,forget))%MOD;
        } 

        return mem[curr]=total;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        MAX=n; 
        mem.assign(n+1,-1);
        return count(1,delay,forget);
    }  
};