/*************************************************************************
    > File Name: SelectSort.c
    > Author: quanqi
    > Mail: 1025105281@qq.com 
    > Created Time: Mon 10 Jul 2017 09:14:28 AM PDT
 ************************************************************************/

#include<stdio.h>

void SelectSort(int list[], int begin, int end){
	if(!list || begin >= end){
		return;
	}
	int max = list[begin];
	int min = list[begin];
	int max_index = begin;
	int min_index = begin;
	for(int i = begin; i < end; i++){
		if(list[i] > max){
			max = list[i];
			max_index = i;
		}
		if(list[i] < min){
			min = list[i];
			min_index = i;
		}
	}
	list[max_index] = list[end-1];
	list[min_index] = list[begin];
	list[end-1] = max;
	list[begin] = min;

	SelectSort(list, begin+1, end-1);
}

void PrintList(int list[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main(){
	int list[] = {
		3,55,74,1,22,3,33
	};
	int size = sizeof(list)/sizeof(int);
	SelectSort(list, 0, size);
	PrintList(list, size);
	return 0;

	
}
