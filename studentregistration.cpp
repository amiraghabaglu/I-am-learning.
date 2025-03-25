#include <iostream>

using namespace std;

struct Student
{
    char name[20];
    char family[20];
    int brithday;
    bool gender;
    char city[20];
    char phonnumber[15];
};

void read(Student s[10] , int count)
{
  for(int i = 0; i < count; i++)
  {
    cout << "Name: " << s[i].name << "\t";
    cout << "Family: " << s[i].family << "\t";
    if(s[i].gender)
      cout << "Gender: mail" << "\t";
    else
      cout << "Gender: Femail" << "\t";
    cout << "Brithday: " << s[i].brithday << "\t";
    cout << "City: " << s[i].city << "\t";
    cout << "Phonnumber: " << s[i].phonnumber << endl;
  }
};
int write(Student s[10] ,int count = 0)
{
  char n;
  while(count < 10)
  {
    cout << "Enter name:";
    cin >> s[count].name;

    cout << "Enter family:";
    cin >> s[count].family;

    cout << "Enter brithday:";
    cin >> s[count].brithday;

    cout << "Enter gender"
            "(mail 1 and femail 0):";
    cin >> s[count].gender;

    cout << "Enter city:";
    cin >> s[count].city;

    cout << "Enter phonnumber:";
    cin >> s[count].phonnumber;

    count++;

    cout << "Enter 'e' to exit: \n"
            "Enter eny keyword to continue:" << endl;
    cin >> n;
    if(n == 'e')
      break;
  }
  return count;
};

void search(Student s[10] )
{
  std::cout << "Search" << std::endl;
};

void deleted(Student s[10] )
{
  std::cout << "Delete" << std::endl;
};

void modify(Student s[10] )
{
  std::cout << "Modify" << std::endl;
};

enum Operat
{
  Read = 0,
  Write = 1,
  Search = 2,
  Delete ,
  Modify
};

int main()
{
  cout << "A program for storing student"
          " information." << endl;

  Student s[10];
  int Operat,
      countiner = 0;

  while(true)
  {
    cout << "Enter 0 to view information,\n"
        "1 to enter information,\n"
        "2 to search in information,\n"
        "3 to delete information,\n"
        "4 to change information, and\n"
        "5 to exit from program." << endl;
    cin >> Operat;

    if(Operat == 5)
        break;

    else if(Operat > 5 || Operat < 0)
    {
      cout << "You entered the input "
                "incorrectly." << endl;
      continue;
    }
    switch (Operat)
    {
      case Read:
        read(s, countiner);
      break;

      case Write:
        countiner = write(s);
      break;

      case Search:
        search(s);
      break;

      case Delete:
        deleted(s);
      break;

      case Modify:
        modify(s);
      break;
    }
  }
  return 0;
}