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

typedef struct Player // ◎
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

typedef struct Monster // ＆, ＠, ★
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

typedef struct Oasis // ♨
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
	srand((unsigned int)time(NULL)); // 난수 생성
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
		{{rand() % 2 + 9, rand() % 2 + 1}, "고블린 도적", 60, 60, 10, 0, 50, 0.05},
		{{rand() % 2 + 7, rand() % 2 + 3}, "스켈레톤 궁수", 40, 40, 15, 0, 50, 0.1},
		{{rand() % 2 + 3, rand() % 2 + 7}, "고블린 도적", 60, 60, 10, 0, 50, 0.05},
		{{rand() % 2 + 1, rand() % 2 + 9}, "스켈레톤 궁수", 40, 40, 15, 0, 50, 0.1},
		{{10, 10}, "오크 사령관", 300, 300, 30, 5, 200, 0.1}
	};
	Oasis oasis = { {3,1} };
	HiddenBox hiddenbox[2] = {
		{{5,6}, 30, 20, 0.1, 0.1},
		{{6,5}, 30, 20, 0.1, 0.1}
	};									// 만들어둔 구조체를 사용한 변수 초기화

	bool isContinue = true;

	printf("§§§§§§§§ Mini Rpg §§§§§§§§\n\n");
	Sleep(2000);
	printf("당신은 던전에서 오크 사령관을 처치하고 탈출해야합니다.\n\n");
	Sleep(2000);
	printf("오크 사령관은 매우 강력하니 몬스터를 처치하거나, 히든 박스를 열어서 성장하고 도전해야합니다.\n\n");
	Sleep(2000);
	printf("그럼 행운을 빕니다...\n\n");
	Sleep(2000);
	printf("맵 로딩중...");
	Sleep(1000);
	printf("...");
	Sleep(1000);
	printf("...\n\n");
	Sleep(1000);
	printf("엔터 누를시 시작합니다.\n\n");	// 게임 도입부

	SetBoard(GameBoard, player, monster, oasis, hiddenbox);

	while (isContinue)
	{
		if (_kbhit())
		{
			system("cls");

			printf("상하좌우 : w s a d\n\n"); // 조작키 설명
			printf("◎ : 플레이어 ＆ : 고블린 도적 ＠ : 스켈레톤 궁수, ★ : 오크 사령관 ♨ : 오아시스 ?? : 히든 박스\n\n"); // 인터페이스 설명

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

			printf("현재 체력 : %d/%d  레벨 : %d  공격력 : %d  방어력 : %d  크리티컬 확률 : %g%%\n\n", player.pCurrHp, player.pMaxHp, player.pLv, player.pAtk, player.pDef, player.pCritrate * 100);
			// 캐릭터의 스테이터스

			PrintBoard(GameBoard);
			// 게임보드판 출력

			for (int i = 0; i < 5; i++) // 몬스터와 만났을때
			{
				if (player.pCoordinate.x == monster[i].mCoordinate.x && player.pCoordinate.y == monster[i].mCoordinate.y)
				{
					printf("%s 을(를) 마주쳤습니다!\n", monster[i].mName);
					printf("%s 의 체력 : %d/%d\n", monster[i].mName, monster[i].mCurrHp, monster[i].mMaxHp);
					Sleep(1000);

					while (1)
					{
						printf("플레이어의 공격!!\n");
						if (rand() % 100 < player.pCritrate * 100)
						{
							printf("크리티컬!! 두배의 데미지가 들어갔다!!\n");
							monster[i].mCurrHp -= player.pAtk * 2 - monster[i].mDef;
						}
						else
						{
							monster[i].mCurrHp -= player.pAtk - monster[i].mDef;
						}
						Sleep(1000);
						printf("%s 의 체력 : %d/%d\n", monster[i].mName, monster[i].mCurrHp, monster[i].mMaxHp);
				
						if (monster[i].mCurrHp <= 0)
						{
							printf("%s 을(를) 처치했습니다.\n\n", monster[i].mName);
							Sleep(1000);
							printf("경험치 %d 얻었습니다.\n\n", monster[i].mExp);
							player.pExp += monster[i].mExp;
							monster[i].mCoordinate.y = NULL;
							monster[i].mCoordinate.x = NULL;
							SetBoard(GameBoard, player, monster, oasis, hiddenbox);
							if (player.pExp >= 100)
							{
								int lv = player.pExp / 100;
								printf("%d 레벨 올랐습니다!\n\n", lv);
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
								printf("축하합니다!! %s 을(를) 물리쳤습니다!! 던전에서 탈출합니다.\n\n", monster[i].mName);
								isContinue = false;
							}
							printf("엔터를 눌러 계속 진행.\n\n");
							break;
						}
						Sleep(1000);
						printf("%s 의 공격!!\n", monster[i].mName);
						if (rand() % 100 < monster[i].mCritrate * 100)
						{
							printf("크리티컬! 적의 공격이 급소에 맞았다..\n");
							player.pCurrHp -= monster[i].mAtk * 2 - player.pDef;
						}
						else
						{
							player.pCurrHp -= monster[i].mAtk - player.pDef;
						}
						Sleep(1000);
						printf("플레이어의 체력 : %d/%d\n", player.pCurrHp, player.pMaxHp);
						Sleep(1000);
					}
				}
			}

			if (player.pCoordinate.x == oasis.oCoordinate.x && player.pCoordinate.y == oasis.oCoordinate.y) // 오아시스에 들렸을때
			{
				printf("오아시스에 도착했습니다.\n\n");
				Sleep(1000);
				printf("나의 체력이 모두 회복됩니다.\n\n");
				player.pCurrHp = player.pMaxHp;
				oasis.oCoordinate.y = NULL;
				oasis.oCoordinate.x = NULL;
				SetBoard(GameBoard, player, monster, oasis, hiddenbox);
				Sleep(1000);
				printf("엔터를 눌러 계속 진행.\n\n");
			}

			for (int i = 0; i < 2; i++) // 히든 박스랑 만났을때
			{
				if (player.pCoordinate.x == hiddenbox[i].hCoordinate.x && player.pCoordinate.y == hiddenbox[i].hCoordinate.y)
				{
					printf("히든 박스를 발견 했습니다.\n\n");
					Sleep(1000);
					printf("뭐가 들어있을지는 아무도 모릅니다.\n\n");
					Sleep(1000);
					printf("상자 까는중...");
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
						printf("누군가가 설치해놓은 함정이었습니다..\n\n");
						Sleep(1000);
						if (rand() % 100 < hiddenbox[i].hCritrate * 100)
						{
							printf("이런! 함정에 제대로 빠져버렸다... %d * 2 만큼 데미지를 입습니다.\n\n", hiddenbox[i].hAtk);
							Sleep(1000);
							player.pCurrHp -= hiddenbox[i].hAtk * 2 - player.pDef;
						}
						else
						{
							printf("%d 만큼의 데미지를 입습니다.\n\n", hiddenbox[i].hAtk);
							Sleep(1000);
							player.pCurrHp -= hiddenbox[i].hAtk - player.pDef;
						}
						break;
					}
					case 1:
					{
						printf("옛 영웅의 보검이 들어있었습니다!!\n\n");
						Sleep(1000);
						printf("플레이어의 공격력이 %d 증가합니다!\n\n", hiddenbox[i].hPlusAtk);
						player.pAtk += hiddenbox[i].hPlusAtk;
						break;
					}
					case 2:
					{
						printf("엘프족의 고고한 브로치가 들어있었습니다!!\n\n");
						Sleep(1000);
						printf("플레이어의 크리티컬 확률이 %g%% 만큼 증가합니다!\n\n", hiddenbox[i].hPlusCritrate * 100);
						player.pCritrate += hiddenbox[i].hPlusCritrate;
						break;
					}
					}
					hiddenbox[i].hCoordinate.y = NULL;
					hiddenbox[i].hCoordinate.x = NULL;
					SetBoard(GameBoard, player, monster, oasis, hiddenbox);
					Sleep(1000);
					printf("엔터를 눌러 계속 진행.\n\n");
				}
			}

			if (player.pCurrHp < 1) // 플레이어 체력이 0 이하가 된 경우
			{
				printf("Hp가 다 떨어졌습니다.. 힘이 빠집니다...\n\n");
				Sleep(1000);
				printf("Game Over\n\n");
				Sleep(1000);
				isContinue = false;
			}
		}
	}
}

void SetBoard(int board[][12], Player pl, Monster* mon, Oasis oa, HiddenBox* hb) // 게임보드 설정
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

void PrintBoard(int board[][12]) // 게임보드 출력
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
				printf("◎");
			}
			else if (board[i][j] == 2)
			{
				printf("＆");
			}
			else if (board[i][j] == 3)
			{
				printf("＠");
			}
			else if (board[i][j] == 4)
			{
				printf("★");
			}
			else if (board[i][j] == 5)
			{
				printf("♨");
			}
			else if (board[i][j] == 6)
			{
				printf("??");
			}
			else
			{
				printf("◆");
			}
		}
		printf("\n");
	}
	printf("\n");
}
