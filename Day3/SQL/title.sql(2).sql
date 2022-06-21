-- sample DB employees 학습
-- Department 부서테이블 조회
select dp.dept_no, dp.dept_name
FROM departments as dp;

select * from dept_manager;
select emp_no, dept_no, from_date, to_date
	FROM dept_manager as dm;
    
-- 합치기 
select dp.dept_no
	  , dp.dept_name
	  , emp_no
      , dept_no
      , from_date
      , to_date
      /*, em.emp_no*/
      DATE_FORMAT(em.birth_date,'%Y년 %m일 %d일') as '생일'
      CONCAT(em.first_name, ' ', em.last_name) as 'full name'
      CASE WITH em.gender = 'F' then '여성'
		   WITH em.gender = 'M' then '남성'
           ELSE '오류' END as '성별'
      
FROM departments as dp
INNER JOIN dept_manager as dm
	ON dp.dept_no = dm.dept_no
INNER JOIN employees as em
	ON em.emp_no = dm.emp_no;
    
-- employees & salaries
SELECT em.emp_no
	, birth_date
    , last_name
    , gender
    , hire_rate
FROM employees as em;

select count(*) from salaries; --
select sum(salary) from salaries; -- 

select sum(salary) from salaries
	group by sl.emp_no;
     
    -- i'm sorry when i fall a sleep at 14:20PM, everything is gone 
    -- too many education to follow up so i lost way 
    -- and also finally i understand C-programming, but MYSQL education begin, so the chance to study it lost :( 
    
    
    
    
    
