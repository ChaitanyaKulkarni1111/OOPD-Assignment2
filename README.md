# README

## Descritpion
"This assignment models the administrative and academic structures of IIIT-Delhi using Object-Oriented Programming in C++. It involves creating classes and inheritance for different departments and positions, fetching contact details for individuals, and building an escalation matrix for unresolved complaints. The project also includes a Makefile for compiling the source code."

## Question 1
This program models the administrative structure of IIIT-Delhi by creating classes for the departments and positions. It includes five administrative departments: IRD, Academics, Student Affairs, Store & Purchase, and Library. The program models each department head and their respective positions, such as deans and associate deans. The registrar heads the overall administrative structure. It also provides functionality to fetch room numbers, telephone numbers, and email addresses when given the name of a person.

```bash
# Compile the source file for Question1
g++ -c OOPD_Q1.cpp

# Generate the debugging binary
g++ -g -o debug1 OOPD_Q1.o

# Generate the optimized binary
g++ -O3 -o optimize1 OOPD_Q1.o
