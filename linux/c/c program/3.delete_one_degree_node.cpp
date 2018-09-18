#include <iostream>

using namespace std;

struct Node
{
    int v;
    Node* left;
    Node* right;
};

void print_div(int p)
{
    for(int i=0; i<p; i++)
    {
        cout<<"-";
    }
}

void print_tree(Node* node, int p)
{
    if( node != NULL )
    {
        print_div(p);
        
        cout<<node->v<<endl;
        
        if( (node->left != NULL) || (node->right != NULL) )
        {
            print_tree(node->left, p+1);
            print_tree(node->right, p+1);
        }
    }
    else
    {
        print_div(p);
        
        cout<<endl;
    }
}

void print_tree(Node* node)
{
    print_tree(node, 0);
}

void delete_one_degree_node(Node*& node)
{
    if( node != NULL )
    {
        if( (node->left != NULL) && (node->right != NULL) )
        {
            delete_one_degree_node(node->left);
            delete_one_degree_node(node->right);
        }
        else if( (node->left != NULL) && (node->right == NULL) )
        {
            node = node->left;
            
            delete_one_degree_node(node);
        }
        else if( (node->left == NULL) && (node->right != NULL) )
        {
            node = node->right;
            
            delete_one_degree_node(node);
        }
    }
}

int main()
{
	Node n[10] = {0};
	Node* tree = n;
	
	for(int i=0; i<10; i++)
	{
	    n[i].v = i;
	}
	
	tree[0].left = &tree[1];
	tree[0].right = &tree[2];
	tree[1].left = &tree[3];
	tree[1].right = &tree[4];
	tree[2].left = NULL;
	tree[2].right = &tree[6];
	tree[3].left = &tree[7];
	tree[3].right = &tree[8];
	tree[4].left = &tree[9];
	
	cout<<"Original:"<<endl;
	
	print_tree(tree);
	
	delete_one_degree_node(tree);
	
	cout<<"After:"<<endl;
	
	print_tree(tree);

    return 0;
}

