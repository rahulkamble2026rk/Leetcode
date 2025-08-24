class Solution {
public:
    int gcdOfOddEvenSums(int n) 
    {
        int evenSum=0; 
        int oddSum=0;  
        int flagEven=0;  
        int flagOdd=0;
        int i=1;
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




        cout<<"Odd:"<<oddSum<<" "<<"Even: "<<evenSum<<endl;
        return __gcd(evenSum,oddSum);
    }
};