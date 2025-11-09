class Solution {
public:
    int countOperations(int num1, int num2)  
    {
        //In one operation if num1>=num2 , you must subtract num2 from num1 else revers 

        //we have to continue this operation utill the either num1=0 or num2=0 

        int count=0;
        while(num1!=0 && num2!=0)
        {
           if(num1>=num2)
           {
            num1-=num2;
           } 
           else 
           {
            num2-=num1;
           } 
           count++;
        } 

        return count;
    }
};