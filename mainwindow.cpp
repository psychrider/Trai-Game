#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void welcome()
{   system("color B0");
    string wel="DICTIONARY PROJECT";
    for(int i=0;i<wel.length();i++)
    {
        cout<<wel[i];
        for(int j=0;j<40000000;j++)
        {
        }
    }
}
void menu()
{
    int k;
    cout<<"\n\n\t\t\t\t\t\t";
    cout<<"1:Admin login";
    cout<<"\n\n\t\t\t\t\t\t";
    cout<<"2:Dictionary\n\n\t\t\t\t\t\t3:Word Game\n\n\t\t\t\t\t\t4:Exit\n\n\t\t\t\t\t\tEnter your choice :";
    cin>>k;
    switch(k)
    {
    case 1:
        {
            system("cls");
            system("admin.exe");
            break;
        }
    case 2:
        {
            system("cls");
            system("pro.exe");
            break;
        }
    case 3:
        {
            system("cls");
            system("word_game.exe");
            break;
        }
    case 4:
        {
            exit(0);
            break;
        }
    default :
        {
            system("color 0c");
            cout<<"\n\n\t\t\t\t\t\tWrong choice!!!";
            _getch();
            system("cls");
            system("mainwindow.exe");
        }
    }
}
int main()
{
    cout<<"\t\t--------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t";
    welcome();
    cout<<"\n\t\t--------------------------------------------------------------------------------------------\n";
    menu();
}
