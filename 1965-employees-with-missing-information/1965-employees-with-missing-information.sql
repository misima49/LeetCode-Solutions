# Write your MySQL query statement below
SELECT T.employee_id
FROM 
    (
        SELECT * FROM Salaries LEFT JOIN Employees USING(employee_id)
        UNION
        SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    ) AS T
WHERE T.name IS NULL OR T.salary IS NULL
ORDER BY employee_id ASC;