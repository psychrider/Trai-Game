#include<bits/stdc++.h>
#include<string>
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
void delete_key(string key);


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

void delete_key(string key)
{
    struct TrieNode *tr=root;
    tr=search_key(key);
    if(tr!=NULL)
    {
        tr->isLast=false;
        bool isLeaf=true;
       struct TrieNode *parent=NULL;
       for(char i='a';i<='z';i++)
       {
           if(tr->child[i]!=NULL)
           {
               isLeaf=false;
               break;
           }
       }
       while(tr->parent!=NULL&&isLeaf&&!tr->isLast)
       {
           parent=tr->parent;
           for(char i='a';i<='z';i++)
           {
               if(parent->child[i]==tr)
               {
                   parent->child[i]=NULL;
                   delete tr;
                   tr=parent;
               }
               else if(parent->child[i]!=NULL)
               {
                   isLeaf=false;
                   break;
               }
           }
       }
       ifstream file("dict.txt");
       ofstream file1;
       file1.open ("newdic.txt");
       if(!file1)
       {
           cout<<"unable to create a file\n";
           exit(1);
       }
       if (!file)
      {
       cout << "unable to open file";
       exit(1);
      }
       std::string line1;
       std::string word1,meaning1;
       while ( std::getline(file,line1))
        {
          word1=line1.substr(0,line1.find(' '));
          meaning1=line1.substr(line1.find(' ')+1);
          string write;
          if(word1!=key)
          {write=word1+" "+meaning1;
          file1<<write<< endl;}
        }
        file1.close();
        file.close();
        remove("dict.txt");
        std::rename("newdic.txt", "dict.txt");
        cout<<"Word deleted successfully\n";
    }
    else
    {
        cout<<"Word doesn't exist\n";

    }
}
int main()
{   system("color 90");
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
        while(1)
   {

    cout<<"\n\t\t\t\t\t\t1:Insert a new word\n\n\t\t\t\t\t\t2:Delete a existing word\n\n\t\t\t\t\t\t3:Main Window\n\n\t\t\t\t\t\t4:Exit\n\n\t\t\t\t\t\t";
    int choice;
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
           string w,m;
           cout<<"Enter the Word :";
           cin>>w;
           if(search_key(w)!=NULL)
           {
               cout<<"Sorry!!word already exist,try to put another word\n";
               //system("upd.exe");
               break;
           }
           cout<<"Enter the Meaning :";
           cin.ignore();
           getline(cin,m);
           ofstream file;
           file.open ("dict.txt", ios::app);
           if(!file)
           {
               cout<<"Unable to open file\n";
               exit(1);
           }
           file<<endl<<w<<" "<<m;
           cout<<"New word with meaning is appended\n";
           file.close();
           insert(w,m);
           break;
        }
    case 2:
        {
            string del;
            cout<<"Enter the word to be deleted\n";
            cin>>del;
            delete_key(del);
            break;
        }
    case 3:
        {
            system("cls");
            system("mainwindow.exe");
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
            cout<<"Wrong choice";
            break;

        }
    }
    _getch();
    system("cls");
}}
