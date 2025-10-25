class Solution {
public:
    int totalMoney(int n)  
    {
        //Firstly get the numbers of teh rounds , by divide that number: 

        int divide=n/7; //Here you will get the intial summation 

        int rem=n%7; 
        int sum=0; 
        int intial_sum=28;
        for(int i=1;i<=divide;i++)
        {
            sum=sum+intial_sum; 
            intial_sum+=7;
        } 
         
         for(int i=divide+1;i<=divide+rem;i++)
         {
            sum+=i;
         } 
         return sum;
    }
};