#include <iostream>
#include <string>

using namespace std;

class student
{
private:
    string name;
    int rollnumber;
    float marks;

public:
    void inputDetails()
    {
        cout << "Enter student's name:";
        getline(cin, name);
        cout << "Enter roll number : ";
        cin >> rollnumber;
        cout << "Enter marks : ";
        cin >> marks;
    }

    void displayInfo()
    {
        cout << "-----Student Details -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll number: " << rollnumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of Students:" << endl;
    cin >> n;
    student Student[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for the student: " << i + 1 << endl;
        cin.ignore();
        Student[i].inputDetails();
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "\nDisplaying student details: " << i + 1 << endl;
        Student[i].displayInfo();
    }
    return 0;
}