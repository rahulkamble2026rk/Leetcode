class Solution {
public:
    int gcdOfOddEvenSums(int n) 
    {
        int evenSum=0; 
        int oddSum=0;  
        int flagEven=0;  
        int flagOdd=0;
        int i=1; 
        if(n==1) 
        {
            return 1;
        }
       while(flagOdd<n && flagEven<=n)
        {
            if(i%2==0)
            {
                evenSum=evenSum+i; 
                flagEven++;
            } 
            else
            { 
                oddSum=oddSum+i;
                flagOdd++;
            } 
            i++;

        }  


         
         //gcd: i=min(evenSum,oddSum) , and then go upto the 1:  
         i=min(evenSum,oddSum); 
         int k=0;
         for( k=i;k>=1;k--)
         {
            if(evenSum%k==0 && oddSum%k==0)
            {
                break;
            }
         }

        // cout<<"Odd:"<<oddSum<<" "<<"Even: "<<evenSum<<endl;
        // return __gcd(evenSum,oddSum); 
        return k;
    }
};