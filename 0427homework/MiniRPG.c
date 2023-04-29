#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

typedef struct Coordinate
{
	int x;
	int y;
}Coordinate;

typedef struct Player // ��
{
	Coordinate pCoordinate;
	int pMaxHp;
	int pCurrHp;
	int pAtk;
	int pDef;
	int pExp;
	int pLv;
	int pGold;
	double pCritrate;
}Player;

typedef struct Monster // ��, ��, ��
{
	Coordinate mCoordinate;
	char mName[16];
	int mMaxHp;
	int mCurrHp;
	int mAtk;
	int mDef;
	int mExp;
	double mCritrate;
}Monster;

typedef struct Oasis // ��
{
	Coordinate oCoordinate;
}Oasis;

typedef struct HiddenBox // ??
{
	Coordinate hCoordinate;
	int hAtk;
	int hPlusAtk;
	double hCritrate;
	double hPlusCritrate;
}HiddenBox;

void MainGame();
void SetBoard(int board[][12], Player pl, Monster* mon, Oasis oa, HiddenBox* hb);
void PrintBoard(int board[][12]);

int main()
{
	MainGame();

	return 0;
}

void MainGame()
{
	srand((unsigned int)time(NULL)); // ���� ����
	rand();

	int GameBoard[12][12] = {
		{7,7,7,7,7,7,7,7,7,7,7,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,7},
		{7,7,7,7,7,7,7,7,7,7,7,7}
	};
	Player player = { {1,1}, 100, 100, 20, 5, 0, 1, 100, 0.1 };
	Monster monster[5] = {
		{{rand() % 2 + 9, rand() % 2 + 1}, "��� ����", 60, 60, 10, 0, 50, 0.05},
		{{rand() % 2 + 7, rand() % 2 + 3}, "���̷��� �ü�", 40, 40, 15, 0, 50, 0.1},
		{{rand() % 2 + 3, rand() % 2 + 7}, "��� ����", 60, 60, 10, 0, 50, 0.05},
		{{rand() % 2 + 1, rand() % 2 + 9}, "���̷��� �ü�", 40, 40, 15, 0, 50, 0.1},
		{{10, 10}, "��ũ ��ɰ�", 300, 300, 30, 5, 200, 0.1}
	};
	Oasis oasis = { {3,1} };
	HiddenBox hiddenbox[2] = {
		{{5,6}, 30, 20, 0.1, 0.1},
		{{6,5}, 30, 20, 0.1, 0.1}
	};									// ������ ����ü�� ����� ���� �ʱ�ȭ

	bool isContinue = true;

	printf("�ססססססס� Mini Rpg �ססססססס�\n\n");
	Sleep(2000);
	printf("����� �������� ��ũ ��ɰ��� óġ�ϰ� Ż���ؾ��մϴ�.\n\n");
	Sleep(2000);
	printf("��ũ ��ɰ��� �ſ� �����ϴ� ���͸� óġ�ϰų�, ���� �ڽ��� ��� �����ϰ� �����ؾ��մϴ�.\n\n");
	Sleep(2000);
	printf("�׷� ����� ���ϴ�...\n\n");
	Sleep(2000);
	printf("�� �ε���...");
	Sleep(1000);
	printf("...");
	Sleep(1000);
	printf("...\n\n");
	Sleep(1000);
	printf("���� ������ �����մϴ�.\n\n");	// ���� ���Ժ�

	SetBoard(GameBoard, player, monster, oasis, hiddenbox);

	while (isContinue)
	{
		if (_kbhit())
		{
			system("cls");

			printf("�����¿� : w s a d\n\n"); // ����Ű ����
			printf("�� : �÷��̾� �� : ��� ���� �� : ���̷��� �ü�, �� : ��ũ ��ɰ� �� : ���ƽý� ?? : ���� �ڽ�\n\n"); // �������̽� ����

			char move = _getch();
			switch (move)
			{
			case 119: // w
			{
				if (player.pCoordinate.y > 1)
				{
					GameBoard[player.pCoordinate.y][player.pCoordinate.x] = 0;
					player.pCoordinate.y--;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					break;
				}
				else
					break;
			}
			case 97: // a
			{
				if (player.pCoordinate.x > 1)
				{
					GameBoard[player.pCoordinate.y][player.pCoordinate.x] = 0;
					player.pCoordinate.x--;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					break;
				}
				else
					break;
			}
			case 115: // s
			{
				if (player.pCoordinate.y < 11)
				{
					GameBoard[player.pCoordinate.y][player.pCoordinate.x] = 0;
					player.pCoordinate.y++;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					break;
				}
				else
					break;
			}
			case 100: // d
			{
				if (player.pCoordinate.x < 11)
				{
					GameBoard[player.pCoordinate.y][player.pCoordinate.x] = 0;
					player.pCoordinate.x++;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					break;
				}
				else
					break;
			}
			default:
				break;
			}

			printf("���� ü�� : %d/%d  ���� : %d  ���ݷ� : %d  ���� : %d  ũ��Ƽ�� Ȯ�� : %g%%\n\n", player.pCurrHp, player.pMaxHp, player.pLv, player.pAtk, player.pDef, player.pCritrate * 100);
			// ĳ������ �������ͽ�

			PrintBoard(GameBoard);
			// ���Ӻ����� ���

			for (int i = 0; i < 5; i++) // ���Ϳ� ��������
			{
				if (player.pCoordinate.x == monster[i].mCoordinate.x && player.pCoordinate.y == monster[i].mCoordinate.y)
				{
					printf("%s ��(��) �����ƽ��ϴ�!\n", monster[i].mName);
					printf("%s �� ü�� : %d/%d\n", monster[i].mName, monster[i].mCurrHp, monster[i].mMaxHp);
					Sleep(1000);

					while (1)
					{
						printf("�÷��̾��� ����!!\n");
						if (rand() % 100 < player.pCritrate * 100)
						{
							printf("ũ��Ƽ��!! �ι��� �������� ����!!\n");
							monster[i].mCurrHp -= player.pAtk * 2 - monster[i].mDef;
						}
						else
						{
							monster[i].mCurrHp -= player.pAtk - monster[i].mDef;
						}
						Sleep(1000);
						printf("%s �� ü�� : %d/%d\n", monster[i].mName, monster[i].mCurrHp, monster[i].mMaxHp);
				
						if (monster[i].mCurrHp <= 0)
						{
							printf("%s ��(��) óġ�߽��ϴ�.\n\n", monster[i].mName);
							Sleep(1000);
							printf("����ġ %d ������ϴ�.\n\n", monster[i].mExp);
							player.pExp += monster[i].mExp;
							monster[i].mCoordinate.y = NULL;
							monster[i].mCoordinate.x = NULL;
							SetBoard(GameBoard, player, monster, oasis, hiddenbox);
							if (player.pExp >= 100)
							{
								int lv = player.pExp / 100;
								printf("%d ���� �ö����ϴ�!\n\n", lv);
								player.pLv += lv;
								player.pExp -= lv * 100;
								player.pMaxHp += lv * 50;
								player.pCurrHp += lv * 25;
								player.pAtk += lv * 20;
								player.pDef += lv * 5;
							}
							Sleep(1000);
							if (i == 4)
							{
								printf("�����մϴ�!! %s ��(��) �����ƽ��ϴ�!! �������� Ż���մϴ�.\n\n", monster[i].mName);
								isContinue = false;
							}
							printf("���͸� ���� ��� ����.\n\n");
							break;
						}
						Sleep(1000);
						printf("%s �� ����!!\n", monster[i].mName);
						if (rand() % 100 < monster[i].mCritrate * 100)
						{
							printf("ũ��Ƽ��! ���� ������ �޼ҿ� �¾Ҵ�..\n");
							player.pCurrHp -= monster[i].mAtk * 2 - player.pDef;
						}
						else
						{
							player.pCurrHp -= monster[i].mAtk - player.pDef;
						}
						Sleep(1000);
						printf("�÷��̾��� ü�� : %d/%d\n", player.pCurrHp, player.pMaxHp);
						Sleep(1000);
					}
				}
			}

			if (player.pCoordinate.x == oasis.oCoordinate.x && player.pCoordinate.y == oasis.oCoordinate.y) // ���ƽý��� �������
			{
				printf("���ƽý��� �����߽��ϴ�.\n\n");
				Sleep(1000);
				printf("���� ü���� ��� ȸ���˴ϴ�.\n\n");
				player.pCurrHp = player.pMaxHp;
				oasis.oCoordinate.y = NULL;
				oasis.oCoordinate.x = NULL;
				SetBoard(GameBoard, player, monster, oasis, hiddenbox);
				Sleep(1000);
				printf("���͸� ���� ��� ����.\n\n");
			}

			for (int i = 0; i < 2; i++) // ���� �ڽ��� ��������
			{
				if (player.pCoordinate.x == hiddenbox[i].hCoordinate.x && player.pCoordinate.y == hiddenbox[i].hCoordinate.y)
				{
					printf("���� �ڽ��� �߰� �߽��ϴ�.\n\n");
					Sleep(1000);
					printf("���� ����������� �ƹ��� �𸨴ϴ�.\n\n");
					Sleep(1000);
					printf("���� �����...");
					Sleep(1000);
					printf("...");
					Sleep(1000);
					printf("...\n\n");
					Sleep(1000);
					int num = rand() % 3;
					switch (num)
					{
					case 0:
					{
						printf("�������� ��ġ�س��� �����̾����ϴ�..\n\n");
						Sleep(1000);
						if (rand() % 100 < hiddenbox[i].hCritrate * 100)
						{
							printf("�̷�! ������ ����� �������ȴ�... %d * 2 ��ŭ �������� �Խ��ϴ�.\n\n", hiddenbox[i].hAtk);
							Sleep(1000);
							player.pCurrHp -= hiddenbox[i].hAtk * 2 - player.pDef;
						}
						else
						{
							printf("%d ��ŭ�� �������� �Խ��ϴ�.\n\n", hiddenbox[i].hAtk);
							Sleep(1000);
							player.pCurrHp -= hiddenbox[i].hAtk - player.pDef;
						}
						break;
					}
					case 1:
					{
						printf("�� ������ ������ ����־����ϴ�!!\n\n");
						Sleep(1000);
						printf("�÷��̾��� ���ݷ��� %d �����մϴ�!\n\n", hiddenbox[i].hPlusAtk);
						player.pAtk += hiddenbox[i].hPlusAtk;
						break;
					}
					case 2:
					{
						printf("�������� ����� ���ġ�� ����־����ϴ�!!\n\n");
						Sleep(1000);
						printf("�÷��̾��� ũ��Ƽ�� Ȯ���� %g%% ��ŭ �����մϴ�!\n\n", hiddenbox[i].hPlusCritrate * 100);
						player.pCritrate += hiddenbox[i].hPlusCritrate;
						break;
					}
					}
					hiddenbox[i].hCoordinate.y = NULL;
					hiddenbox[i].hCoordinate.x = NULL;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					Sleep(1000);
					printf("���͸� ���� ��� ����.\n\n");
				}
			}

			if (player.pCurrHp < 1) // �÷��̾� ü���� 0 ���ϰ� �� ���
			{
				printf("Hp�� �� ���������ϴ�.. ���� �����ϴ�...\n\n");
				Sleep(1000);
				printf("Game Over\n\n");
				Sleep(1000);
				isContinue = false;
			}
		}
	}
}

