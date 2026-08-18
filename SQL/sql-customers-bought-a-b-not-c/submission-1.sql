-- Write your query below
select customer_id, customer_name
from customers
where customer_id in(
    select customer_id from orders where product_name = 'A'
)
AND
 customer_id in(
    select  customer_id from orders where product_name = 'B'
)
and  customer_id not in(
    select customer_id from orders where product_name = 'C'
)
order by customer_name