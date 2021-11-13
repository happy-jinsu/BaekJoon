#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 50
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


int is_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);

	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch)
		{
		case '(':
			push(&s, ch);
			break;

		case ')':
			if (is_empty(&s))
				return FALSE;
			else
			{
				open_ch = pop(&s);
				if (open_ch == '(' && ch != ')')
				{
					return FALSE;
				}
				break;
			}
		}

	}
	if (!is_empty(&s))
		return FALSE;

	return TRUE;
}

int main(void)
{
	int i, j, T;
	scanf("%d ", &T);

	for (i = 0; i < T; i++)
	{
		char p[MAX_STACK_SIZE];
		scanf("%s",&p);

		if (is_matching(p) == TRUE)
			printf("YES\n");

		else
			printf("NO\n");
	}

	return 0;
}