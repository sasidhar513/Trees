/*
This function takes the input from string 
parentNode childNode link
eg:
6 3 L 6 8 R 3 1 L 3 5 R 1 3 X 5 6 X

a) 6 3 L  (Represents that 3 is the left child of 6)
b) 6 8 R (Represents that 8 is the right child of 6)
c) 1 3 X (Represents a random pointer from node 1 to node 3)


*/
node * MakeTreeFromString(string s)
{
    map<int ,node *> map1;
    vector<string> ss=split(s,' ');
    vector<int> check;
    vector<int> check1;
    int key=0,key1=0;
    for ( int i=0;i<ss.size();i=i+3)
    {
        node  *parent ,* child ;
        stringstream(ss[i])>>key;
        stringstream(ss[i+1])>>key1;
        if ( find(check1.begin(), check1.end(), key) == check1.end())
        {
            check.push_back(key);
            check1.push_back(key);
        }
        if ( find(check.begin(), check.end(), key1) != check.end()&&ss[i+2]!="X")
           check.erase(remove(check.begin(), check.end(), key1), check.end());
        if(ss[i+2]!="X")
            check1.push_back(key1);
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
    return map1[check.front()];

}
