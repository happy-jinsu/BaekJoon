#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000000
#define TRUE 1
#define FALSE 0

typedef char element;
typedef struct
{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Stack is full!\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		//printf("Item %d is pushed\n", item);
	}
}

// �����Լ�
element pop(StackType* s)
{
	element temp;
	if (is_empty(s))
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		//printf("Item %d is popped\n", temp);
		return temp;
	}
}

//top Ȯ�� �Լ�
char peek(StackType* s)
{
	//if (is_empty(s) == TRUE)
		//printf("Stack is Empty");

	//else
		return s->data[s->top];
}


int is_matching(const char* in)
{
	StackType s;
	char ch;
	int i, n = strlen(in);

	init_stack(&s);
	push(&s, in[0]);

	for (i = 1; i < n; i++)
	{
		ch = in[i];
		if (peek(&s) == ch)
		{
			pop(&s);
		}

		else
			push(&s, in[i]);
	}
			
	if (is_empty(&s))
		return TRUE;
	else
		return FALSE;
}

int main(void)
{
	int i, T, num=0;
	scanf("%d ", &T);

	for (i = 0; i < T; i++)
	{
		char p[MAX_STACK_SIZE];
		scanf("%s", &p);

		if (is_matching(p) == TRUE)
			num++;
	}

	printf("%d", num);

	return 0;
}