/* Write your PL/SQL query statement below */
SELECT firstName, lastName, city, state
FROM Person NATURAL LEFT JOIN Address;