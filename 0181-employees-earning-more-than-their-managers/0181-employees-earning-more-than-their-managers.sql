# Write your MySQL query statement below

Select a.name as Employee from Employee as a Join Employee as b on a.ManagerId = b.Id and a.salary>b.salary