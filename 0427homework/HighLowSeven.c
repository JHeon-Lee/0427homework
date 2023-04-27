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
//void Surffle(Cards* cards);
void GamePlay(Cards* cards, bool open, int* count, int* money);
void Result(Cards* cards);

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int Money = 50000;
	int CardCount = 0;
	Cards cards[52];
	bool isContinue = true;
	bool opencard = false;


	InitCards(cards);


	while (Money > 0)
	{
		system("cls");

		printf("※※※ Welcome to High Low Seven Game!! ※※※\n\n");

		while (isContinue)
		{
			GamePlay(cards, opencard, &CardCount, &Money);

			break;
		}
		break;
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

//void Surffle(Cards* cards)
//{
//	for (int i = 0; i < 200; i++)
//	{
//		int src = rand() % 52;
//		int dest = rand() % 52;
//
//		Cards temp = cards[src];
//		cards[src] = cards[dest];
//		cards[dest] = temp;
//	}
//}

void GamePlay(Cards* cards, bool open, int* count, int* money)
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

	printf("카드 오픈!!\n");

	for (int i = 0; i < 6; i++)
	{
		switch (cards[random_nums[i]].shape)
		{
		case 0:
			printf("♠");
			break;
		case 1:
			printf("♥");
			break;
		case 2:
			printf("◆");
			break;
		case 3:
			printf("♣");
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
		if (i == 5 && open == false)
		{
			printf("??\t");
		}
		else if (i == 5 && open == true)
		{
			continue;
		}
	}
	printf("\n\n");
	(*count)++;
	
	printf("베팅액을 적어주세요. (최소 2000원) : ");
	scanf_s("%d", &bet);
	while (bet > money || bet < 2000)
	{
		printf("제대로 베팅하세요.\n");
		Sleep(2000);
		printf("베팅액을 적어주세요. (최소 2000원) : ");
		scanf_s("%d", &bet);
	}

	printf("1. High 2. Low 3. Seven : ");
	scanf_s("%d", &num);
	while (num > 3 || num < 1)
	{
		printf("1 ~ 3에서 골라야합니다!!!\n");
		Sleep(2000);
		printf("1. High 2. Low 3. Seven : ");
		scanf_s("%d", &num);
	}

	open = true;

	if (cards[random_nums[5]].num > 7 && num == 1)
	{
		
	}

}
