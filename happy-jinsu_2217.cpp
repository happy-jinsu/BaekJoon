#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;  // ��Ÿ�� ������ ���� �̷��� �ذ���.

int main()
{
	int NumberOfRopes, tmp, i, MIN = 0, MAX = 0, Weight;
	
	scanf("%d", &NumberOfRopes);
	int* Rope = (int*)malloc(sizeof(int) * NumberOfRopes); // �����Ҵ�

	for (i = 0; i < NumberOfRopes; i++)                    // �Է¹ޱ�
		scanf("%d", &Rope[i]);
	
	sort(Rope, Rope + NumberOfRopes);                      // ���� �� ���� ����.
	MIN = 0;                                                 // j �ʱ�ȭ.

	for (i = NumberOfRopes; i > 0; i--)                    // �� ���� �ٿ����� MAX�� ��.
	{
		Weight = Rope[MIN] * i;
		MIN++;

		if (Weight > MAX)
			MAX = Weight;
	}

	printf("%d",MAX);
	free(Rope);                                             // �޸� ����
	return 0;
}