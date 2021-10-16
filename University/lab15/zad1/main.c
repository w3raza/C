#include "drzewoBST.h"
#include "drzewoBST.c"

int main(){
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7};
	
	tnode *root=NULL;
	tnode *leaf=NULL;
	
	for(int i=0;i<12;i++)
	{
		AddLeaf(tab[i],&root,leaf);
	}
	printf("-----------\n");
	printf("Preorder:\n");
	showPreorder(root);
	printf("-----------\n");
	printf("Postorder:\n");
	showPostorder(root);

	printf("------\n");
	printf("min: %d\n",min(root));
	printf("------\n");
	printf("max: %d\n",max(root));
	printf("-------\n");

	printf("\nSearchIterative 12: %p \n",SearchIterative(root,12));
	printf("\nSearchRecursive 12: %p \n",SearchRecursive(root,12));

	Left_Rotate(&root, root);

	for(int i = 0; i < 12; i++)
	{
		tnode *n;
		n = SearchIterative(root, tab[i]);

		printf("---------------------------\n");
		printf("tab[%d]: %d\n", i, tab[i]);
		printf("Succesor: %p\n", Succesor(n));
		printf("Predecessor: %p\n", Predecessor(n));
	}
	freeTree(root);
	return 0;
}
