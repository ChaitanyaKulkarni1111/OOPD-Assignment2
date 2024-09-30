#include <iostream>
#include <fstream>
#include <sstream>
#include<cctype>
using namespace std;
const int MAX_PEOPLE=50;
// Person class to hold data for each individual
string lower(string& str) {
    string result;

    for (char c : str) {
        result += tolower(c);
    }

    return result;
}
class Person {
public:
    string name;
    string email;
    string phone;
    string room;
    string position;
    string department;
    int seniority=0;

    Person() = default;

    Person(string n, string e, string p, string r, string pos, string dept)
        : name(n), email(e), phone(p), room(r), position(pos), department(dept) {}

    void displayInfo() const {
        cout << "Name: " << name << "\n"
             << "Email: " << email << "\n"
             << "Phone: " << phone << "\n"
             << "Room: " << room << "\n"
             << "Position: " << position << "\n"
             << "Department: " << department << "\n";
    }
};
class Department {
public:
    string name;
    Person staff[MAX_PEOPLE];  // Static array for staff
    int count;
    int seniority;                // Track the number of staff members

    Department(string deptName) : name(deptName), count(0) {}

    void addPerson(const Person& p) {
        if (count < MAX_PEOPLE) {
            staff[count++] = p;
        } else {
            cerr << "Error: Department " << name << " is full.\n";
        }
    }

    void displayDepartmentInfo() const {
        cout << "Department: " << name << "\n";
        for (int i = 0; i < count; ++i) {
            staff[i].displayInfo();
            cout << "---------------------\n";
        }
    }
    void printEscalationMatrix() const {
        cout << "Escalation matrix for department " << name << endl;
    int day = 0;

    for (int level = 1; level <= 4; ++level) {
        for (int i = 0; i < count && day <= 12; ++i) {
            Person s = staff[i];
            string pos = lower(s.position);

            if (level == 1 && pos.find("officer") != -1) {
                cout << "Officer level Days "<<day <<"-"<<day+3 <<".\n";
                s.displayInfo();
                cout<<"contact for any further information\n\n";
                day+=3;
                break;
            }
            else if (level == 2 && s.position.find("Associate Dean") != -1 ) {
                cout << "Associative Dean level Days"<<day <<"-"<<day+3 <<".\n";
                s.displayInfo();
                cout<<"contact for any further information\n\n";
                day+=3;
                break;
            }
            else if (level == 3 && s.position.find("Dean") != -1 && s.position.find("Associate Dean") == -1) {
                cout << "Dean level Days"<<day <<"-"<<day+3 <<".\n";
                s.displayInfo();
                cout<<"contact for any further information\n\n";
                day+=3;
                break;
            }
            else if (level == 4 && pos.find("registrar") != -1 ) {
                cout << "Officer level Days "<<day <<" onward" <<".\n";
                s.displayInfo();
                cout<<"contact for any further information\n\n";
                day+=3;
                break;
            }
        }
    }
    cout << "---------------------" << endl;
    }
};

// Specialized Department Classes
class IRD : public Department {
public:
    IRD() : Department("IRD") {}
};

class Academic : public Department {
public:
    Academic() : Department("Academic") {}
};

class StudentAffair : public Department {
public:
    StudentAffair() : Department("StudentAffair") {}
};

class Purchase : public Department {
public:
    Purchase() : Department("Purchase") {}
};

class Library : public Department {
public:
    Library() : Department("Library") {}
};

// Base Position class
class Position {
public:
    string title;
    Person members[MAX_PEOPLE];  // Static array for members of this position
    int count;                   // Track the number of people in this position
    int seniority;

    Position(string posTitle, int level) : title(posTitle), seniority(level), count(0) {}

    void addPerson(const Person& p) {
        if (count < MAX_PEOPLE) {
            members[count++] = p;
        } else {
            cerr << "Error: Position " << title << " is full.\n";
        }
    }

    void displayPositionInfo() const {
        cout << "Position: " << title << "\n";
        for (int i = 0; i < count; ++i) {
            members[i].displayInfo();
            cout << "---------------------\n";
        }
    }
};

// Specialized Position Classes
class Dean : public Position {
public:
    Dean() : Position("Dean", 3) {}          // Dean has the highest seniority
};

class AssociateDean : public Position {
public:
    AssociateDean() : Position("Associate Dean", 2) {}   // Associate Dean has medium seniority
};

class Officer : public Position {
public:
    Officer() : Position("Officer", 1) {}    // Officer has the lowest seniority
};

