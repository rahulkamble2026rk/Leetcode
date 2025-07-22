# Write your MySQL query statement below

select ifnull((select n1.num from MyNumbers as n1 
group by n1.num having 
count(n1.num)=1 
order by num desc  
limit 1),null) as num
