1. --select employees whose salary is company's second max salary
  
        select * 
        from employees 
        where salary = (select max(salary) as second_max_salary
                        from employees
                        where salary < (select max(salary) as first_max_salary
                                        from employees));

2.  -- display the cities having salary less than 25000
        
            select cities.country_id, cities.name, sum(salary) 
            from employees 
            inner join cities on employees.city_id = cities.id
            group by cities.country_id, cities.name
            having sum(salary) < 25000;

3. -- display employees whose salary matching their department's max salary [correlated sub query]
        select parent.name, parent.department_id, parent.salary
        from employees parent
        where parent.salary = (select max(child.salary) 
                            from employees child 
                            where child.department_id = parent.department_id);

 4.  -- display employees whose salary matching their department's second max salary [correlated sub query]
        select parent.* 
        from employees parent 
        where salary = (select max(salary) as second_max_salary
                        from employees 
                        where (department_id = parent.department_id)
                            and (salary < (select max(salary) as first_max_salary
                                        from employees
                                        where (department_id = parent.department_id)
                                        )
                                 ) 
                        );

5. -- country name then city name based total salary sort by country A-Z then by city name Z-A order 
        -- maximum city salary 
  select *  
        from (select 
                countries.name as country_name, 
                cities.name as city_name,  
                sum(employees.salary) as salary 
            from employees 
                inner join cities on employees.city_id = cities.id 
                inner join countries on cities.country_id = countries.id 
            group by countries.name,  cities.name
            order by countries.name Asc, cities.name DESC) city_salaries
        where salary > 8000;


