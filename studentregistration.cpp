#include <iostream>

using namespace std;

struct Student
{
    string name;
    string family;
    int brithday;
    int gender;
    string city;
    string phonnumber;
};

enum Operat
{
    Read = 0,
    Write = 1,
    Search = 2,
    Delete ,
    Modify
};

enum Spec
{
    Name = 0,
    Family = 1,
    Brithday,
    Gender,
    City,
    Phonnum
};

void print(Student s[10], int i)
{
    cout << i << "   " << s[i].name << " " << s[i].family << "\t\t";
    if(s[i].gender)
        cout << " mail \t";
    else
        cout << " fem  ";
    cout << s[i].brithday << "\t\t" << s[i].city << "\t\t" << s[i].phonnumber << endl;
}

void inputInfo(Student s[10], int count)
{
    cout << "Enter name: ";
    cin >> s[count].name;

    cout << "Enter family: ";
    cin >> s[count].family;

    cout << "Enter brithday: ";
    cin >> s[count].brithday;

    cout << "Enter gender (mail 1 and femail 0): ";
    cin >> s[count].gender;

    cout << "Enter city:";
    cin >> s[count].city;

    cout << "Enter phonnumber:";
    cin >> s[count].phonnumber;
}

void read(Student s[10] , int count)
{
    cout << "ID| Name | Family |  Gender  |  Brith  |   City   |  PhonNumber" << endl;
    if(count > 10)
    {
        print(s, count - 11);
    }
    else
    {
        for(int i = 0; i < count; i++){
            print(s, i);
        }
    }
};

int write(Student s[10] ,int count)
{
    inputInfo(s, count);
    count++;

    return count;
};

void search(Student s[10] , int count)
{
    int Spec;
    
    string name;
    string family;
    int brithday = 0;
    int gender = 2;
    string city;
    string phonnumber;

    cout << "This part of the program is for searching." << endl;
    cout << "What information do you have?\n"
    "Enter number 0 from name,\n"
    "Last name, 1\n"
    "Date of birth, 2\n"
    "Gender, 3\n"
    "City, 4\n"
    "Contact number, 5" << endl;
    cin >> Spec;

    if(Spec > 5 || Spec < 0)
        cout << "You entered the input incorrectly." << endl;

    switch (Spec)
    {
    case Name:
        cout << "enter Name: ";
        cin >> name;
    break;
    case Family:
        cout << "enter Last name: ";
        cin >> family;
    break;
    case Brithday:
        cout << "enter Date of birth: ";
        cin >> brithday;
    break;
    case Gender:
        cout << "enter Gender: ";
        cin >> gender;
    break;
    case City:
        cout << "enter City: ";
        cin >> city;
    break;
    case Phonnum:
        cout << "enter Contact number: ";
        cin >> phonnumber;
    break;
    }

    for(int i = 0 ; i < count; i++)
    {
        if(name == s[i].name)
        {
            read(s, i+11);
        }
        else if(family == s[i].family)
        {
            read(s, i+11);
        }
        else if(brithday == s[i].brithday)
        {
            read(s, i+11);
        }
        else if(gender == s[i].gender)
        {
            read(s, i+11);
        }

        else if(city == s[i].city)
        {
            read(s, i+11);
        }
        else if(phonnumber == s[i].phonnumber)
        {
            read(s, i+11);
        }
    }
}

int deleted(Student s[10] ,int count)
{
    std::cout << "Student information deletion section" << std::endl;

    int id_num;
    cout << "Give the user ID number from delete:";
    cin >> id_num;

    for(int i=id_num; i<count ; i++)
    {
        s[i].name       = s[i+1].name;
        s[i].family     = s[i+1].family;
        s[i].brithday   = s[i+1].brithday;
        s[i].gender     = s[i+1].gender;
        s[i].city       = s[i+1].city;
        s[i].phonnumber = s[i+1].phonnumber;
    }
    count--;

    return count;
};

void modify(Student s[10] )
{
    std::cout << "In this section of the program, you can change student details." << std::endl;

    int id_num;
    cout << "Give the user ID number from modify:";
    cin >> id_num;

    inputInfo(s, id_num);
};

int main(){
    cout << "A program for storing student information." << endl;
    Student s[10] = {{"amir","bagloo",1369,1,"zoor","+98936"},
                     {"amin","agha",1386,1,"zoor","+98937"},
                     {"lela","mahmud",1379,0,"hasan","+98990"},
                     {"mads","mosavi",1386,0,"karaj","+98903"},
                    };
    int Operat,
        countiner = 4;
    while(true)
    {
        cout << "Enter 0 to view information,\n"
                "1 to enter information,\n"
                "2 to search in information,\n"
                "3 to delete information,\n"
                "4 to change information,\n"
                "5 to exit from program." << endl;
        cin >> Operat;
        if(Operat == 5)
            break;
        else if(Operat > 5 || Operat < 0)
        {
            cout << "You entered the input incorrectly." << endl;
            continue;
        }
        switch (Operat)
        {
        case Read:
            read(s, countiner);
            break;
        case Write:
            countiner = write(s, countiner);
            break;
        case Search:
            search(s, countiner);
            break;
        case Delete:
            countiner = deleted(s, countiner);
            break;
        case Modify:
            modify(s);
            break;
        }
    }
    return 0;
}
