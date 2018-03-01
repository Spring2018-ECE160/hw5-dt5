## Question 5

(K&R Exercise 5-8) There is no error checking in <code>day_of_year</code> or <code>month_day</code>. Remedy this defect and verify that all of the cases are covered with examples.

Compile Steps:
`make`  
Output:
```
./question5 
day_of_year(1998, 3, 27) = 86
day_of_year(-2, 10, 10) = -1
day_of_year(10, 13, 2) = -1
Day 172 of year 1998 is 6/21
Day 13 of year -1 is invalid input
Day 366 of year 2012 is 12/31
```
