typedef struct ListNode{
	void* data;
	void* next;
} ListNode;

struct ListRoot{
	ListNode* first;
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

int list_add(ListRoot* list, void* element){
	void* ptr = calloc(1, list->blocksize);           if (!ptr) return 1;

	memcpy(ptr + sizeof(ListNode), element, list->elementsize);
	((ListNode*)ptr)->data = ptr + elementsize;
	list->elementcount++;

	if (!list->elementcount)
		list->first = ptr;
	else
		list->last->next = ptr

	list->last = ptr;
}
