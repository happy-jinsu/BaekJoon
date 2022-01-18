#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, num1, num2, sum = 0, finalSum = 0;

	//1. 입력 받기
	scanf("%d", &num1);
	scanf("%d", &num2);

	//2. 계산 하기
	sum += num1 * (num2 % 10);   // 472 * 5
	printf("%d\n", sum);
	finalSum += sum;
	sum = 0; 

	sum += num1 * ((num2 % 100) / 10); // 475 * 8
	printf("%d\n", sum);
	finalSum += sum * 10; // 475 * 80
	sum = 0;
	
	sum += num1 * ((num2 - (num2 % 100)) / 100); // 475 * 3
	printf("%d\n", sum);
	finalSum += sum * 100; // 475 * 300

	printf("%d", finalSum);

	return 0;
}
