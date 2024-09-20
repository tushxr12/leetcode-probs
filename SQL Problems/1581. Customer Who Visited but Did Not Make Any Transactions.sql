# Write your MySQL query statement below
SELECT v.customer_id, COUNT(customer_id) as count_no_trans
FROM Visits v 
Left join Transactions t
on v.visit_id = t.visit_id
where (t.transaction_id is NULL)
group by v.customer_id