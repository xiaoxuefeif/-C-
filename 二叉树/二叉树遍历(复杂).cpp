# include<stdio.h>
# include<stdlib.h> 

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}TNode;


TNode* CreateTree(char* s, int* i)
{
	if(s[*i] == '#')
	{
		(*i)++;                      // 加括号
		return NULL;
	}
	TNode* root = (TNode*)malloc(sizeof(TNode));
	root->val = s[*i];
	(*i)++;
	
	root->left = CreateTree(s, i);
	root->right = CreateTree(s, i);
	
	return root;
	
} 

void InOrder(TNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}


int main()
{
	char s[100];
	scanf("%s", s);
	getchar();
	
	int i = 0;  // 为数组创建 
	TNode* root = CreateTree(s, &i);
	
	InOrder(root);
	
	return 0;	
}
