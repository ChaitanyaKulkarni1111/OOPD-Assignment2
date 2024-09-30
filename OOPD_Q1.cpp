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

class AdminManager {
private:
    const char* filePath;

public:
    AdminManager(const char* path) : filePath(path) {}


    void fetchDetailsByName(const string& searchName) {
        ifstream file(filePath);
        if (!file) {
            cout << "Unable to open file: " << filePath << endl;
            return;
        }

        char line[MAX_LINE_LENGTH];

        file.getline(line, MAX_LINE_LENGTH);

        bool found = false;


        while (file.getline(line, MAX_LINE_LENGTH)) {
            char* token = strtok(line, ",");
            string name, email, phone, room, designation, department;


            if (token) name = token;
            token = strtok(NULL, ",");
            if (token) email = token;
            token = strtok(NULL, ",");
            if (token) phone = token;
            token = strtok(NULL, ",");
            if (token) room = token;
            token = strtok(NULL, ",");
            if (token) designation = token;
            token = strtok(NULL, ",");
            if (token) department = token;

            if (name == searchName) {
                if (designation.find("Registrar") != string::npos) {
                    Registrar reg(name, email, phone, room, designation, department);
                    reg.displayInfo();
                } else if (designation.find("Dean") != string::npos) {
                    Dean dean(name, email, phone, room, designation, department);
                    dean.displayInfo();
                } else if (designation.find("Associate Dean") != string::npos) {
                    AssociateDean assocDean(name, email, phone, room, designation, department);
                    assocDean.displayInfo();
                } else {
                    if (department == "Academics") {
                        Academics academics(name, email, phone, room, designation, department);
                        academics.displayInfo();
                    } else if (department == "IRD") {
                        IRD ird(name, email, phone, room, designation, department);
                        ird.displayInfo();
                    } else if (department == "Library") {
                        Library library(name, email, phone, room, designation, department);
                        library.displayInfo();
                    } else if (department == "Store and Purchase") {
                        StoreAndPurchase store(name, email, phone, room, designation, department);
                        store.displayInfo();
                    } else if (department == "Student Affairs") {
                        StudentAffairs studentAffairs(name, email, phone, room, designation, department);
                        studentAffairs.displayInfo();
                    } else {
                        Admin admin(name, email, phone, room, designation, department);
                        admin.displayInfo();
                    }
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No records found for name: " << searchName << endl;
        }

        file.close();
    }
};

int main() {
    const char* filePath = "C:\\Users\\Chaitanya\\Downloads\\Assignment_2\\IIITD(A).csv";
    AdminManager adminManager(filePath);

    string searchName;
    cout << "Enter the name : ";
    getline(cin, searchName);
    adminManager.fetchDetailsByName(searchName);

    return 0;
}
