-- Write your query below
select left_operand, operator, right_operand,
case
    when operator = '<' AND lv.value < rv.value then 'true'
    when operator = '>' AND lv.value > rv.value then 'true'
    when operator = '=' AND lv.value = rv.value then 'true'
    else 'false'
end as value
from expressions
join variables lv on lv.name = left_operand
join variables rv on rv.name = right_operand

