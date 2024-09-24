# Write your MySQL query statement below
SELECT p.project_id, IFNULL(ROUND(SUM(e.experience_years)/COUNT(p.project_id),2), 0) as average_years
FROM Project p 
LEFT JOIN Employee e
ON (e.employee_id = p.employee_id)
GROUP BY p.project_id;