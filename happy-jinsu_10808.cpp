#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int alphabet[26] = { 0 };      // 97 = a, 122= z
	int i, j,end;
	char word[100];

	scanf("%s", word);
	end = strlen(word);
	/*
	for (i = 0; i < end; i++)               //���ư��� ���
	{
		for (j = 'a'; j < 'z'; j++)
		{
			if (word[i] == j)
			{
				alphabet[j-97]++;
			}
		}
	}
	*/

	for (i = 0; i < end; i++)                //(�ڵ� ����) ������ ���
	{
		alphabet[ word[i] - 97 ]++;           
	}

	for (i = 0; i < 26; i++)
	{
		printf("%d ", alphabet[i]);
	}

	return 0;
}