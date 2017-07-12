/*************************************************************************
    > File Name: BinaryTreeInit.c
    > Author: quanqi
    > Mail: 1025105281@qq.com 
    > Created Time: Wed 12 Jul 2017 08:33:03 AM PDT
	> Description: init the BinaryTree useing array
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE;


NODE* BinaryTreeInit(int list[],int i, int size){
	if(i > size || !list)
		return NULL;
	if(list[i-1] == 0)
		return NULL;
	NODE* ans = (NODE*) malloc(sizeof(NODE));
	ans->data = list[i-1];
	ans->left = BinaryTreeInit(list, i*2, size);
	ans->right = BinaryTreeInit(list, i*2+1, size);
}

void PreOrder(NODE* head){
	if(!head)
		return;
	printf("%d ", head->data);
	PreOrder(head->left);
	PreOrder(head->right);
}

int main(){
	int list[] = {
		1,2,3,4,5,6,7,8
	};//0代表这个位置没有节点
	int size = sizeof(list)/sizeof(int);
	NODE* head_node = BinaryTreeInit(list, 1, size);
	PreOrder(head_node);
	return 0;
}
