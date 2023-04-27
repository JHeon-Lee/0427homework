#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

typedef struct Cards
{
	int num;
	int shape;
}Cards;

void InitCards(Cards* cards);
void GamePlay(Cards* cards, int* count, int* money);

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int Money = 50000;
	int CardCount = 0;
	Cards cards[52];
	bool isContinue = true;

	InitCards(cards);

	while (isContinue)
	{
		system("cls");

		printf("�ءء� Welcome to High Low Seven Game!! �ءء�\n\n");

		printf("���� ���� �ݾ� : %d\n\n", Money);

		GamePlay(cards, &CardCount, &Money);

		if (CardCount == 8)
		{
			printf("���ο� ī�� 52������ �����մϴ�.\n");
			printf("ī�弯����..");
			Sleep(1500);
			printf("..");
			Sleep(1500);
			printf("..");
			Sleep(1500);
			printf("..\n");
			InitCards(cards);
		}

		if (Money < 2000)
		{
			printf("�̷�! ������ ���� ���׿�.. ������ ����˴ϴ�.\n");
			isContinue = false;
		}
	}
	return 0;
}

void InitCards(Cards* cards)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cards[i * 13 + j].num = j;
			cards[i * 13 + j].shape = i;
		}
	}
}

void GamePlay(Cards* cards, int* count, int* money)
{
	int num;
	int bet;
	int random_nums[6];
	for (int i = 0; i < 6; i++)
	{
		random_nums[i] = rand() % 52;
		for (int j = 0; j < i; j++)
		{
			if (random_nums[i] == random_nums[j] || cards[random_nums[i]].num == 0)
			{
				i--;
				break;
			}
		}
	}

	printf("ī�� ����!!\n");

	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			printf("??\t");
		}
		else
		{
			switch (cards[random_nums[i]].shape)
			{
			case 0:
				printf("��");
				break;
			case 1:
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			}
			switch (cards[random_nums[i]].num)
			{
			case 1:
				printf("A\t");
				break;
			case 11:
				printf("J\t");
				break;
			case 12:
				printf("Q\t");
				break;
			case 13:
				printf("K\t");
				break;
			default:
				printf("%d\t", cards[random_nums[i]].num);
				break;
			}
		}
	}
	printf("\n\n");
	
	printf("���þ��� �����ּ���. (�ּ� 2000��) : ");
	scanf_s("%d", &bet);
	while (bet > *money || bet < 2000)
	{
		printf("����� �����ϼ���.\n");
		Sleep(2000);
		printf("���þ��� �����ּ���. (�ּ� 2000��) : ");
		scanf_s("%d", &bet);
	}
	printf("\n");

	printf("1. High 2. Low 3. Seven : ");
	scanf_s("%d", &num);
	while (num > 3 || num < 1)
	{
		printf("1 ~ 3���� �����մϴ�!!!\n");
		Sleep(2000);
		printf("1. High 2. Low 3. Seven : ");
		scanf_s("%d", &num);
	}
	printf("\n");

	if (cards[random_nums[5]].num > 7 && num == 1)
	{
		printf("�¸��߽��ϴ�!\n");
		*money += bet;
	}
	else if (cards[random_nums[5]].num < 7 && num == 2)
	{
		printf("�¸��߽��ϴ�!\n");
		*money += bet;
	}
	else if (cards[random_nums[5]].num == 7 && num == 3)
	{
		printf("Seven���� �¸��߽��ϴ�!\n");
		*money += (bet * 13);
	}
	else
	{
		printf("�����ϴ�...\n");
		*money -= bet;
	}

	printf("���� ī�� : ");
	switch (cards[random_nums[5]].shape)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	}
	switch (cards[random_nums[5]].num)
	{
	case 1:
		printf("A\t");
		break;
	case 11:
		printf("J\t");
		break;
	case 12:
		printf("Q\t");
		break;
	case 13:
		printf("K\t");
		break;
	default:
		printf("%d\t", cards[random_nums[5]].num);
		break;
	}

	(*count)++;

	Sleep(2000);
	printf("\n");
}
