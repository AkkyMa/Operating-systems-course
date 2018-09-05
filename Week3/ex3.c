#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
} head;

struct List{
	struct Node *head;
	struct Node *tail;
};

void init(struct List *list) {
	list->head = 0;
	list->tail = 0;
}

void print_list(struct List *list) {
	struct Node *node = list->head;
	while(node != 0) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void insert_node(struct List *list, int value) {
	if(list->head == 0) {
		list->head = list->tail = malloc(sizeof(struct Node));
		list->tail->value = value;
		list->tail->next = 0;
		return;
	}
	list->tail->next = malloc(sizeof(struct Node));
	list->tail = list->tail->next;
	list->tail->value = value;
	list->tail->next = 0;
}

void delete_node(struct List *list, int value) {
	struct Node *prevNode = 0;
	struct Node *node = list->head;
	while(node != 0) {
		if(node->value == value) {
			if(prevNode != 0)
				prevNode->next = node->next;
			if(list->head == node)
				list->head = node->next;
			if(list->tail == node)
				list->tail = prevNode;
			free(node);
		}
		prevNode = node;
		node = node->next;
	}
}

int main() {
	struct List *list = malloc(sizeof(struct List));
	init(list);
	insert_node(list, 3);
	insert_node(list, 6);
	insert_node(list, 1);
	print_list(list);
	delete_node(list, 6);
	print_list(list);
	insert_node(list, 5);
	delete_node(list, 3);
	print_list(list);
}
