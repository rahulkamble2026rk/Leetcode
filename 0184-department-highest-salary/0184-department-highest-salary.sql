# Write your MySQL query statement below
#we have to find teh employees who have in each department highest salary: 

SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary FROM Employee e JOIN Department d
    ON e.departmentId = d.id
WHERE e.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = e.departmentId
);
