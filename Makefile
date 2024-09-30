test1 : 
# Question 1
	g++ -c OOPD_Q1.cpp
	g++ -g -o debug1 OOPD_Q1.cpp
	g++ -O3 -o optimize1 OOPD_Q1.cpp

test2 : 
# Question 2
	g++ -c OOPD_Q2.cpp
	g++ -g -o debug2 OOPD_Q2.cpp
	g++ -O3 -o optimize2 OOPD_Q2.cpp

	test3 : 
# Question 2
	g++ -c OOPD_Q3_Admin.cpp
	g++ -g -o debug2 OOPD_Q3_Admin.cpp
	g++ -O3 -o optimize2 OOPD_Q3_Admin.cpp