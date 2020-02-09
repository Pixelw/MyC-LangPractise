#include <stdio.h>
#include <malloc.h>

#define LIST_SIZE 10

typedef int Data;

struct SeqList {
	Data* base;
	int length;
	int size;
};


SeqList initSeqList() {
	int size = LIST_SIZE * sizeof(Data);
	int* base = (int*)malloc(LIST_SIZE * sizeof(Data));
	int length = 0;
	SeqList seqList = { base,length,size };
	return seqList;
}

int insertList(SeqList* list, Data data, int position) {
	if (position < 0 || position > list->length + 1) {
		return -1;
	}


	if (list->length * sizeof(data) >= list->size) {
		int* newBase = (int*)realloc(list->base, (list->size + LIST_SIZE) * sizeof(Data));
		if (!newBase) {
			return -1;
		}
		list->base = newBase;
		list->size += LIST_SIZE;
	}

	Data* p;
	for (p = list->base + list->length - 1; p >= list->base + position; p--) {
		*(p + 1) = *p;
	}

	*(list->base + position) = data;
	list->length++;
	return 0;
}

int main() {

	SeqList* list = &initSeqList();

	//insert <number> times
	for (int number = 1; number <= 99; number++) {
		insertList(list, number, 0);
	}
	insertList(list, 114514, 2);

	//list output
	for (int i = 0; i < list->length; i++) {
		printf("%d\n", *(list->base + i));
	}

}