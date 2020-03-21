#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
     map<char,TrieNode*> child;
     string mean;
    bool isLast;
    TrieNode()
    {
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;
         string mean="";
        isLast = false;
    }
};
void display(string str);
TrieNode *root = NULL;
void mean(string word)
{
    int len=word.length();
    string res="";
    struct TrieNode *itr=root;
    for(int i=0;i<len;i++)
    {
        struct TrieNode *nn=itr->child[word[i]];
        if(nn==NULL)
        {
            cout<<"no such word";
            return;
        }
        res=res+word[i];
        itr=nn;
    }
    if(itr->isLast)
        {   cout<<"Meaning:  ";
            cout<<itr->mean;
        }
    if(!itr->isLast)
    {    int no;
        cout<<"word not found but suggestions available!!! "<<endl;
        cout<<"enter 1 to see suggestions \t";
        cin>>no;
        if(no==1)
        {display(res);}

    }

}
void insert(string s,string m)
{   int len = s.length();
    TrieNode *itr = root;
    for (int i = 0; i < len; i++)
    {
        TrieNode *nextNode = itr->child[s[i]];
        if (nextNode == NULL)
        {
            nextNode = new TrieNode();
            itr->child[s[i]] = nextNode;
        }
        itr = nextNode;
        if (i == len - 1)
           {
              itr->mean=m;
            itr->isLast = true;}
    }
}
void disp(TrieNode *curNode, string prefix)
{
    if (curNode->isLast==true)
        {cout<<prefix<<"   ";
         mean(prefix);
         cout<<endl;
        return;
        }
    for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *nextNode = curNode->child[i];

        if (nextNode != NULL)
            disp(nextNode, prefix + (char)i);
    }
}
void display(string str)
{
    TrieNode *prevNode = root;
    string prefix = "";
    int len = str.length();
    int i;
    for (i=0; i<len; i++)
    {
       prefix += (char)str[i];
        char lastChar = prefix[i];
        TrieNode *curNode = prevNode->child[lastChar];
        if (curNode == NULL)
        {
            cout << "No Results Found for " << prefix
                 << "\n";
            i++;
           break;
        }
        if(prefix==str)
        {cout << "Suggestions based on " << prefix
             << " are \n";
        disp(curNode, prefix);
        }
        prevNode = curNode;
    }
}
void welcome()
{int i,j;
 char wel[100];
 printf("\n\t\t------------------------------------------------------------------------------");
 strcpy(wel,"\t\t\tDICTIONARY");
 printf("\n\t\t\t");
 for(i=0;i<13;i++)
 {
  printf("%c",wel[i]);
  for(j=0;j<50000000;j++)
  {
  }
 }
 printf("\n\t\t------------------------------------------------------------------------------");
 printf("\n\n\n");
}
int main()
{    system("color 4A");welcome();
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
        string x;
        while(1)

        { int z;cout<<"\n\n\t\t\t\t\t\tEnter your choice \n\n\t\t\t\t\t\t 1.Meaning\n\n\t\t\t\t\t\t2.Prefix\n\n\t\t\t\t\t\t3.Main Menu\n\n\t\t\t\t\t\t4.Exit\n\n\t\t\t\t\t\t";
        cin>>z;
          switch(z)
     {

      case 1:
        {cout<<"enter the word to be searched\t";
        cin>>x;
        mean(x);
        break;
        }
      case 2:
        {
            cout<<"enter prefix\t";
            cin>>x;
            display(x);
            break;
        }
      case 4:
        {
            exit(0);
            break;
        }
      case 3:
        {
            system("cls");
            system("mainwindow.exe");
            break;
        }
        }}

return 0;

}
