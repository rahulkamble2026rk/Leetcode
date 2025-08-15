# Write your MySQL query statement below
select Customers.name as Customers FROM Customers left join Orders 
on Customers.id=Orders.customerId 
where Orders.customerId Is NULL