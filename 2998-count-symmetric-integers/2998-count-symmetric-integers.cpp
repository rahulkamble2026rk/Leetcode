class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
            int count=0; 
            for(int i=low;i<=high;i++)
            {
                if(countdigit(i))
                {
                    count++;
                } 
               
            } 
            return count;
    } 

    bool  countdigit(int num)
    {  
         int digits[10];
        int count=0; 
        int temp=num; 
        int totalsum=0; 
        while(temp>0)
        {  
            int rem=temp%10;
            temp/=10;   
              digits[count] = rem;
            totalsum+=rem;
            count++;
        }  

        if(count%2==1)
        {
            return false;
        } 
        int sum1=0; 
        int sum2=0;  
        for (int i = 0; i < count / 2; i++) {
            sum1 += digits[i]; // last half
        }

        for (int i = count / 2; i < count; i++) {
            sum2 += digits[i]; // first half
        }

        return sum1 == sum2;
    }
};