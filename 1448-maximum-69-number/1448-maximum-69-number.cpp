class Solution {
public:
    int maximum69Number (int num)  
    {
        vector<int>store;  
        int temp=num;
        while(temp>0)
        {
            store.push_back(temp%10); 
            temp/=10;
        } 
 reverse(store.begin(),store.end());
        for(int i:store)
        {
            cout<<i<<" ";
        }
        for(int i=0;i<store.size();i++)
        {
            if(store[i]==6)
            {
                store[i]=9; 
                break;
            }
        }  

        cout<<"After the change:"<<endl; 
        for(int i:store)
        {
            cout<<i<<" ";
        }
        int ans=0; 
        int mul=1; 
        reverse(store.begin(),store.end());

        for(int i=0;i<store.size();i++)
        {
            ans=ans+store[i]*mul;
            mul*=10;
        } 
        return ans;
    }
};