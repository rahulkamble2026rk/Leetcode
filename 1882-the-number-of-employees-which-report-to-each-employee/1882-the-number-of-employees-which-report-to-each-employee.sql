# Write your MySQL query statement below

select E2.employee_id ,E2.name , count( E2.name) as reports_count ,Round(AVG(E1.age),0) as average_age
from Employees as E1 
join Employees as E2  
on E1.reports_to=E2.employee_id 
group by E2.name,E2.employee_id 
order by employee_id 
