#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
using namespace std;
void gotoxy(int x,int y)
{COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void excess()
{   int i=0;
    char ch;
    cout<<"Enter Username :";
    string uname,pass="";
    cin>>uname;
    cout<<"Enter password :";
    while(1)
    {
     ch=_getch();
     if(ch==ENTER)
     {
         break;
     }
     else if(ch==BKSP)
     {
         if(i>0)
         {
             i--;
             cout<<"\b \b";
         }
     }
     else if(ch==TAB||ch==SPACE)
     {
         continue;
     }
     else
     {
         pass+=ch;
         cout<<"*";
     }
     i++;
    }
    ifstream file("admin.txt");
    if (!file)
    {
       cout << "unable to open file";
       exit(1);
    }
    bool flag=false;
    std::string line;
    std::string email,password;
    while ( std::getline(file,line))
        {
          email=line.substr(0,line.find(' '));
          password=line.substr(line.find(' ')+1);
          if(pass==password&&uname==email)
          {
              flag=true;
              break;
          }
        }
        file.close();
        if(flag)
        {
            gotoxy(43,13);
            cout<<"Loading.....Please wait!!\n";
             gotoxy(43,15);
            for(int i=1;i<=30;i++)
            {

                cout<<(char)178;
                for(int j=0;j<10000000;j++)
                {

                }
            }
            system("cls");
            system("upd.exe");
        }
        else
        {
            cout<<"\nEmail or password is incorrect\n\n";
            system("color 0c");
            cout<<"To retry press r ";
            char r;
            cin>>r;
            if(r=='r')
            {
                system("admin.exe");
            }
        }
}
int main()
{   system("color 4A");
   // system("color 0a");
    excess();
}
