#include <iostream>
#include <string.h>
#include <cstring>
#include <iomanip>

using namespace std;

struct personalinfo{
    char name[50];
    int age;
};

struct student{
    personalinfo info;
    float grade[3];
};

inline void cont(int t=0){
    cout << "\n\n\t\t" ; system("pause"); system("cls");
}

student addStudent(int n){ system("cls");
        student s;
        cout << "\n\t\t---------- ADD STUDENT -----------\n";
        cout << "\n\t\tEnter Student Full Name: ";
        cin.ignore();
        cin.getline(s.info.name, 50);
        cout << "\n\t\tEnter Student Age: ";
        cin >> s.info.age;
        cout << "\n\t\tEnter Student Grade: ";
        cin >> s.grade[0];
    return s;
}

void display(student *s, int n){ system("cls");
    cout << "\t\t---------- STUDENT LIST -----------\n";
    cout << "\t\t" << setw(20) << left << "Name\t" << setw(20) << left << "Age\t" << setw(20) << left << "Grade" << endl;
    for(int i=0; i<n; i++){
        cout << "\t\t" << setw(20) << left << (s+i)->info.name << "\t"
            << setw(20) << left <<  s[i].info.age << "\t"
            << setw(20) << left << (s+i)->grade[0] << endl;
    }
    cont();
}
void search(student *s, int n){ system("cls");
    char value[50]; bool found = false; int c = 0 ;
    cout << "\t\t---------- SEARCH STUDENT -----------\n";
    cout << "\t\tEnter Student name: ";
    cin.ignore();
    cin.getline(value, 50);
    for(int i=0; i<n; i++){
        if( (strncasecmp(value, (s+i)->info.name, (strlen(value)))) == 0){
            c==0? cout << "\n\t\t" << setw(20) << left << "Name\t" << setw(20) << left << " Age\t" << setw(20) << left << "Grade" << endl : cout << "";
            cout << "\t\t" << setw(20) << left << (s+i)->info.name << "\t"
            << setw(20) << left <<  s[i].info.age << "\t"
            << setw(20) << left << (s+i)->grade[0] << endl;
            found = true; c++;
        }
    }
    if (!found) cout << "\n\t\tNo Student Found\n";
    cont();
}

void menu(student s[],int *c){ system("cls");
    int choice; string confirm; int count = 0;

    while(true){
        cout << "\t\t---------- WELCOME -----------\n";
        cout <<  "\t\tMenu: \n\t\t 1.Add student \n\t\t 2.Display \n\t\t 3.Search \n\t\t 0. Exit \n\t\t\t Choose: ";
        cin >> choice;

        switch(choice){
        case 1:
            do{
                s[*c] = addStudent(*c);
                cout << "\n\t\tDo you want to add another user? y/n: ";
                cin >> confirm;
                (*c)++;
            }while(confirm[0] == 'y');
            system("cls");
            break;

        case 2:
            display(s, *c);
            break;

        case 3:
            search(s, *c);
            break;

        case 0:
            exit(0);
            break;

        default:
            break;
        }
    }
}

int main()
{
    student s[100]; int students = 0;
    menu(s, &students);
    return 0;
}
