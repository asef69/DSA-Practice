-- Write your PostgreSQL query statement below
select firstname,lastname,city,state
from person left join address using(personid)