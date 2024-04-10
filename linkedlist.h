#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node new_linked_list(int val);
Node prepend(Node* node, int val);
void append(Node* node, int val);
Node* last(Node* node);
Node* at(Node* node, size_t pos);
int get(const Node* node, size_t pos);
void insert(Node* node, size_t pos, int val);
int llist_remove(Node* node, size_t pos);
int remove_head(Node* node);
int remove_last(Node* node);
bool find(const Node* node, int val);
size_t len(const Node* node);
void delete_linked_list(Node* node);
int* into_array(const Node* node, size_t* rsize);
Node llist_reverse(Node* node);
void _exit_if_node_null(const Node* node);
bool llist_is_circular(const Node* node);
void llist_make_circular(Node* node);
