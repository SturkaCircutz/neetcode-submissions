-- Write your query below
SELECT customer_id, customer_name
FROM customers
where  customer_id in (
    select customer_id from orders where product_name = 'A'
)
AND customer_id  in (
    select customer_id from orders where product_name = 'B'
)
AND customer_id  not in(
    select customer_id from orders where product_name = 'C'
)
order by customer_name