class Registrar : public Position {
public:
    Registrar() : Position("Registrar", 4) {}  // Registrar has the overall highest seniority
    Person get_name(){
        return members[0];
    }
};


// read csv file
int readCSV(string &filename, Person* people, int capacity) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Opening file";
        return -1;
    }
    string line;
    int size = 0;

    getline(file, line);
    while (getline(file, line) && size < capacity) {
        stringstream ss(line);
        string name, email, phone, room, position,department;

        // Read fields from the CSV line
        if (!getline(ss, name, ',') || !getline(ss, email, ',') || !getline(ss, phone, ',') ||
            !getline(ss, room, ',') || !getline(ss, position, ',') || !getline(ss, department, ',')) {
            cerr << "Invalid Data Skipping  this line..\n";
            continue;
        }
        // Create a new Person object and store it in the people array
        people[size++] = Person(name, email, phone, room, position ,department);
    }

    return size;
}


int main() {
    int capacity = 100;
    Person people[capacity];
    string filename = "C:\\Users\\Chaitanya\\Downloads\\Assignment_2\\IIITD(A).csv";

    int personCount = readCSV(filename, people, capacity);

    // If file could not be opened or no people loaded, exit
    if (personCount == -1 || personCount == 0) {
        cerr << "Error: No data available to process.\n";
        return 1;
    }

    // display all people
    // for (int i = 0; i < personCount; ++i) {
    //     cout << "Person " << (i + 1) << ":\n";
    //     people[i].displayInfo();
    //     cout << "---------------------\n";
    // }
    IRD ird;
    Academic academic;
    StudentAffair studentAffair;
    Purchase purchase;
    Library library;

    // Create position objects
    Dean deans;
    AssociateDean associateDeans;
    Registrar registrars;
    Officer officers;

    // Assign people to respective department and position arrays
    for (int i = 0; i < personCount; ++i) {
        Person& person = people[i];
        string dept = lower(person.department);
        string pos = lower(person.position);

        // Assign to position arrays
        if (pos.find("associate dean")!=-1) {
            associateDeans.addPerson(person);

        } else if (pos.find("dean") !=- 1) {
            deans.addPerson(person);

        } else if (pos.find("registrar")!=-1) {
            registrars.addPerson(person);

        } else if (pos.find("officer")!=-1) {
            officers.addPerson(person);

        }
        // Assign to department arrays
        if (dept == "ird") {
            ird.addPerson(person);

        } else if (dept == "academics") {
            academic.addPerson(person);
        } else if (dept == "student affairs") {
            studentAffair.addPerson(person);
        } else if (dept == "purchase") {
            purchase.addPerson(person);
        } else if (dept == "library") {
            library.addPerson(person);
        }


    }
    studentAffair.addPerson(registrars.get_name());
    academic.addPerson(registrars.get_name());
    ird.addPerson(registrars.get_name());
    // Display information for all departments
    // ird.displayDepartmentInfo();
    // academic.displayDepartmentInfo();
    // studentAffair.displayDepartmentInfo();
    // purchase.displayDepartmentInfo();
    // library.displayDepartmentInfo();

    // deans.displayPositionInfo();
    // associateDeans.displayPositionInfo();
    // registrars.displayPositionInfo();
    // officers.displayPositionInfo();

    ird.printEscalationMatrix();
    academic.printEscalationMatrix();
    studentAffair.printEscalationMatrix();
    purchase.printEscalationMatrix();
    library.printEscalationMatrix();

while(true){
    string name;
    cout << "Enter the name of the person: ";
    getline(cin, name);
    //error handling
    for (char c : name) {
        if (!isalpha(c) && c != ' '){
            cerr<<"Invalid Input";
            return -1;
        }
    }
    if (name.empty()) {
        cerr << "Error: No name entered. Please provide a valid name.\n";
        return -1;
    }

    // Search for the person by name
    int match=0;
    for (int i = 0; i < personCount; ++i) {

        if (lower(people[i].name).find(lower(name))!= -1) {
            cout<<match+1<<": "<<people[i].name<<endl;
            match +=1;
        }
        }
        if(match==0){
            cout << "No person found with that name.\n";
            return 0;
        }
        else if(match==1){
            for (int i = 0; i < personCount; ++i) {
            if (lower(people[i].name).find(lower(name))!= -1) {
                people[i].displayInfo();
                return 0;
            }
            }
        }
        else{
            cout<<"Multiple match found Be specific\n";
        }
    }
}
