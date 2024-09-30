# README

## Descritpion
"This assignment models the administrative and academic structures of IIIT-Delhi using Object-Oriented Programming in C++. It involves creating classes and inheritance for different departments and positions, fetching contact details for individuals, and building an escalation matrix for unresolved complaints. The project also includes a Makefile for compiling the source code."

## Question 1
This program models the administrative structure of IIIT-Delhi by creating classes for the departments and positions. It includes five administrative departments: IRD, Academics, Student Affairs, Store & Purchase, and Library. The program models each department head and their respective positions, such as deans and associate deans. The registrar heads the overall administrative structure. It also provides functionality to fetch room numbers, telephone numbers, and email addresses when given the name of a person.

## Question 2
This program models the structure of academic departments at IIIT-Delhi, where each department consists of a head and four additional faculty members. It creates classes to represent each department and the faculty members, including their roles and responsibilities. The program provides functionality to fetch room numbers and telephone numbers for each faculty member, facilitating easy access to contact information within the academic structure.

## Question 3
- Developed an escalation matrix to handle complaints, allowing issues unresolved for more than three days to be escalated to higher authorities based on the seniority of positions within the departments.

```bash
# Compile the source file for Question1
g++ -c OOPD_Q1.cpp

# Generate the debugging binary
g++ -g -o debug1 OOPD_Q1.o

# Generate the optimized binary
g++ -O3 -o optimize1 OOPD_Q1.o

# Compile the source file for Question2
g++ -c OOPD_Q2.cpp

# Generate the debugging binary
g++ -g -o debug3 OOPD_Q2.o

# Generate the optimized binary
g++ -O3 -o optimize3 OOPD_Q2.o
