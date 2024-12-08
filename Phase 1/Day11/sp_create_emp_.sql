-- Exercise 51:
    -- write stored procedure to get 
    --    employee name, job title, department name, address, city name, country name, 
    --    salary, bonus as input 
    -- if city exist use existing city id otherwise insert 
    -- if country exist use existing country id for city otherwise insert  
    -- if department exist use existing department id other insert 
    -- finally insert into employee 
    --      generate next emmployee id [and city id, country id, department id]


CREATE OR REPLACE PROCEDURE sp_create_employee(
    p_name IN VARCHAR2, 
    p_job_title IN VARCHAR2, 
    p_department_name IN VARCHAR2, 
    p_address IN VARCHAR2, 
    p_city_name IN VARCHAR2, 
    p_country_name IN VARCHAR2, 
    p_salary IN NUMBER, 
    p_bonus IN NUMBER)
AS
    v_country_id number := 1;
    v_city_id number := 1;
    v_department_id number := 1;
    v_employee_id number := 1;

    v_country_count number := 0;
    v_city_count number := 0;
    v_department_count number := 0;

BEGIN
    
    -- read department count
    select count(*) into v_department_count 
    from departments 
    where name = p_department_name;

    -- read country count
    select count(*) into v_country_count
    from countries
    where name = p_country_name;

    -- read city count
    select count(*) into v_city_count
    from cities
    where name = p_city_name;

    savepoint start_transaction;
         if v_department_count >= 1 then
            select id into v_department_id 
            from departments 
            where name = p_department_name;
        else 
            select (nvl(max(id),0) + 1) into v_department_id 
            from departments;

            INSERT INTO departments(id, name)
            VALUES (v_department_id, p_department_name);

            DBMS_OUTPUT.PUT_LINE('Department ' || p_department_name || ' is added');
        end if;

        if v_country_count >= 1 then
            select id into v_country_id 
            from countries 
            where name = p_country_name;
        else 
            select (nvl(max(id),0) + 1) into v_country_id 
            from countries;

            INSERT INTO countries(id, name, ruler)
            VALUES (v_country_id, p_country_name, 'Unknown');

            DBMS_OUTPUT.PUT_LINE('Country ' || p_country_name || ' is added');
        end if;

        if v_city_count >= 1 then
            select id into v_city_id 
            from cities 
            where name = p_city_name;
        else 
            select (nvl(max(id),0) + 1) into v_city_id 
            from cities;

            INSERT INTO cities(id, name, country_id, admin)
            VALUES (v_city_id, p_city_name, v_country_id, 'Unknown');

            DBMS_OUTPUT.PUT_LINE('City ' || p_city_name || ' is added');
        end if;

        select (nvl(max(id),0) + 1) into v_employee_id
        from employees;

        INSERT INTO employees(id, name, job_title, department_id, 
            address, city_id, salary, bonus)
        VALUES (v_employee_id, p_name, p_job_title, v_department_id, 
            p_address, v_city_id, p_salary, p_bonus);
        
        DBMS_OUTPUT.PUT_LINE('Employee ' || p_name || ' is added');
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
       ROLLBACK TO start_transaction;
       DBMS_OUTPUT.PUT_LINE('Error occurred in creating employees: ' || SQLERRM);
END;


-- to call the procedure
-- all existings

call sp_create_employee(
        'Surya', 'Cricketer', 'Cricket', '----', 
        'Banglore', 'Australia', 64000, 50); 

-- country only existing
call sp_create_employee(
        'Hardik', 'Bowler', 'Bowling', '----', 
        'Mysore', 'Australia', 64000, 50);
-- all non existings
call sp_create_employee(
        'Pant', 'Wicket Keepter', 'Wicket Keeping', '----', 
        'Mangalore', 'England', 64000, 50);
