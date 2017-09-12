#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<string.h>


int right = 0;
int wrong = 0;
char getSignal();
int  calculateIntegerResult(int num1, int num2, char signal);
//int getNumber();
void doIntegerSubject();
void falsePrint(int);
void correctPrint(int);

/*char getSignal()

{

char signal[4] = { '+','-','*','/' };

srand((unsigned)time(NULL));

return signal[rand() % 4];

}*/
char getSignal()
{
	srand((unsigned)time(NULL));
	int a;
	a = rand() % 4 + 1;
	switch (a)
	{
	case 1:
		return '+';
		break;
	case 2:
		return'-';
		break;
	case 3:
		return '*';
		break;
	case 4:
		return '/';
		break;
	default:
		break;
	}
}
/*int getNumber()
{
srand((unsigned)time(NULL));
int a, b;
a = rand() % 100 + 1;
b = rand() % 100 + 1;
return 0;
}*/

int calculateIntegerResult(int num1, int num2, char signal)
{
	int t;
	switch (signal)
	{
	case '+':
		t = num1 + num2;
		break;
	case'-':
		t = num1 - num2;
		break;
	case'*':
		t = num1*num2;
		break;
	case'/':
		t = num1 / num2;
		break;
	default:
		t = 0;
		printf("运算符不符合规则\n");
		break;
	}
	return t;
}

void calculateMarkResult(int num1, int num2, int num3, int num4, char signal, int mark[5])
{

	switch (signal)
	{
	case '+':
		if (num2 == num4)
		{
			mark[0] = num1 + num3;
			mark[1] = num1;
		}
		else
		{
			mark[0] = num1*num4 + num2*num3;
			mark[1] = num2*num4;
		}
		break;
	case'-':
		if (num2 == num4)
		{
			mark[0] = num1 - num3;
			mark[1] = num1;
		}
		else
		{
			mark[0] = num1*num4 - num2*num3;
			mark[1] = num2*num4;
		}
		break;
	case'*':
		mark[0] = num1*num3;
		mark[1] = num2*num4;
		break;
	case'/':
		mark[0] = num1*num4;
		mark[1] = num2*num3;
		break;
	default:
		printf("运算符不符合规则\n");
		break;
	}

}

void doIntegerSubject()
{
	int a, b, giverAnswer, printFlag;

	char signal;
	srand((unsigned)time(NULL));
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	signal = getSignal();
	if (signal == '/')
	{
		if (b == 0)
		{
			int temp;
			temp = b;
			b = a;
			a = temp;
		}
	}
	printf("please do blew problem:\n");
	printf("%d %c %d=", a, signal, b);
	//giverAnswer = _getch();
	scanf_s("%d", &giverAnswer);
	fflush(stdin);
	if (calculateIntegerResult(a, b, signal) == giverAnswer)

	{
		right++;
		srand((unsigned)time(NULL));
		printFlag = rand() % 4 + 1;
		correctPrint(printFlag);

	}

	else

	{
		wrong++;
		srand((unsigned)time(NULL));
		printFlag = rand() % 4 + 1;;
		falsePrint(printFlag);
		printf("\n正确答案：%d\n", calculateIntegerResult(a, b, signal));
	}

}

void doMarkSubject()
{
	int a, b, c, d, i = 0, printFlag;
	int result[5];
	char giverNumber[10];
	char signal;
	int x, y, j;
	signal = getSignal();
	srand((unsigned)time(NULL));
	while (1)
	{
		a = rand() % 100;
		while (1)
		{
			b = rand() % 100;
			if (b)
				break;
		}
		if (a < b)
			break;
	}

	while (1)
	{
		c = rand() % 100;
		while (1)
		{
			d = rand() % 10;
			if (d)
				break;
		}
		if (c < d)
			break;
	}
	/*a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	c = rand() % 100 + 1;
	d = rand() % 100 + 1;
	signal = getSignal();
	if (b == 0 || a>b)
	{
	int temp;
	temp = b;
	b = a;
	a = temp;
	}
	if (d == 0 || c>d)
	{
	int f;
	f = b;
	b = a;
	a = f;
	}*/
	printf("please do blew problem:\n");
	printf("%d/%d %c %d/%d=", a, b, signal, c, d);
	//giverAnswer = _getch();
	i = 0;
	while (1)
	{
		giverNumber[i] = _getche();
		if (giverNumber[i] == '/')
			break;
		i++;

	}
	x = 0;
	for (j = 0; j < i; j++)
	{
		x = x + pow(10, (i - 1 - j))*(giverNumber[j] - '0');
	}
	scanf_s("%d", &y);
	calculateMarkResult(a, b, c, d, signal, result);
	//scanf_s("%d", &giverNumber[i]);
	fflush(stdin);
	if (x == result[0] && y == result[1])

	{
		right++;
		srand((unsigned)time(NULL));
		printFlag = rand() % 4 + 1;
		correctPrint(printFlag);

	}

	else

	{
		wrong++;
		srand((unsigned)time(NULL));
		printFlag = rand() % 4 + 1;;
		falsePrint(printFlag);
		int *dd;
		printf("\n正确答案：%d/%d\n", result[0], result[1]);
		//printf("\n正确答案：%d\n", calculateMarkResult(a, b, signal, c, d));
	}

}
//回答正确打印信息
void correctPrint(int num)
{
	switch (num)

	{
	case 1:
		printf("You're right!\n"); break;
	case 2:
		printf("It's OK!\n"); break;
	case 3:
		printf("Correct!\n"); break;
	case 4:
		printf("Perfect!\n"); break;
	case 5:
		printf("Oh my gag!\n"); break;
	default:
		printf("Powerful!\n"); break;
	}

}
//回答错误打印信息

void falsePrint(int num)
{
	switch (num)
	{
	case 1:
		printf("You're lost!"); break;
	case 2:
		printf("Failure!"); break;
	case 3:
		printf("Come on!"); break;
	case 4:
		printf("It's wrong!"); break;
	default:
		printf("Incorrect!"); break;
	}
}

void main()
{
	int total, choice, choice1;
	int con=0 ;
	printf("welcome to math world!:");
	system("cls");
	while (1)
	{
		if (con ==0)
		{
			printf("\t\t\t  1.整数运算\n");
			printf("\t\t\t  2.分数运算\n");
			printf("请选择：\n");
			scanf_s("%d", &choice);
			system("cls");
			switch (choice)
			{
			case 1:
				while (right >= wrong)
				{
					doIntegerSubject();

				}
				total = right + wrong;
				printf("你一共答了:%d道题其中答对了%d 道答错了%d道\n", total, right, wrong);
				break;
			case 2:
				while (right >= wrong)
				{
					doMarkSubject();
				}
				total = right + wrong;
				printf("你一共答了:%d道题其中答对了%d 道答错了%d道\n", total, right, wrong);
				break;
			}
			//system("pause");
			printf("\n\t\t\t1.重新选择？\n");
			printf("\n\t\t\t2.退出运算？\n");
			scanf_s("%d", &choice1);
			if (choice1 == 1)
			{
				system("cls");
				con = 0;
			}
			else if (choice1 == 2)
			{
				exit(0);
			}
			else
				printf("抱歉!，你输入的指令有误!请重新输入!\n");
			system("pause");
		}
	}
}
