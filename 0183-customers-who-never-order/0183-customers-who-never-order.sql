# Write your MySQL query statement below

Select a.name as Customers from Customers as a where a.id not in (
select customerid from orders
);