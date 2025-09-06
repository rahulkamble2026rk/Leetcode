# Write your MySQL query statement below

-- select x , y, z,
-- if(x+y<=z or x+z<=y or y+z<=x ,'No','Yes') as triangle
-- from Triangle 


select x,y,z,
case 
    when (x+y<=z or y+z<=x or x+z<=y)
    then 'No' 
    else 'Yes' 
end as triangle
from Triangle


-- \U0001f50e What is CASE in SQL?

-- CASE in SQL is like if-else logic in programming (C, Java, Python).
-- It lets you check conditions and return different values depending on the result.

-- It’s most often used in SELECT queries to add calculated columns, or in UPDATE statements to conditionally update values.





-- CASE
--     WHEN condition1 THEN result1
--     WHEN condition2 THEN result2
--     ...
--     ELSE default_result
-- END



-- SELECT 
--     student_id,
--     marks,
--     CASE
--         WHEN marks >= 90 THEN 'A'
--         WHEN marks >= 75 THEN 'B'
--         WHEN marks >= 60 THEN 'C'
--         ELSE 'Fail'
--     END AS grade
-- FROM Students;


-- +------------+-------+-------+
-- | student_id | marks | grade |
-- +------------+-------+-------+
-- | 1          | 95    | A     |
-- | 2          | 80    | B     |
-- | 3          | 65    | C     |
-- | 4          | 40    | Fail  |
-- +------------+-------+-------+


-- SELECT 
--     x, y, z,
--     CASE
--         WHEN (x + y <= z OR x + z <= y OR y + z <= x) 
--              THEN 'No'
--         ELSE 'Yes'
--     END AS can_form_triangle
-- FROM Triangles;

