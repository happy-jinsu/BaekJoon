#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int numInput[10] = { 0 };
	int i, j,num,sum=1;

	for (i = 0; i < 3; i++)        //�Է¹ް� ���ÿ� ���ؼ� sum�� ����
	{
		scanf("%d", &num);
		sum *= num;
	}
	
	while (1)
	{
		numInput[sum % 10]++;      //10���� ���� �������� �ش� �ڸ��� ���ڿ� ������. �������� �ش��ϴ� �迭�� +1����.
		sum /= 10;                 
		if (sum == 0)              //�Է¹��� ���ڰ� 0�� �� ������ �ݺ�
			break;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", numInput[i]);
	}

	return 0;
}