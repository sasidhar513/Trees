#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


#include<iostream>
#include<map>
using namespace std;
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
struct node
{
    int data;
    node* left;
    node* right;
    node *random;
};
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);  
     printInorder(node->right);
}
node * ReadNodes(string s)
{
    map<int ,node *> map1;
    vector<string> ss=split(s,' ');
    vector<int> check;
    vector<int> check1;

    /* node * root=new node;
    stringstream(ss[0])>>(root->data);
    root->right=NULL;
    root->left=NULL;*/
  
    int key=0,key1=0;
    
    //stringstream(ss[0])>>key;
    //check.push_back(key);
    
   // map1[key]=root;
    for ( int i=0;i<ss.size();i=i+3)
    {
        node  *parent ,* child ;
        stringstream(ss[i])>>key;
        stringstream(ss[i+1])>>key1;
        cout<<key<<" "<<key1<<endl;
        if ( find(check1.begin(), check1.end(), key) == check1.end())
        {
            cout<<"ist the key is "<<key<<endl;
            check.push_back(key);
            check1.push_back(key);
        }  
        if ( find(check.begin(), check.end(), key1) != check.end())
        {
            cout<<check.size()<<endl;
           check.erase(remove(check.begin(), check.end(), key1), check.end());
            cout<<"called 2nd if"<<check.size()<<" "<<key1<<endl;
        }
        else
        {
            check1.push_back(key1);
            cout<<"else called"<<endl;
        }
        if(map1.find(key)!=map1.end())
            parent=map1[key];
        else 
        {
            parent=new node;
            parent->data =key;
            parent->right=NULL;
            parent->left=NULL;
            parent->random=NULL;
            map1[key]=parent;
        }
        if (map1.find(key1)!=map1.end())
            child=map1[key1];
        else
        {   
            child=new node;
            child->data=key1;
            child->right=NULL ;
            child->left =NULL;
            child->random=NULL;
            map1[key1]=child;
        }   
            
        if(ss[i+2]=="L")
            map1[key]->left=map1[key1];
        else if (ss[i+2]=="R")
            map1[key]->right =map1[key1];
        else 
            map1[key]->random=map1[key1];
            
    }
    cout<<check.front();
    return NULL;
    
}
int main()
{
    string str ;
    getline(cin,str);
    node * root;
    root=ReadNodes(str);
    //cout<<ss;
    //cout<<root->data;
   printInorder(root );
    
    return 0;
}
