#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j,n,m,tmp, num[9], sum=0, Mi=0;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);

	}

	for (i = 0; i < 9; i++)             //���� ���ϱ�
	{
		sum = sum + num[i];
	}

	for (i = 0; i < 8; i++)            //�� �� ���� ��
	{
		for (j = i + 1; j < 9; j++)
		{
			Mi = num[i] + num[j];

			if (sum - Mi == 100)           //�� ���� 100�̸� break
			{
				/*                         //�� Ʋ�� �ڵ����� ���� ã��. (���� �ٸ� �� �־ ����� ����.)
				tmp = num[i];
				num[i] = num[7];
				num[7] = tmp;

				tmp = num[j];
				num[j] = num[8];
				num[8] = tmp;

				break;
				*/

				num[i] = 0;
				num[j] = 0;
				i = 8;                  //Ż��
			}
		}

	}

	
	for (i = 0; i < 9;i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (num[i] < num[j])
			{
				tmp = num[j];
				num[j] = num[i];
				num[i] = tmp;
			}
		}
	}

	for (i = 2; i < 9; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;

}