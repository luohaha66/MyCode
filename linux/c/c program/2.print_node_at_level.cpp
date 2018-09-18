#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int v;
    Node* left;
    Node* right;
};

void print_node_at_level(Node* node, int level)
{
    if( node != NULL )
    {
        if( level == 0 )
        {
            cout<<node->v<<" ";
        }
        else
        {
            print_node_at_level(node->left, level-1);
            print_node_at_level(node->right, level-1);
        }
    }
}

void print_node_at_level_ex(Node* node, int level)
{
    if( node != NULL )
    {
        list<Node*> nl;
        list<int> ll;
        
        nl.push_back(node);
        ll.push_back(0);
        
        while( nl.size() > 0 )
        {
            Node* n = nl.front();
            int cl = ll.front();
            
            nl.pop_front();
            ll.pop_front();
            
            if( cl == level )
            {
                cout<<n->v<<" ";
            }
            else if( cl < level )
            {
                if( n->left != NULL )
                {
                    nl.push_back(n->left);
                    ll.push_back(cl+1);
                }
                
                if( n->right != NULL )
                {
                    nl.push_back(n->right);
                    ll.push_back(cl+1);
                }
            }
        }
    }
}

int main()
{
    Node nodes[] =
    {
        {0, NULL, NULL},
        {1, NULL, NULL},
        {2, NULL, NULL},
        {3, NULL, NULL},
        {4, NULL, NULL},
        {5, NULL, NULL},
        {6, NULL, NULL},
        {7, NULL, NULL},
    };
    
    nodes[0].left  = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left  = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[2].left  = &nodes[5];
    nodes[2].right = NULL;
    nodes[4].left  = &nodes[6];
    nodes[4].right = &nodes[7];
    
    print_node_at_level(nodes, 3);
    
    cout<<endl;
    
    //print_node_at_level_ex(nodes, 3);
    
    cout<<endl;
    
    return 0;
}
