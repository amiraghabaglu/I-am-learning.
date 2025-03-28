#include<iostream>
using namespace std;

struct Chart
{
   float physic;
   float chemistre;
   float mathematic;
   float avg()
   {
        return (this->physic + this->chemistre + this->mathematic)/3;
   }
   bool failing()
   {
       return !(avg() > 10);
   }
};

struct Student
{
    string name;
    string family;
    int brithday;
    int gender;
    string city;
    string phonnumber;
    Chart term;
};

struct ClassFunctions
{
  void inputInfo(Student s[10], int count);
  void print(Student s[10], int i);
  void read(Student s[10] , int count);
  int write(Student s[10] ,int count);
  void search(Student s[10] , int count);
  int deleted(Student s[10] ,int count);
  void modify(Student s[10] );
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

int main(){
    cout << "A program for storing student information." << endl;
    
    ClassFunctions cf;
    Student s[10] = {{"amir","bagloo",1369,1,"zoor","+98936",{10,16,14}},
                     {"amin","agha",1386,1,"zoor","+98937",{9,10,10}},
                     {"lela","mahmud",1379,0,"hasan","+98990",{20,18,19}},
                     {"mads","mosavi",1386,0,"karaj","+98903",{18,16,17}},
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
            cf.read(s, countiner);
            break;
  
        case Write:
            countiner = cf.write(s, countiner);
            break;
  
        case Search:
            cf.search(s, countiner);
            break;
  
        case Delete:
            countiner = cf.deleted(s, countiner);
            break;
  
        case Modify:
            cf.modify(s);
            break;
        }
    }
    return 0;
}

void ClassFunctions::inputInfo(Student s[10], int count)
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

    cout << "Enter the math grade:";
    cin >> s[count].term.mathematic;

    cout << "Enter the physic grade:";
    cin >> s[count].term.physic;

    cout << "Enter the chemistre grade:";
    cin >> s[count].term.chemistre;
}

void ClassFunctions::print(Student s[10], int i)
{
  cout << i << "   " << s[i].name << " " << s[i].family << "\t\t";
  if(s[i].gender)
      cout << " mail \t";
  else
      cout << " fem  ";
  cout << s[i].brithday << "\t\t" << s[i].city << "\t\t" << s[i].phonnumber << "\t\t"
       << s[i].term.mathematic << "\t" << s[i].term.chemistre << "\t"
       << s[i].term.physic << "\t" << s[i].term.avg() << "\t";
  if(s[i].term.failing())
      cout << "Student has failed!\t" << endl;
  else
      cout << "Student has passid!\t" << endl;
}

void ClassFunctions::read(Student s[10] , int count)
{
  ClassFunctions cf;
  cout << "ID| Name | Family |  Gender  |  Brith  |   City   |  PhonNumber  |  {math , physic , chem , avg() , failing()}" << endl;
  if(count > 10)
    cf.print(s, count - 11);
  else
    for(int i = 0; i < count; i++)
      cf.print(s, i);
};

int ClassFunctions::write(Student s[10] ,int count)
{
    this->inputInfo(s, count);
    count++;

    return count;
};

void ClassFunctions::search(Student s[10] , int count)
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

int ClassFunctions::deleted(Student s[10] ,int count)
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
        s[i].term.physic = s[i+1].term.physic;
        s[i].term.chemistre = s[i+1].term.chemistre;
        s[i].term.mathematic = s[i+1].term.mathematic;
    }
    count--;

    return count;
};

void ClassFunctions::modify(Student s[10])
{
    std::cout << "In this section of the program, you can change student details." << std::endl;

    int id_num;
    cout << "Give the user ID number from modify:";
    cin >> id_num;

    this->inputInfo(s, id_num);
};