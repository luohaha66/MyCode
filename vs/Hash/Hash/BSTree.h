#ifndef _BSTREE_H_
#define _BSTREE_H_

typedef void BSTree;
typedef void BSKey;

typedef struct _tag_BSTreeNode BSTreeNode;
struct _tag_BSTreeNode
{
    BSKey* key;
    BSTreeNode* left;
    BSTreeNode* right;
};

typedef void (BSTree_Printf)(BSTreeNode*);
typedef int (BSTree_Compare)(BSKey*, BSKey*);

BSTree* BSTree_Create();

void BSTree_Destroy(BSTree* tree);

void BSTree_Clear(BSTree* tree);

int BSTree_Insert(BSTree* tree, BSTreeNode* node, BSTree_Compare* compare);

BSTreeNode* BSTree_Delete(BSTree* tree, BSKey* key, BSTree_Compare* compare);

BSTreeNode* BSTree_Get(BSTree* tree, BSKey* key, BSTree_Compare* compare);

BSTreeNode* BSTree_Root(BSTree* tree);

int BSTree_Height(BSTree* tree);

int BSTree_Count(BSTree* tree);

int BSTree_Degree(BSTree* tree);

void BSTree_Display(BSTree* tree, BSTree_Printf* pFunc, int gap, char div);

#endif

