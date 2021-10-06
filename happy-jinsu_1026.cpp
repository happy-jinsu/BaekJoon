#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int main()
{
	int i, j, sum=0, MAX = 0, N, Location=0, tmp, A[100], B[100];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);

	std::sort(A, A + N);   //C++ A�� �������� ���� (�Ʒ��� �������ķ� �������� �����ϴ� �͵� �����.)

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (B[j] > MAX)
			{
				MAX = B[j];
				Location = j;
			}
			if (j == N-1)
			{
				sum += B[Location] * A[i];
				B[Location] = -1;
			}
		}
		MAX = -1;
	}
	printf("%d", sum);
	return 0;
}



/*�������� ��������
for (i = 0; i < N-1; i++)   //A�� �������� ����
{
    for (j = i+1; j < N; j++)
	{
		if (A[i] > A[j])
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
}*/