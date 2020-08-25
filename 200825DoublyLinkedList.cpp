#include <stdio.h>
#include <stdlib.h>
// 학교 실습 코드
typedef struct DoublyLinkedList {
	struct DoublyLinkedList* prev;
	struct DoublyLinkedList* next;
	char elem;
}node;

typedef struct List {
	int N;
	node* H;
	node* T;
}list;

node* createNode() {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->prev = NULL;
	newNode->elem = NULL;
	newNode->next = NULL;
	return newNode;
}

void init(list* A) {
	A->H = createNode();
	A->T = createNode();
	A->H->next = A->T;
	A->T->prev = A->H;
	scanf("%d", &A->N);
	getchar();
}

node* get_entry(list *one, int position) {

	node* A = one->H->next;
	node* chase_A = one->H;

	int cnt = 0;
	while (A != NULL) {

		if (cnt == position)
			break;

		chase_A = A;
		A = A->next;
		cnt++;
	}

	if (A == NULL && cnt != position)
		return NULL;
	else
		return chase_A;
}

void add(list *one, int position, char item) {
	node* A = get_entry(one, position);

	if (A == NULL)
	{
		printf("invalid position\n");
		return;
	}

	node* chase_A = A->prev;
	node* newNode = createNode();

	newNode->elem = item;
	A->prev = chase_A->next = newNode;
	newNode->prev = chase_A;
	newNode->next = A;
}

void Delete(list *one, int position) {
	node* A = get_entry(one, position);

	if (A == NULL || A == one->T)
	{
		printf("invalid position\n");
		return;
	}

	node* prev_A = A->prev;
	node* next_A = A->next;
	prev_A->next = next_A;
	next_A->prev = prev_A;

	free(A);
}

void print(list *one) {
	node* A = one->H->next;

	while (A->next != NULL) {
		printf("%c", A->elem);
		A = A->next;
	}
	printf("\n");
}

void process(list *one) {
	char op = NULL;
	int position = 0;
	char ch = NULL;

	while (one->N--)
	{
		scanf("%c", &op);

		if (op == 'A') // Add
		{
			scanf("%d %c", &position, &ch);
			add(one, position, ch);
		}
		else if (op == 'D') // Delete
		{
			scanf("%d", &position);
			Delete(one, position);
		}
		else if (op == 'G') // getEntry
		{
			scanf("%d", &position);
			node* temp = get_entry(one, position);
			if (temp == NULL || temp == one->T)
			{
				printf("invalid position\n");
			}
			else
			{
				printf("%c\n", temp->elem);
			}
		}
		else if (op == 'P') // Print
		{
			print(one);
		}
		getchar();
	}

}

int main() {
	list* one = (list*)malloc(sizeof(list));;
	init(one);
	process(one);
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct DoublyLinkedList 
//{
//	struct DoublyLinkedList *prev;
//	struct DoublyLinkedList *next;
//	char elem;
//}node;
//
//node *H;
//node *T;
//
//node *createNode() {
//	node* newNode = (node*)malloc(sizeof(node));
//	newNode->prev = NULL;
//	newNode->elem = NULL;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void init() {
//	H = createNode();
//	T = createNode();
//	H->next = T;
//	T->prev = H;
//}
//
//node *get_entry(int position) {
//
//	node *A = H;
//
//	int cnt = 0;
//	while (A != NULL) {
//
//		if (cnt == position)
//			return A;
//
//		A = A->next;
//		cnt++;
//	}
//
//	return H;
//}
//
//void add(int position, char item) {
//	node *A = get_entry(position);
//
//	if (A == H)
//	{
//		printf("invalid position\n");
//		return;
//	}
//
//	node *newNode = createNode();
//
//	newNode->elem = item;
//	A->prev->next = newNode;
//	newNode->prev = A->prev;
//	A->prev = newNode;
//	newNode->next = A;
//}
//
//void Delete(int position) {
//	node *A = get_entry(position);
//
//	if (A == H || A == T)
//	{
//		printf("invalid position\n");
//		return;
//	}
//
//	A->prev->next = A->next;
//	A->next->prev = A->prev;
//	free(A);
//}
//
//void printList() {
//	node* A = H->next;
//
//	while (A != T) 
//	{
//		printf("%c", A->elem);
//		A = A->next;
//	}
//	printf("\n");
//}
//
//int main() {
//
//	int N;
//	char op = NULL;
//	int position = 0;
//	char ch = NULL;
//
//	scanf("%d\n", &N);
//	init();
//
//	for (int i = 0; i < N; ++i)
//	{
//		scanf("%c", &op);
//
//		if (op == 'A')
//		{
//			scanf("%d %c", &position, &ch);
//			add(position, ch);
//		}
//		else if (op == 'D')
//		{
//			scanf("%d", &position);
//			Delete(position);
//		}
//		else if (op == 'G')
//		{
//			scanf("%d", &position);
//			node* temp = get_entry(position);
//			if (temp == T)
//			{
//				printf("invalid position\n");
//			}
//			else
//			{
//				printf("%c\n", temp->elem);
//			}
//		}
//		else if (op == 'P')
//		{
//			printList();
//		}
//		getchar();
//	}
//
//	return 0;
//}