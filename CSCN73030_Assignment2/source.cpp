#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 

using namespace std;

//#define PRE_RELEASE 

struct STUDENT_DATA {
    string firstName;
    string lastName;

#ifdef PRE_RELEASE
    string email;
#endif
};


int main()
{
    STUDENT_DATA studentInformation;

#ifdef PRE_RELEASE 
    cout << endl << endl << "Pre-Release code running" << endl << endl;

    vector <STUDENT_DATA> studentData2;
    ifstream file2("StudentData_Emails.txt");

    while (getline(file2, studentInformation.lastName, ',') && getline(file2, studentInformation.firstName, ',') && getline(file2, studentInformation.email)) {
        studentData2.push_back(studentInformation);
    }

    file2.close();

    for (int i = 0; i < studentData2.size(); i++) {
        cout << studentData2[i].lastName << "," << studentData2[i].firstName << "," << studentData2[i].email << endl;
    }  

#endif 

    return 1;
} 