# Write your MySQL query statement below

select distinct project_id , round(sum(Employee.experience_years)/count(project_id),2) as average_years  from Project 
join Employee
on Project.employee_id=Employee.employee_id 
group by project.project_id;