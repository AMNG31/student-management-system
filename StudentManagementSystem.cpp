#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    int roll_number;
    string name;
    int age;
    double marks;
    void input(){
        cout<<"Enter the roll number of the student: "<<endl;
        cin>>roll_number;
        cout<<"Enter the name of the student: "<<endl;
        cin.ignore();
        getline(cin, name);
        cout<<"Enter the age of the student: "<<endl;
        cin>>age;
        cout<<"Enter the marks of the student out of 100: "<<endl;
        cin>>marks;
        cout<<"Student added!!!"<<endl;
        while (marks < 0 || marks > 100){
            cout<<"Incorrect marks recorded!!"<<endl;
            cout<<"Enter marks again: "<<endl;
            cin>>marks;
        }
    }
    void display(){
        cout<<"\nThe roll number of student is: "<<roll_number<<endl;
        cout<<"The name of student is: "<<name<<endl;
        cout<<"The age of student is: "<<age<<endl;
        cout<<"The marks of student are "<<marks<<" out of 100"<<endl;
    }   
};
int main() {
    cout<<"======================================="<<endl;
    cout<<"       STUDENT MANAGEMENT SYSTEM       "<<endl;
    cout<<"======================================="<<endl;
    vector <Student> students;
    int s;
    cout<<"Enter the size of vector: "<<endl;
    cin>>s;
    for (int i = 0; i < s; i++){
        Student S;
        S.input();
        students.push_back(S);
    }
    cout<<"This is the old data of all the students --->\n";
    for (int i = 0; i < students.size(); i++){
        students[i].display();
    }
    cout<<endl;
    string content[] = {"1. Add Student", "2. Display all students", "3. Search by Roll Number", "4. Update Student", "5. Delete Student", "6. Exit"};
    cout<<"List of Operations is --->\n";
    for (int i = 0; i < 6; i++){
        cout<<content[i]<<endl;
    }
    int op;
    int roll_number;
    string name;
    int age;
    double marks;
    do{
        cout<<"Enter the choice from the list: "<<endl;
        cin>>op;
        Student s1;
        int rn;
        bool found = false;
        switch(op){
            case 1:
            s1.input();
            students.push_back(s1);
            cout<<"A new student is added."<<endl;
            break;
            case 2:
            if (students.size() != 0){
                cout<<"This is the new data of all the students --->\n";
                for (int i = 0; i < students.size(); i++){
                    students[i].display();
                }
            }
            else{
                cout<<"Vector students is empty.\n";
            }
            break;
            case 3:
            cout<<"Enter the roll number you want to search: \n";
            cin>>rn;
            for (int i = 0; i < students.size(); i++){
                if (rn == students[i].roll_number){
                    students[i].display();
                    found = true;
                    break;
                }
            }
            if (!found){
                cout<<"The roll number entered doesn't exist.\n";
            }
            break;
            case 4:
            cout<<"Which roll number you want to update? "<<endl;
            cin>>rn;
            for (int i = 0; i < students.size(); i++){
                if (rn == students[i].roll_number){
                    cout<<"Enter new name: \n";
                    cin.ignore();
                    getline(cin, name);
                    students[i].name = name;
                    cout<<"Enter new age: \n";
                    cin>>age;
                    students[i].age = age;
                    cout<<"Enter new marks: \n";
                    cin>>marks;
                    students[i].marks = marks;
                    cout<<"Data Updated!!\n";
                    found = true;
                    break;
                }
            }
            if (!found){
                cout<<"The roll number entered doesn't exist.\n";
            }
            break;
            case 5:
            cout<<"Which roll number you want to erase? "<<endl;
            cin>>rn;
            for (int i = 0; i < students.size(); i++){
                if (rn == students[i].roll_number){
                    students.erase(students.begin() + i);
                    cout<<"Data Erased!!\n";
                    found = true;
                    break;
                }
            }
            if (!found){
                cout<<"The roll number entered doesn't exist.\n";
            }
            break;
            case 6:
            cout<<"Thank You for using this program!!"<<endl;
            cout<<"---------------------------------------"<<endl;
            break;
            default:
            cout<<"Invalid number. Please enter a number between 1 and 6 as your choice."<<endl;
            break;
        }
    }
        while (op != 6);
        return 0;
}