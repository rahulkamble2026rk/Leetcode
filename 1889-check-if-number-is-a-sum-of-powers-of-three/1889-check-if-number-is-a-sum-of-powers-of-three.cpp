class Solution {
public:
    bool checkPowersOfThree(int n)  
    {
        vector<int>vct; 
        for(int i=1;i<=(1e7+3);i*=3)
        {
                vct.push_back(i); 
        } 

        //  for(auto &i:vct)
        // {
        //         cout<<i<<endl;
        // }   
        int size=vct.size();
        return findoccurance(vct,n,size-1);
       
    }  
    bool findoccurance(vector<int>vct,int target,int ind)
    {   
        if(target==0)
        {
            return true;
        } 
        
        if(ind==0) 
        {
            if(vct[ind]==target)
            {
                return true;
            } 
            else
            {
                return false;
            }
        } 
        
        bool nottake=findoccurance(vct,target,ind-1); 
        bool  take=false; 
        if(target>=vct[ind])
        { 
            cout<<"I am in"<<vct[ind]<<endl;
            take=findoccurance(vct,target-vct[ind],ind-1); 
            
        } 
        return (take||nottake);
    }
   
};