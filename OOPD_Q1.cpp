#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_LINE_LENGTH = 1024;

class Admin {
protected:
    string name;
    string email;
    string phone;
    string room;
    string designation;
    string department;

public:
    Admin(string n, string e, string p, string r, string d, string dep)
        : name(n), email(e), phone(p), room(r), designation(d), department(dep) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Room: " << room << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department: " << department << endl;
        cout << "-----------------------------------" << endl;
    }

    string getName() const { return name; }
};

class Registrar : public Admin {
public:
    Registrar(string n, string e, string p, string r, string d, string dep)
        : Admin(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Registrar" << endl;
        Admin::displayInfo();
    }
};

class Dean : public Admin {
public:
    Dean(string n, string e, string p, string r, string d, string dep)
        : Admin(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Dean " << endl;
        Admin::displayInfo();
    }
};


class AssociateDean : public Admin {
public:
    AssociateDean(string n, string e, string p, string r, string d, string dep)
        : Admin(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Associate Dean " << endl;
        Admin::displayInfo();
    }
};


class Department : public Admin {
public:
    Department(string n, string e, string p, string r, string d, string dep)
        : Admin(n, e, p, r, d, dep) {}

    virtual void displayInfo() override {
        cout << "Department " << endl;
        Admin::displayInfo();
    }
};


class Academics : public Department {
public:
    Academics(string n, string e, string p, string r, string d, string dep)
        : Department(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Academics " << endl;
        Department::displayInfo();
    }
};

class IRD : public Department {
public:
    IRD(string n, string e, string p, string r, string d, string dep)
        : Department(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "IRD " << endl;
        Department::displayInfo();
    }
};

class Library : public Department {
public:
    Library(string n, string e, string p, string r, string d, string dep)
        : Department(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Library " << endl;
        Department::displayInfo();
    }
};

class StoreAndPurchase : public Department {
public:
    StoreAndPurchase(string n, string e, string p, string r, string d, string dep)
        : Department(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Store and Purchase " << endl;
        Department::displayInfo();
    }
};

class StudentAffairs : public Department {
public:
    StudentAffairs(string n, string e, string p, string r, string d, string dep)
        : Department(n, e, p, r, d, dep) {}

    void displayInfo() override {
        cout << "Student Affairs " << endl;
        Department::displayInfo();
    }
};

