-- Write your query below
SELECT name from sales_person
where sales_id not in (
    select sales_id from orders o join company  c on c.com_id = o.com_id
    where c.name = 'CRIMSON'
)