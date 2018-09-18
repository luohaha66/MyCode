#include <iostream>
#include <list>

using namespace std;

struct BTreeNode
{
    int v;
    BTreeNode* left;
    BTreeNode* right;
};

bool BTreeCompare(BTreeNode* b1, BTreeNode* b2)
{
    bool ret = false;

    if( b1 && b2 )
    {
        ret = (b1->v == b2->v) && BTreeCompare(b1->left, b2->left) && BTreeCompare(b1->right, b2->right);
    }

    if( !b1 && !b2 )
    {
        ret = true;
    }

    return ret;
}

bool BTreeCompareEx(BTreeNode* b1, BTreeNode* b2)
{
    bool ret = true;
    list<BTreeNode*> l1;
    list<BTreeNode*> l2;

    l1.push_back(b1);
    l2.push_back(b2);

    while( ret && l1.size() && l2.size() )
    {
        BTreeNode* n1 = l1.front();
        BTreeNode* n2 = l2.front();

        l1.pop_front();
        l2.pop_front();

        if( (n1 != NULL) && (n2 != NULL) )
        {
            ret = (n1->v == n2->v);

            l1.push_back(n1->left);
            l1.push_back(n1->right);

            l2.push_back(n2->left);
            l2.push_back(n2->right);
        }
        else
        if( (n1 == NULL) && (n2 != NULL) )
        {
            ret = false;
        }
        else
        if( (n1 != NULL) && (n2 == NULL) )
        {
            ret = false;
        }
    }

    return ret && (l1.size() == 0) && (l2.size() == 0);
}

int main()
{
    BTreeNode n1[10] = {0};
    BTreeNode n2[10] = {0};

    for(int i=0; i<10; i++)
    {
        n1[i].v = i;
        n2[i].v = i;
    }

    n1[0].left = &n1[1];
    n1[0].right = &n1[2];
    n1[1].left = &n1[3];
    n1[1].right = &n1[4];
    n1[2].left = &n1[5];
    n1[2].right = &n1[6];
    n1[3].left = &n1[7];
    n1[3].right = &n1[8];
    n1[4].left = &n1[9];

    n2[0].left = &n2[1];
    n2[0].right = &n2[2];
    n2[1].left = &n2[3];
    n2[1].right = &n2[4];
    n2[2].left = &n2[5];
    n2[2].right = &n2[6];
    n2[3].left = &n2[7];
    n2[3].right = &n2[8];
    n2[4].left = &n2[9];

    cout<<BTreeCompare(n1, n2)<<endl;
    cout<<BTreeCompareEx(n1, n2)<<endl;
}
