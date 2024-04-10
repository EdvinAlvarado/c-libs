#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node new_linked_list(int val) {
	Node ret = {.data = val, .next = NULL};
	return ret;
}

void _exit_if_node_null(const Node* node) {
	if (node == NULL) {
		fprintf(stderr, "node pointer is null.\n");
		exit(EXIT_FAILURE);
	}
}

Node prepend(Node* node, int val) {
	_exit_if_node_null(node);
	Node ret = {.data = val, .next = node};
	return ret;
}

void append(Node* node, int val) {
	_exit_if_node_null(node);
	Node* end = last(node);
	Node new_node = new_linked_list(val);
	end->next = &new_node;
}

Node* last(Node* node) {
	_exit_if_node_null(node);
	Node* check = node;
	while (check->next != NULL) {
		check = check->next;
	}
	return check;
}

Node* at(Node* node, size_t pos) {
	_exit_if_node_null(node);
	size_t n = pos;
	Node* walk = node;
	while (n-- != 0) {
		if (walk == NULL) {break;}
		walk = walk->next;
	}
	return walk;
}


int get(const Node* node, size_t pos) {
	_exit_if_node_null(node);
	const Node* node_at = at(node, pos);
	if (node_at == NULL) {
		fprintf(stderr, "linked list is not long enough.\n");
		exit(EXIT_FAILURE);
	}
	return node_at->data;
}

Node* _at_before(Node* node, size_t pos) {
	_exit_if_node_null(node);
	Node* left;
	if (pos == 0) {
		left = node;
	}
	else {
		left = at(node, pos-1);
	}
	
	_exit_if_node_null(left);
	return left;
}

void insert(Node* node, size_t pos, int val) {
	_exit_if_node_null(node);
	Node* left = _at_before(node, pos);
	Node* right = left->next;
	Node middle = new_linked_list(val);
	middle.next = right;
	left->next = &middle;
}


int llist_remove(Node* node, size_t pos) {
	_exit_if_node_null(node);
	Node* left = _at_before(node, pos);
	Node* middle = at(node, pos);
	Node* right = middle->next;
	
	int ret = middle->data;
	free(middle);
	left->next = right;
	return ret;
}

int remove_head(Node* node) {
	_exit_if_node_null(node);
	Node* head = node;
	int ret = head->data;
	node = node->next;
	return ret;
}

int remove_last(Node* node) {
	_exit_if_node_null(node);
	Node* head = node;
	if (head->next == NULL) {
		int ret = head->data;
		free(head);
		return ret;
	} 
	while (head->next->next != NULL) {
		head = head->next;
	}
	int ret = head->next->data;
	free(head->next);
	head->next = NULL;
	return ret;
}

bool find(const Node* node, int val) {
	const Node* cur = node;
	while (cur != NULL) {
		if (cur->data == val) {return true;}
		cur = cur->next;
	}
	return false;
}

size_t len(const Node* node) {
	const Node* cur = node;
	size_t n = 0;
	while (cur != NULL) {
		cur = cur->next;
		n++;
	}
	return n;
}

void delete_linked_list(Node* node) {
	Node* head = node;
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

int* into_array(const Node* node, size_t* rsize) {
	_exit_if_node_null(node);
	size_t size = len(node);
	int* arr = calloc(size, sizeof(int));
	
	const Node* head = node;
	size_t n = 0;
	while (head != NULL) {
		arr[n++] = head->data;
		head = head->next;
	}

	*rsize = size;
	return arr;
}

Node llist_reverse(Node* node) {
	_exit_if_node_null(node);
	Node rhead = new_linked_list(node->data);
	Node* head = node->next;
	

	while (head != NULL) {
		rhead = prepend(&rhead, head->data);
		head = head->next;
	}

	return rhead;
}

bool llist_is_circular(const Node* node) {
	_exit_if_node_null(node);
	const Node* head = node->next;
	while (head != NULL && head != node) {
		head = head->next;
	}
	return (head == node);
}

void llist_make_circular(Node* node) {
	_exit_if_node_null(node);
	Node* end = last(node);
	end->next = node;
}



