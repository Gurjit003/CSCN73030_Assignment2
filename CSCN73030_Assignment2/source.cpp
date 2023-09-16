#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 

using namespace std;

#define PRE_RELEASE       //Definition of the PRE_RELEASE compiler directive 

struct STUDENT_DATA {       //Struct for the 3 types (last name, first name, and email) of student data 
    string firstName;
    string lastName;

    #ifdef PRE_RELEASE      //Email is only needed for PRE_RELEASE compiler directive 
        string email;
    #endif
};


int main()
{
    STUDENT_DATA studentInformation;        //Object to store student data 
    vector <STUDENT_DATA> studentData;      //Vector to store objects 
    string fileName;

    #ifdef PRE_RELEASE 
        fileName = "StudentData_Emails.txt";        //Email for PRE_RELEASE compiler directive 
    #else 
        fileName = "StudentData.txt";               //Email for _DEBUG compiler directive 
    #endif


    ifstream file(fileName);        //Open one of the files 

    if (file.is_open()) {
        #ifdef PRE_RELEASE          //Read last name, first name, and email if PRE_RELEASE compiler directive enabled 
            while (getline(file, studentInformation.lastName, ',') && getline(file, studentInformation.firstName, ',') && getline(file, studentInformation.email)) {
                studentData.push_back(studentInformation);
            }
        #endif 

        #ifdef _DEBUG               //Read last name and first name if _DEBUG compiler directive enabled 
            while (getline(file, studentInformation.lastName, ',') && getline(file, studentInformation.firstName)) {
                studentData.push_back(studentInformation);
            }
        #endif 

        file.close();
    }
    else {
        cout << "Cannot open file: " << fileName << endl;       //If file cannot be opened 
    }


    #ifdef PRE_RELEASE 
        cout << "Pre-Release code running" << endl << endl;           //Text to illustrate which compiler directive is enabled 
    #endif 

    #ifdef _DEBUG   
        cout << "Standard code running" << endl << endl;              //Text to illustrate which compiler directive is enabled 

    #ifdef PRE_RELEASE                                                //If PRE_RELEASE compiler directive is enabled, then print last name, first name, and email 
        for (int i = 0; i < studentData.size(); i++) {
            cout << studentData[i].lastName << "," << studentData[i].firstName << "," << studentData[i].email << endl;
        }
    #else                                                             //If _DEBUG compiler directive is enabled, then print last name and first name 
        for (int i = 0; i < studentData.size(); i++) {
            cout << studentData[i].lastName << "," << studentData[i].firstName << endl;
        }
    #endif 
    #endif 

    return 1;
} 