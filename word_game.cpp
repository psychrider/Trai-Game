#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
struct TrieNode
{
     struct TrieNode *parent;
     map<char,TrieNode*> child;
     string mean;
     bool isLast;
     TrieNode()
     {
         parent=NULL;
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;
         string mean="";
        isLast = false;
     }
};
TrieNode *root = NULL;
struct TrieNode* search_key(string key);

void insert(string s,string m)
{   int len = s.length();
    TrieNode *itr = root;
    for (int i = 0; i < len; i++)
    {
        TrieNode *nextNode = itr->child[s[i]];
        if (nextNode == NULL)
        {
            nextNode = new TrieNode();
            nextNode->parent=itr;
            itr->child[s[i]] = nextNode;
        }
        itr = nextNode;
        if (i == len - 1)
           {
              itr->mean=m;
            itr->isLast = true;}
    }
}

struct TrieNode*search_key(string key)
{
    struct TrieNode *tr=root;
    int i=0;
    while(i<key.length())
    {
        if((tr->child[key[i]])!=NULL)
        {
            tr=tr->child[key[i]];
            i++;
        }
        else
            return NULL;
    }
    return(tr->isLast)?tr:NULL;
}
int main()
{
    system("color 4A");
    cout<<"\t\t--------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t";
    string wel="WORD GAME";
    for(int i=0;i<wel.length();i++)
    {
        cout<<wel[i];
        for(int j=0;j<40000000;j++)
        {
        }
    }
    cout<<"\n\t\t--------------------------------------------------------------------------------------------\n";

    root=new TrieNode;
    ifstream file("dict.txt");
    if (!file)
    {
       cout << "unable to open file";
       exit(1);
    }
    std::string line;
    std::string word,meaning;
    while ( std::getline(file,line))
        {
          word=line.substr(0,line.find(' '));
          meaning=line.substr(line.find(' ')+1);
          insert (word,meaning);
        }
    file.close();
    cout<<"\n\n\t\tRules of the game:\n\t\t1:First to score 5 points will win the game\n\t\t2:Player must enter the correct word starting with last character of \n\t\t\t the word spelled by other player to get +1 point\n\t\t3:If word is spelled wrong or if the word doesn't exist then 1 point will be \n\t\t\t deducted for that player and game will come to end \n\n\n\t\t\t\t\t";
    cout<<"Enter player 1 name :";
    string pl1;
    cin>>pl1;
    cout<<"\n\t\t\t\t\tEnter player 2 name :";
    string pl2;
    cin>>pl2;
    cout<<"\n\t\t\t\t\tPress enter to continue ";
    _getch();
    system("cls");
    int point1=0,point2=0;
    string word1="a";
    bool flag1=true,flag2=true;
    while(1)
    {
        if(flag2)
        {cout<<"\n\t\t\t\t\tPlayer 1,enter a word starting with "<<word1[word1.length()-1]<<endl<<"\n\t\t\t\t\t";
         cin>>word1;
         if(search_key(word1)!=NULL)
         {
            point1++;
            flag1=true;
         }
         else
         {
            flag1=false;
            point1--;
            break;
         }
        }
        if(flag1)
        {
            cout<<"\n\t\t\t\t\tPlayer 2,enter a word starting with "<<word1[word1.length()-1]<<"\n\t\t\t\t\t";
            cin>>word1;
            if(search_key(word1)!=NULL)
            {
            point2++;
            flag2=true;
            }
            else
            {
            flag2=false;
            point2--;
            break;
            }
        }
        cout<<"\n\t\t\t\t\tPlayer1 points:"<<point1<<endl<<"\n\t\t\t\t\tPlayer2 points:"<<point2<<"\n\t\t\t\t\t";
    }
    if(point1>point2)
    {
        cout<<pl1<<",you won by score "<<point1-point2<<endl;
    }
    else if(point2>point1)
    {
        cout<<pl2<<",you won by score "<<point2-point1<<endl;
    }
    else
    {
        cout<<"Match draw\n";
    }
    cout<<"Press 1 to go to main menu else 0 to exit:\n";
    int c;
    cin>>c;
    if(c==1)
    {
        system("cls");
        system("mainwindow.exe");
    }
    else
    {
        exit(1);
    }
    return 0;
}
