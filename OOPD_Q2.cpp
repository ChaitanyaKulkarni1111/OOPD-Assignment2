#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;


class Academic {
protected:
    char name[50];
    char designation[50];
    char phoneNumber[20];
    char roomNumber[20];
    char emailAddress[50];
    char department[50];

public:
    Academic(const char* n, const char* des, const char* dept, const char* phone, const char* room, const char* email) {
        strcpy(name, n);
        strcpy(designation, des);
        strcpy(department, dept);
        strcpy(phoneNumber, phone);
        strcpy(roomNumber, room);
        strcpy(emailAddress, email);
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Email Address: " << emailAddress << endl;
    }

    const char* getDepartment() const {
        return department;
    }

    virtual ~Academic() {}
};


class Head : public Academic {
public:
    Head(const char* n, const char* des, const char* dept, const char* phone, const char* room, const char* email)
        : Academic(n, des, dept, phone, room, email) {}

    void display() override {
        cout << "Head of Department:" << endl;
        Academic::display();
    }
};


class Department : public Academic {
public:
    Department(const char* n, const char* des, const char* dept, const char* phone, const char* room, const char* email)
        : Academic(n, des, dept, phone, room, email) {}

    void display() override {
        cout << "Department: " << getDepartment() << endl;
        Academic::display();
    }
};


class CSE : public Department {
public:
    CSE(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "CSE", phone, room, email) {}
};

class ECE : public Department {
public:
    ECE(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "ECE", phone, room, email) {}
};

class CB : public Department {
public:
    CB(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "CB", phone, room, email) {}
};

class Math : public Department {
public:
    Math(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "Math", phone, room, email) {}
};

class HCD : public Department {
public:
    HCD(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "HCD", phone, room, email) {}
};

class SSH : public Department {
public:
    SSH(const char* n, const char* des, const char* phone, const char* room, const char* email)
        : Department(n, des, "SSH", phone, room, email) {}
};


