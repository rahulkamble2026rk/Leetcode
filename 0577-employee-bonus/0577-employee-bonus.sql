# Write your MySQL query statement below
 

select name,bonus from Employee left join Bonus 
    on Employee.empId=Bonus.empId 
    where Bonus.bonus is null
    or Bonus.bonus<1000;
