class Solution {
public:
    int sumFourDivisors(vector<int>& nums)  
    {
        // we have to return the sum of integers , that hasve eaxactly four divisiors  

        // I think we have must to iterate upto the square is less than number: 

        int sum=0;
        for(int i=0;i<nums.size();i++)
        {   
            cout<<"For "<<nums[i]<<endl;
            int result=check(nums[i]);  
            cout<<nums[i]<<" sum is : "<<result<<endl;

            if(result!=-9999)
            {
                sum+=result;
            }
        } 
        return sum;

    } 

    int check(int num)
    {   
        set<int>vct;

        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {  
                cout<<i<<" & "<<num/i<<endl;
                vct.insert(i); 
                vct.insert(num/i);
            }
        } 
    
        if(vct.size()==4)
        {
            return accumulate(vct.begin(),vct.end(),0);
        } 
        return -9999;
    }
};