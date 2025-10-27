class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)  
    {
        int n=nums.size();  
         
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i]<0)
            {
                nums[i]=nums[i]*(-1);
            }
         }

        vector<int>vct=nums; 
        sort(vct.begin(),vct.end()); 
        sort(nums.rbegin(),nums.rend());  

        long long sum=0;

        int ind1=0; 
        int ind2=0; 
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(flag==0)
            {
                sum=sum+(nums[ind1]*nums[ind1]); 
                // cout<<nums[ind1]*nums[ind1]<<" is get added from nums"<<endl; 
                // cout<<"Sum is "<<sum<<endl; 
                flag=1; 
                ind1++;
            } 
            else
            {
                sum=sum-(vct[ind2]*vct[ind2]); 
                // cout<<vct[ind2]*vct[ind2]<<" is get subtracted from vct"<<endl; 
                // cout<<"Sum is "<<vct[i]<<endl; 
                flag=0; 
                ind2++;
            }
        }

        return sum;
        
    }
};