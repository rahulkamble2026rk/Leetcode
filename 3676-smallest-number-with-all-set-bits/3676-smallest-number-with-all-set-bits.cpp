class Solution {
public:
    int smallestNumber(int n)  
    {
        //chcek whehter it is fully divided by the 2 or not if not then  
         while(1)
         {  
            
            if(check(n)==true)
            {
                break;
            } 
            n++;
         } 
         return n;
    } 
    bool check(int n)
    {   
        int rem=0;
        while(n>0)
        {
            rem=n%2;  
            if(rem!=1)
            {
                return false;
            }
            n/=2;
        } 

        return (rem==1)?true:false;
    } 

};