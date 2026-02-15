#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student()
    {
        name = "";
        age = 0;
    }

    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void printStudentInfo()
    {
        cout << "Student " << name << " Age " << age << endl;
    }
};

int main()
{
    int selection = 0;
    vector<Student> studentList;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection)
        {
            case 0:
            {
                string name;
                int age;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter student age: ";
                cin >> age;

                Student newStudent(name, age);
                studentList.push_back(newStudent);
                break;
            }

            case 1:
            {
                for (int i = 0; i < studentList.size(); i++)
                {
                    studentList[i].printStudentInfo();
                }
                break;
            }

            case 2:
            {
                for (int i = 0; i < studentList.size() - 1; i++)
                {
                    for (int j = i + 1; j < studentList.size(); j++)
                    {
                        if (studentList[i].getName() > studentList[j].getName())
                        {
                            Student temp = studentList[i];
                            studentList[i] = studentList[j];
                            studentList[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < studentList.size(); i++)
                {
                    studentList[i].printStudentInfo();
                }
                break;
            }

            case 3:
            {
                for (int i = 0; i < studentList.size() - 1; i++)
                {
                    for (int j = i + 1; j < studentList.size(); j++)
                    {
                        if (studentList[i].getAge() > studentList[j].getAge())
                        {
                            Student temp = studentList[i];
                            studentList[i] = studentList[j];
                            studentList[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < studentList.size(); i++)
                {
                    studentList[i].printStudentInfo();
                }
                break;
            }

            case 4:
            {
                string searchName;
                cout << "Student to be found name = ?" << endl;
                cin.ignore();
                getline(cin, searchName);

                bool found = false;
                for (int i = 0; i < studentList.size(); i++)
                {
                    if (studentList[i].getName() == searchName)
                    {
                        cout << "Student found:" << endl;
                        studentList[i].printStudentInfo();
                        found = true;
                        break;
                    }
                }

                if (found == false)
                {
                    cout << "Student not found." << endl;
                }
                break;
            }

            default:
                cout << "Wrong selection" << endl;
                break;
        }

    } while (selection >= 0 or selection < 5);

    return 0;
}
