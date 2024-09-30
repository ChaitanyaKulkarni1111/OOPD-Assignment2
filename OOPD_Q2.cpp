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

class Manage {
private:
    Academic* academics[100];
    int count;

public:
    Manage() : count(0) {}

    void addAcademic(Academic* academic) {
        if (count < 100) {
            academics[count++] = academic;
        } else {
            cout << "Cannot add more academics. List is full." << endl;
        }
    }

    void displayAll() {
        for (int i = 0; i < count; ++i) {
            academics[i]->display();
            cout << "-----------------------------" << endl;
        }
    }

    void displayByDepartment(const char* dept) {
        cout << "Academics in " << dept << " Department:" << endl;
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcasecmp(academics[i]->getDepartment(), dept) == 0) {
                academics[i]->display();
                cout << "-----------------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No academics found in the " << dept << " Department." << endl;
        }
    }
};


Academic* createAcademic(const char* name, const char* dept, const char* designation, const char* phone, const char* room, const char* email) {
    if (strcmp(designation, "Head") == 0) {
        return new Head(name, designation, dept, phone, room, email);
    }
    else if (strcmp(dept, "CSE") == 0) {
        return new CSE(name, designation, phone, room, email);
    }
    else if (strcmp(dept, "ECE") == 0) {
        return new ECE(name, designation, phone, room, email);
    }
    else if (strcmp(dept, "CB") == 0) {
        return new CB(name, designation, phone, room, email);
    }
    else if (strcmp(dept, "Math") == 0) {
        return new Math(name, designation, phone, room, email);
    }
    else if (strcmp(dept, "HCD") == 0) {
        return new HCD(name, designation, phone, room, email);
    }
    else if (strcmp(dept, "SSH") == 0) {
        return new SSH(name, designation, phone, room, email);
    }
    else {
        return new Academic(name, designation, dept, phone, room, email);
    }
}


int readCSV(const char* fileName, Manage& manager) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Could not open file " << fileName << endl;
        return 0;
    }

    char line[256];
    int count = 0;

    file.getline(line, 256);

    while (file.getline(line, 256)) {

        char name[50], dept[10], designation[50], phone[20], room[20], email[50];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", name, dept, designation, phone, room, email);


        manager.addAcademic(createAcademic(name, dept, designation, phone, room, email));

        count++;
    }

    file.close();
    return count;
}


void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


bool isValidString(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int main() {

    Manage manager;


    readCSV("C:\\Users\\Chaitanya\\Downloads\\Assignment_2\\IIITD(D).csv", manager);


    char departmentName[50];
    bool validInput = false;

    while (!validInput) {
        cout << "Enter the department name to get the faculty : ";
        cin.getline(departmentName, 50);


        toLowerCase(departmentName);


        if (!isValidString(departmentName)) {
            cout << "Error: Invalid input. Please enter a valid department name containing only letters." << endl;
        } else {
            validInput = true;
        }
    }

    manager.displayByDepartment(departmentName);
    return 0;
}

