class Solution {
public:
    bool isPowerOfFour(int n)  
    {
    if(n<=0)
    {
          return false;
    }
       if(n==1 || n==4)
       {
        return true;
       }
       return check(n);
    }  
    bool check(int num)
    {
        while(num%4==0)
        {
            num/=4;
        } 
        if(num==1)
        {
            return true; 
        }
        return false;
    }

};