void SetBoard(int board[][12], Player pl, Monster* mon, Oasis oa, HiddenBox* hb) // ���Ӻ��� ����
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 2)
		{
			board[mon[i].mCoordinate.y][mon[i].mCoordinate.x] = 2;
		}
		else if (i == 1 || i == 3)
		{
			board[mon[i].mCoordinate.y][mon[i].mCoordinate.x] = 3;
		}
		else
		{
			board[mon[i].mCoordinate.y][mon[i].mCoordinate.x] = 4;
		}
	}

	board[oa.oCoordinate.y][oa.oCoordinate.x] = 5;

	for (int i = 0; i < 2; i++)
	{
		board[hb[i].hCoordinate.y][hb[i].hCoordinate.x] = 6;
	}

	for (int i = 0; i < 12; i++)
	{
		board[0][i] = 7;
		board[11][i] = 7;
		board[i][0] = 7;
		board[i][11] = 7;
	}

	board[pl.pCoordinate.y][pl.pCoordinate.x] = 1;
}

void PrintBoard(int board[][12]) // ���Ӻ��� ���
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == 0)
			{
				printf("  ");
			}
			else if (board[i][j] == 1)
			{
				printf("��");
			}
			else if (board[i][j] == 2)
			{
				printf("��");
			}
			else if (board[i][j] == 3)
			{
				printf("��");
			}
			else if (board[i][j] == 4)
			{
				printf("��");
			}
			else if (board[i][j] == 5)
			{
				printf("��");
			}
			else if (board[i][j] == 6)
			{
				printf("??");
			}
			else
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("\n");
}
