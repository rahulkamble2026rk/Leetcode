-- # Write your MySQL query statement below
 
-- select customer_id,count(*) as count_no_trans from Visits join Transactions
--     on Visits.visit_id=Transactions.visit_id
--     where Transactions.visit_id is null 
--     group by customer_id;


SELECT customer_id, COUNT(*) AS count_no_trans FROM Visits LEFT JOIN Transactions 
                    ON Visits .visit_id = Transactions.visit_id 
                    WHERE Transactions.visit_id IS NULL 
                    GROUP BY customer_id