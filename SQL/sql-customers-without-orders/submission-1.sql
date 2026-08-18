-- Write your query below
SELECT c.name from customers c
where c.id not in (SELECT o.customer_id from orders o)