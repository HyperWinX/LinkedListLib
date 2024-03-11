typedef struct ListNode{
	void* data;
	void* next;
} ListNode;

struct ListRoot{
	ListNode* head;
	ListNode* last;
	int blocksize;
	int elementsize;
	int elementcount;
};

#include "list.h"

ListRoot* list_new(int elementsize){
	ListRoot* ptr = (ListRoot*)calloc(1, elementsize + sizeof(ListRoot));
	if (!ptr) return 0;
	
	ptr->blocksize = elementsize + sizeof(ListNode);
	ptr->elementsize = elementsize;
	return ptr;
}

int list_traverse(ListRoot* list, int(*action)(void*)){
	ListNode* ptr = list->head;
	while (ptr){
		(*action)((void*)ptr);
		ptr = ptr->next;
	}
}

int list_insert(ListRoot* list, void* element, int index){
	if (index == 0){
		if (list->elementcount == 0){
			void* ptr = calloc(1, list->blocksize);
			if (!ptr) return 1;

			memcpy(ptr + sizeof(ListNode), element, list->elementsize);
			((ListNode*)ptr)->data = ptr + 16;
			list->head = ptr;
			list->elementcount++;
		}
		else{
			void* ptr = calloc(1, list->blocksize);
			if (!ptr) return 0;

			memcpy(ptr + sizeof(ListNode), element, list->elementsize);
			((ListNode*)ptr)->data = ptr + 16
			ptr->next = list->head;
			list->head = ptr;
			list->elementcount++;
		}
	}
	else if (index > 0){
		if (list->elementindex == 0) return 1;
		else if (index == list->elementcount - 1){
			void* ptr = calloc(1, list->blocksize);
			if (!ptr) return 0;

			memcpy(ptr + sizeof(ListNode), element, list->elementsize);
			((ListNode*)ptr)->data = ptr + 16;
			list->last->next = ptr;
			list->last = ptr;
			list->elementcount++;
		}
		else{

		}
	}
}
