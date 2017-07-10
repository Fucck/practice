#include <stdio.h>

void print(int list[], size_t size){
	for(int i  = 0; i <= size; i++ ){
		printf("%d ", list[i]);
	}
}

void sort(int list[], size_t size){
	if(!list && size == 0){
		return;
	}
	for(int i = 1; i < size; i++){
		if(list[i-1] > list[i]){
			int j = i;
			while(list[j-1] > list[j] && j >= 1){
				list[j-1] = list[j-1] + list[j];
				list[j] = list[j-1] - list[j];
				list[j-1] = list[j-1] - list[j];
				j--;
			}
		}
		printf("step %d: ", i);
		print(list, i);
	}
}

int main(){
	int list[] = {
		5, 4, 232, 31, 6 , 24, 6
	};
	size_t size = sizeof(list)/sizeof(int);
	sort(list, size);
	return 0;
}
