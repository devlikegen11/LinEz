#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "getch.h"
#define SIZE 50

#define MAXLEN 100
#define RANDNUM rand() % 100 + 1

typedef struct
{
  char name[20];
  int MonHP;
  int MonDam;
  int gold;
  int PlusHP;

} monster;

typedef struct
{
  char heroname[20];
  int heroHP;
  int heroDam;
  int gold;
  float PlusHP;
} named;

typedef struct
{
  char name[20];
  int BossHP;
  int BossDam;
  int gold;
  int PlusHP;
} Boss;

typedef struct
{
  int hp;
  int total_hp;
  int atk;
  int def[5];
  char clothes[5][30];
  char sword[30];
  int gold;
  int all_def;
} status;

struct Value
{
  int status;
  int tier;
  int stage;
  int count;
};
struct Defensive
{
  char name[40];
  int num;
  struct Value list;
};
struct Thing
{
  int plus_hp;
  int tier;
  int count;
};
struct medicine
{
  char name[40];
  int num;
  struct Thing rec;
};
struct other_It
{
  int count;
  int price;
};
struct items
{
  char name[40];
  int num;
  struct other_It cost;
};
struct Equip_Item
{
  int status;
  int tier;
  int inchants;
  int count;
};
struct Equip_Items
{
  char parts[40];
  char name[40];
  int num;
  struct Equip_Item each_parts;
};
struct S_Inventory
{
  char name[40];
  int num;
  int plus_up;
  int tier;
  int count;
};

struct Inventory
{
  char name[40];
  int num;
  int status;
  int tier;
  int stage;
  int count;
};

void moninfo(int, int, monster *);
void heroinfo(int, named *);
int attack(int, int, int, int);
int nomal(int, int, int);
int hard(int, int, int, int, int, int);
void boos1(int, Boss *);
void boos2(int, Boss *);
void boos3(int, Boss *);

void village(int stage, int x, int y, status *player_ptr, int **memory, int m_count, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr);

void dungeon1_4(int stage, int x, int y, status *player_ptr, int **memory, int m_count, int turn, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr);

void dungeon5(int, int, int, status *, int **, int, int, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr);

void battle(int stage, status *player_ptr, int turn, int **memory, int m_count, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr);

void store(int item_location, status *player_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct S_Inventory *s_bag_ptr);

void sanctuary(status *);
void smeleter(status *);
void weapon_li(struct Defensive *Weapon_ptr, struct Value *list_ptr);
void top_li(struct Defensive *Top_ptr, struct Value *list_ptr);
void foot_li(struct Defensive *Foot_ptr, struct Value *list_ptr);
void Hand_li(struct Defensive *Hand_ptr, struct Value *list_ptr);
void Shoulder_li(struct Defensive *Shoulder_ptr, struct Value *list_ptr);
void Mouth_li(struct Defensive *Mouth_ptr, struct Value *list_ptr);
void status_li(status *player_ptr, struct Equip_Items *parts_ptr, struct Equip_Item *ability_ptr);
void medicine_li(struct Thing *rec_ptr, struct medicine *potoin_ptr);
void items_li(struct items *item_ptr, struct other_It *cost_ptr);
void Equip_li(struct Equip_Items *parts, struct Equip_Item *ability_ptr);
void cl_get_2ti_20(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5);
void cl_get_3ti(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5);
void cl_get_4ti(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5);
void print_equip(struct Equip_Items *parts_ptr);
void put_on(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct S_Inventory *bags_ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2,
            struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5, status *player_ptr, struct Equip_Item *ability_ptr);
void upgrade_li(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Hand_ptr,
                struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Defensive *Foot_ptr, status *player_ptr, struct Equip_Item *ability_ptr);
void upgrade_elic(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Hand_ptr,
                  struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Defensive *Foot_ptr, status *player_ptr, struct Equip_Item *ability_ptr);

int main(void)
{
  srand(time(NULL));
  status player;
  status *player_ptr = &player;

  struct Defensive Weapon[5];
  struct Defensive *Weapon_ptr = Weapon;
  struct Defensive Top[5];
  struct Defensive *Top_ptr = Top;
  struct Defensive Foot[5];
  struct Defensive *Foot_ptr = Foot;
  struct Defensive Hand[5];
  struct Defensive *Hand_ptr = Hand;
  struct Defensive Shoulder[5];
  struct Defensive *Shoulder_ptr = Shoulder;
  struct Defensive Mouth[5];
  struct Defensive *Mouth_ptr = Mouth;
  struct medicine potion[4];
  struct medicine *potion_ptr = potion;
  struct Thing rec;
  struct Thing *rec_ptr = &rec;
  struct items item[5];
  struct items *item_ptr = item;
  struct other_It cost;
  struct other_It *cost_ptr = &cost;
  struct Value list;
  struct Value *list_ptr = &list;
  struct Inventory bag[100] = {{0}};
  struct Inventory *bag_ptr = &bag[0];
  struct S_Inventory s_bag[8] = {
      {"기본 물약", 30, 30, 1, 5}, {"주황 물약", 31, 50, 2, 1}, {"맑은 물약", 32, 70, 3, 1}, {"고농도 물약", 33, 150, 4, 1}, {"마을이동 주문서", 34, 0, 0, 1}, {"순간이동 주문서", 35, 0, 0, 5}, {"장비 강화 주문서", 34, 0, 0, 1}, {"엘릭서", 36, 0, 0, 1}};
  struct S_Inventory *s_bag_ptr = s_bag;
  struct Equip_Items parts[6];
  struct Equip_Items *parts_ptr = parts;
  struct Equip_Item ability = {0};
  struct Equip_Item *ability_ptr = &ability;

  weapon_li(Weapon_ptr, list_ptr);
  top_li(Top_ptr, list_ptr);
  foot_li(Foot_ptr, list_ptr);
  Shoulder_li(Shoulder_ptr, list_ptr);
  Mouth_li(Mouth_ptr, list_ptr);
  medicine_li(rec_ptr, potion_ptr);
  Equip_li(parts_ptr, ability_ptr);
  status_li(player_ptr, parts_ptr, ability_ptr);
  items_li(item_ptr, cost_ptr);

  printf("------------------------------------------------------------\n");
  printf("                    게임을 시작하겠습니다.\n");
  printf("------------------------------------------------------------\n");

  int height = 7, width = 3;
  int **memory;
  int m_count = 0;
  int i;
  int stage = 0;
  int x = 1, y = 1;
  int nowlen = 100;
  memory = (int **)malloc(sizeof(int *) * height);
  for (i = 0; i < height; i++)
  {
    memory[i] = (int *)malloc(sizeof(int) * width);
  }
  village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
  put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
  for (i = 0; i < height; i++)
  {
    free(memory[i]);
  }
  free(memory);
  return 0;
}

void village(int stage, int x, int y, status *player_ptr, int **memory, int m_count, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr)

{
  char control;
  char map[SIZE][SIZE];
  int k;
  int store_menu;
  int sanctuary_menu;
  int smeleter_menu;
  int turn = 0;
  int item_location = 0;
  int *item_lo_ptr = &item_location;

  while (1)
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        map[i][j] = ' ';
        map[0][j] = '/';
        map[i][0] = '/';
        map[49][j] = '/';
        map[i][49] = '/';

        for (k = 1; k < 10; k++)
        {
          map[k][45] = '|';
          map[k + 13][45] = '|';
          map[k + 26][45] = '|';
        }
        map[36][45] = '|';
        for (k = 45; k < 49; k++)
        {
          map[10][k] = '-';
          map[13][k] = '-';
          map[23][k] = '-';
          map[26][k] = '-';
          map[37][k] = '-';
        }

        char a[] = "store";
        for (k = 0; k < strlen(a); k++)
        {
          map[k + 3][47] = a[k];
        }

        char b[] = "sanctuary";
        for (k = 0; k < strlen(b); k++)
        {
          map[k + 14][47] = b[k];
        }

        char c[] = "smeleter";
        for (k = 0; k < strlen(c); k++)
        {
          map[k + 28][47] = c[k];
        }

        for (k = 45; k < 49; k++)
        {
          map[45][k] = '/';
        }
        for (k = 46; k < 49; k++)
        {
          map[k][45] = '/';
        }
        map[47][47] = '#';

        map[y][x] = '@';

        printf("%4c", map[i][j]);
      }

      printf("\n");
    }

    printf("마을입니다.\n");
    printf("w s a d로 조작하세요\nm: 순간이동주문서 좌표 저장, n: 순간이동주문서 사용\n");
    control = getch();
    printf("\n");
    if (control == 'w' && y > 1)
    {
      y = y - 1;
    }
    else if (control == 'a' && x > 1)
    {
      x = x - 1;
    }
    else if (control == 's' && y < SIZE - 2)
    {
      y = y + 1;
    }
    else if (control == 'd' && x < SIZE - 2)
    {
      x = x + 1;
    }
    else if (control == 'm')
    {
      char answer;
      printf("\n장소를 기억하시겠습니까?\nyes: y  no: n\n");
      answer = getchar();
      if (answer == 'y' || answer == 'Y')
      {
        if (m_count == 7)
        {
          printf("저장 가능한 공간이 없습니다.");
        }
        else
        {
          memory[m_count][0] = stage;
          memory[m_count][1] = x;
          memory[m_count][2] = y;
          printf("\nstage: %d,  x좌표: %d,  y좌표: %d\n", memory[m_count][0], memory[m_count][1], memory[m_count][2]);
          m_count++;
        }
      }
    }
    else if (control == 'n')
    {
      if (m_count > 0)
      {
        int number = 0;
        for (int i = 0; i < m_count; i++)
        {
          printf("%d. %d층(0층=마을), x좌표: %d, y좌표: %d\n", i + 1, memory[i][0], memory[i][1], memory[i][2]);
        }

        printf("어디로 이동하시겠습니까?\n");
        printf("선택할 번호: ");
        scanf("%d", &number);
        if (number <= m_count)
        {
          stage = memory[number - 1][0];

          if (stage == 0)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
          }
          else if (stage == 1 || stage == 2 || stage == 3 || stage == 4)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
          else if (stage == 5)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon5(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
        }
        else
        {
          printf("번호를 잘못 입력했습니다.\n");
        }
      }
    }
    else if (control == 'i')
    {
      printf("%s\n", bag_ptr[1].name);
      printf("인벤창을 열었습니다.\n");
      int nowlen = 100;
      put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
    }

    if (x == 45 && (y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 9))
    {
      store(item_location, player_ptr, bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, s_bag_ptr);
    }
    else if (x == 45 && (y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22))
    {
      sanctuary(player_ptr);
      printf("현재 용사의 체력은 %d", player_ptr->hp);
      printf("용사의 최대 체력은 %d입니다", player_ptr->total_hp);
      scanf("%d", &sanctuary_menu);
      if (sanctuary_menu == 1)
      {
        player_ptr->hp = player_ptr->total_hp;
        printf("회복시켜드렸습니다. 신의 가호가 함께하시길...\n");
      }
      else
      {
        printf("방문해주셔서 감사합니다.\n");
      }
      x -= 1;
    }
    else if (x == 45 && (y == 27 || y == 28 || y == 29 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36))
    {
      smeleter(player_ptr);
      printf("현재 소지금은 %d원 입니다\n", player_ptr->gold);
      printf("골라보게! : ");
      scanf("%d", &smeleter_menu);
      if (smeleter_menu == 1)
      {
        s_bag_ptr[6].count += 1;
      }
      else if (smeleter_menu == 2)
      {
        int num = 100;
        upgrade_li(num, parts_ptr, bag_ptr, Weapon_ptr, Top_ptr, Hand_ptr,
                   Shoulder_ptr, Mouth_ptr, Foot_ptr, player_ptr, ability_ptr);
      }
      else if (smeleter_menu == 3)
      {
        int num = 100;
        upgrade_elic(num, parts_ptr, bag_ptr, Weapon_ptr, Top_ptr, Hand_ptr,
                     Shoulder_ptr, Mouth_ptr, Foot_ptr, player_ptr, ability_ptr);
      }
      else
      {
        printf("다음에 또 오게.\n");
      }
      x -= 1;
    }
    else if (x == 45 && (y == 10 || y == 11 || y == 12 || y == 13 || y == 23 || y == 24 || y == 25 || y == 26))
    {
      x -= 1;
    }

    else if (y == 37 && (x == 45 || x == 46 || x == 47 || x == 48))
    {
      y += 1;
    }

    if (x == 47 && y == 47)
    {
      stage += 1;
      x = 1;
      y = 1;
      dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
    }
  }
}

void dungeon1_4(int stage, int x, int y, status *player_ptr, int **memory, int m_count, int turn, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr)
{
  char control;
  char map[SIZE][SIZE];
  int k;

  while (1)
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        map[i][j] = ' ';
        map[0][j] = '/';
        map[i][0] = '/';
        map[49][j] = '/';
        map[i][49] = '/';

        for (k = 1; k < 4; k++)
        {
          map[k][4] = '/';
          map[4][k] = '/';
        }
        map[4][4] = '/';
        map[2][2] = '#';

        for (k = 45; k < 49; k++)
        {
          map[45][k] = '/';
        }
        for (k = 46; k < 49; k++)
        {
          map[k][45] = '/';
        }
        map[47][47] = '#';

        map[y][x] = '@';

        printf("%4c", map[i][j]);
      }

      printf("\n");
    }

    printf("%d층 던전입니다.\n", stage);
    printf("w s a d로 조작하세요\nm: 순간이동주문서 좌표 저장, n: 순간이동주문서 사용\n");
    control = getch();
    printf("\n");
    if (control == 'w' && y > 1)
    {
      y = y - 1;
    }
    else if (control == 'a' && x > 1)
    {
      x = x - 1;
    }
    else if (control == 's' && y < SIZE - 2)
    {
      y = y + 1;
    }
    else if (control == 'd' && x < SIZE - 2)
    {
      x = x + 1;
    }
    else if (control == 'm')
    {
      char answer;
      printf("\n장소를 기억하시겠습니까?\nyes: y  no: n\n");
      answer = getchar();
      if (answer == 'y' || answer == 'Y')
      {
        if (m_count == 7)
        {
          printf("저장 가능한 공간이 없습니다.");
        }
        else
        {
          memory[m_count][0] = stage;
          memory[m_count][1] = x;
          memory[m_count][2] = y;
          printf("\nstage: %d,  x좌표: %d,  y좌표: %d\n", memory[m_count][0], memory[m_count][1], memory[m_count][2]);
          m_count++;
        }
      }
    }
    else if (control == 'n')
    {
      if (m_count > 0)
      {
        int number = 0;
        for (int i = 0; i < m_count; i++)
        {
          printf("%d. %d층(0층=마을), x좌표: %d, y좌표: %d\n", i + 1, memory[i][0], memory[i][1], memory[i][2]);
        }

        printf("어디로 이동하시겠습니까?\n");
        printf("선택할 번호: ");
        scanf("%d", &number);
        if (number <= m_count)
        {
          stage = memory[number - 1][0];

          if (stage == 0)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
          }
          else if (stage == 1 || stage == 2 || stage == 3 || stage == 4)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
          else if (stage == 5)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon5(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
        }
        else
        {
          printf("번호를 잘못 입력했습니다.\n");
        }
      }
    }
    else if (control == 'i')
    {
      printf("인벤창을 열었습니다.\n");
      int nowlen = 100;
      put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
    }

    if (x == 2 && y == 2)
    {
      stage -= 1;
      x = 46;
      y = 46;
      if (stage == 0)
      {
        village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
      }
      else
      {
        dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
      }
    }

    if (x == 47 && y == 47)
    {
      stage += 1;
      x = 1;
      y = 1;
      if (stage == 5)
      {
        dungeon5(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
      }
      else
      {
        dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
      }
    }
    turn++;
    if (turn > 5)
    {
      battle(stage, player_ptr, turn, memory, m_count, bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
      turn = 0;
    }
  }
}

void dungeon5(int stage, int x, int y, status *player_ptr, int **memory, int m_count, int turn, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct Inventory *bag_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr)
{
  char control;
  char map[SIZE][SIZE];
  int k;

  while (1)
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        map[i][j] = ' ';
        map[0][j] = '/';
        map[i][0] = '/';
        map[49][j] = '/';
        map[i][49] = '/';
        for (k = 1; k < 4; k++)
        {
          map[k][4] = '/';
          map[4][k] = '/';
        }
        map[4][4] = '/';
        map[2][2] = '#';
        map[y][x] = '@';
        printf("%4c", map[i][j]);
      }
      printf("\n");
    }
    printf("%d층 던전입니다.\n", stage);
    printf("w s a d로 조작하세요\nm: 순간이동주문서 좌표 저장, n: 순간이동주문서 사용\n");
    control = getch();
    printf("\n");
    if (control == 'w' && y > 1)
    {
      y = y - 1;
    }
    else if (control == 'a' && x > 1)
    {
      x = x - 1;
    }
    else if (control == 's' && y < SIZE - 2)
    {
      y = y + 1;
    }
    else if (control == 'd' && x < SIZE - 2)
    {
      x = x + 1;
    }
    else if (control == 'm')
    {
      char answer;
      printf("\n장소를 기억하시겠습니까?\nyes: y  no: n\n");
      answer = getchar();
      if (answer == 'y' || answer == 'Y')
      {
        if (m_count == 7)
        {
          printf("저장 가능한 공간이 없습니다.");
        }
        else
        {
          memory[m_count][0] = stage;
          memory[m_count][1] = x;
          memory[m_count][2] = y;
          printf("\nstage: %d,  x좌표: %d,  y좌표: %d\n", memory[m_count][0], memory[m_count][1], memory[m_count][2]);
          m_count++;
        }
      }
    }
    else if (control == 'n')
    {
      if (m_count > 0)
      {
        int number = 0;
        for (int i = 0; i < m_count; i++)
        {
          printf("%d. %d층(0층=마을), x좌표: %d, y좌표: %d\n", i + 1, memory[i][0], memory[i][1], memory[i][2]);
        }

        printf("어디로 이동하시겠습니까?\n");
        printf("선택할 번호: ");
        scanf("%d", &number);
        if (number <= m_count)
        {
          stage = memory[number - 1][0];

          if (stage == 0)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
          }
          else if (stage == 1 || stage == 2 || stage == 3 || stage == 4)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
          else if (stage == 5)
          {
            x = memory[number - 1][1];
            y = memory[number - 1][2];
            dungeon5(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
          }
        }
        else
        {
          printf("번호를 잘못 입력했습니다.\n");
        }
      }
    }
    else if (control == 'i')
    {
      printf("인벤창을 열었습니다.\n");
      int nowlen = 100;
      put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
    }
    if (x == 2 && y == 2)
    {
      stage -= 1;
      x = 46;
      y = 46;
      dungeon1_4(stage, x, y, player_ptr, memory, m_count, turn, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
    }
    battle(stage, player_ptr, turn, memory, m_count, bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, s_bag_ptr, parts_ptr, item_lo_ptr);
  }
}

int attack(int dam, int adam, int bdef, int hp)
{
  dam = adam - bdef;
  if (dam > 0)
  {
    hp -= dam;
    printf("      %d만큼 피해를 입혔습니다.\n", dam);
  }
  else
  {
    printf("회피!\n");
  }
  return hp;
}

int nomal(int met, int flg, int gen)
{
  if (met < 20 && gen > 0)
  {
    printf("일반 몬스터 등장!\n");
    flg = 1;
    gen--;
  }
  else if (met > 70 && met < 100)
  {
    printf("경쟁 용사가 싸움을 걸어왔다.\n");
    flg = 2;
  }
  return flg;
}

int hard(int mt, int fg, int Bdead1, int Bdead2, int Bdead3, int gen)
{
  if (mt < 20 && gen > 0)
  {
    printf("일반 몬스터 등장!\n");
    fg = 1;
    gen--;
  }

  else if (mt >= 30 && mt < 60)
  {
    printf("경쟁 용사의 결투신청!\n");
    fg = 2;
  }

  else if (mt >= 60 && mt < 80)
  {
    printf("이 느낌은?.\n");
    fg = 3;
    if (Bdead1 == 1)
    {
      printf("기분탓인가...n");
      fg = 2;
    }
  }

  else if (mt >= 80 && mt < 90 && Bdead1 == 1)
  {
    printf("이 느낌은??.\n");
    fg = 4;
    if (Bdead2 == 1)
    {
      printf("기분탓인가...\n");
      fg = 2;
    }
  }

  else if (mt >= 95 && mt < 100 && Bdead1 == 1 && Bdead2 == 1)
  {
    printf("이 느낌은???.\n");
    fg = 5;
    if (Bdead3 == 1)
    {
      printf("기분탓인가...\n");
      fg = 2;
    }
  }
  return fg;
}

void moninfo(int sta, int met, monster *nem)
{
  srand(time(NULL));
  if (sta == 1 && met < 40)
  {

    int hp = rand() % (100 - 50 + 1) + 50;
    int deal = rand() % (15 - 10 + 1) + 10;
    int gold = rand() % (30 - 5 + 1) + 5;
    int PlusHP = 0.01;
    monster Ork = {"오크", hp, deal, gold, PlusHP};
    *nem = Ork;
  }

  else if (sta == 2 && met < 40)
  {
    int hp = rand() % (180 - 50 + 1) + 50;
    int deal = rand() % (30 - 17 + 1) + 17;
    int gold = rand() % (60 - 5 + 1) + 5;
    int PlusHP = 0.02;
    monster ZOM = {"좀비", hp, deal, gold, PlusHP};
    *nem = ZOM;
  }

  else if (sta == 3 && met < 40)
  {
    int hp = rand() % (280 - 120 + 1) + 120;
    int deal = rand() % (45 - 20 + 1) + 20;
    int gold = rand() % (100 - 5 + 1) + 5;
    int PlusHP = 0.03;
    monster Ghoul = {"구울", hp, deal, gold, PlusHP};
    *nem = Ghoul;
  }

  else if (sta == 4 && met < 40)
  {
    int hp = rand() % (260 - 200 + 1) + 200;
    int deal = rand() % (55 - 28 + 1) + 28;
    int gold = rand() % (130 - 5 + 1) + 5;
    int PlusHP = 0.05;
    monster skeleton = {"해골", hp, deal, gold, PlusHP};
    *nem = skeleton;
  }

  else if (sta == 5 && met < 40)
  {
    int hp = rand() % (360 - 260 + 1) + 260;
    int deal = rand() % (75 - 32 + 1) + 32;
    int gold = rand() % (200 - 5 + 1) + 5;
    int PlusHP = 0.07;
    monster Spartoi = {"스파토이", hp, deal, gold, PlusHP};
    *nem = Spartoi;
  }
}

void heroinfo(int Php, named *nem)
{
  srand(time(NULL));
  char hero[27][10] =
      {
          "유시온", "김승수", "권철민", "안광민", "강진영", "김영곤", "박선후", "김건", "이준호", "이철", "이동준", "황은비", "조세빈", "김성근", "이은승", "박희정", "박장미", "김민아", "조대정", "김재신", "박민건", "임석현", "황운하", "노주영", "김혜빈", "서훈", "오은지"};
  int join = rand() % 27;
  strcpy(nem->heroname, hero[join]);
  nem->heroHP = Php * 2;
  nem->heroDam = rand() % (300 - 100 + 1) + 100;
  nem->gold = rand() % (500 - 5 + 1) + 5;
  nem->PlusHP = 0.2;
}

void boos1(int Php, Boss *nem)
{
  srand(time(NULL));
  int hp = Php * 5;
  int deal = rand() % (450 - 180 + 1) + 180;
  int gold = rand() % (700 - 5 + 1) + 5;
  int PlusHP = 0.3;
  Boss Boss1 = {"바포메트", hp, deal, gold, PlusHP};
  *nem = Boss1;
}

void boos2(int Php, Boss *nem)
{
  srand(time(NULL));
  int hp = Php * 7;
  int deal = rand() % (550 - 300 + 1) + 300;
  int gold = rand() % (1000 - 5 + 1) + 5;
  int PlusHP = 0.6;
  Boss Boss2 = {"이동녘", hp, deal, gold, PlusHP};
  *nem = Boss2;
}

void boos3(int Php, Boss *nem)
{
  srand(time(NULL));
  int hp = Php * 10;
  int deal = rand() % (1300 - 500 + 1) + 500;
  int gold = rand() % (3000 - 5 + 1) + 5;
  int PlusHP = 1;
  Boss Boss3 = {"류홍걸", hp, deal, gold, PlusHP};
  *nem = Boss3;
}

void battle(int stage, status *player_ptr, int turn, int **memory, int m_count, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Equip_Item *ability_ptr, struct S_Inventory *s_bag_ptr, struct Equip_Items *parts_ptr, int *item_lo_ptr)
{
  int menu;
  int Mondef = 0;
  int damage = 0;
  int meet;
  int Mongen = 10; 
  int flag = 0;
  int item, choose;
  char username[20] = "Boki";
  int BOSS_DEAD1 = 0, BOSS_DEAD2 = 0, BOSS_DEAD3 = 0; 

  while (1)
  {
    flag = 0; 

    if (stage >= 1 && stage < 5)
    {
      meet = rand() % 100;        
      flag = nomal(meet, flag, Mongen); 
      break;
    }

    else if (stage == 5)
    {
      meet = rand() % 100;                                          
      flag = hard(meet, flag, BOSS_DEAD1, BOSS_DEAD2, BOSS_DEAD3, Mongen);
      break;
    }
  }

  if (flag == 1)
  {
    monster set; 
    moninfo(stage, meet, &set); 
    printf("*************************************\n");
    printf("        %s와 조우했다!! \n", set.name);
    printf("        몬스터 체력: %d \n", set.MonHP);
    printf("        몬스터 공격력: %d \n", set.MonDam);
    printf("*************************************\n");
    while (1)
    {
      printf("메뉴\n");
      printf("1.공격, 2.아이템, 3.장비, 4.도망\n");
      scanf("%d", &menu);

      if (menu == 1) 
      {
        printf("*************************************\n");
        printf("            당신의 공격\n");
        set.MonHP = attack(damage, player_ptr->atk, Mondef, set.MonHP); 
        printf("        %s의 남은 체력 : %d\n", set.name, set.MonHP); 
        printf("*************************************\n");

        if (set.MonHP <= 0)
        {
          player_ptr->total_hp += player_ptr->total_hp * set.PlusHP;
          player_ptr->gold += set.gold;

          int home_scroll = rand() % (100 - 0 + 1) + 100;
          if (home_scroll < 21)
            s_bag_ptr[4].count += 1;

          if (set.name == "해골" || set.name == "스파토이")
          {
            item_lo_ptr += 1;
            cl_get_2ti_20(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          break;
        }

        printf("#####################################\n");
        printf("        %s의 공격\n", set.name);
        player_ptr->hp = attack(damage, set.MonDam, player_ptr->all_def, player_ptr->hp); 
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);              
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 2) 
      {
        printf("아이템 선택\n");
        printf("1. 물약, 2. 마을이동주문서, 3. 장비강화주문서, 4. 엘릭서\n");
        scanf("%d", &item);
        if (item == 1)
        {
          printf("1. 빨간물약, 2. 주황물약, 3. 맑은물약, 4. 고농도 물약\n");
          scanf("%d", &choose);
          if (choose == 1)
          {
            printf("체력회복\n");
            player_ptr->hp += 30;
            s_bag_ptr[0].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[0].count);
          }
          else if (choose == 2)
          {
            printf("체력회복\n");
            player_ptr->hp += 50;
            s_bag_ptr[1].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[1].count);
          }
          else if (choose == 3)
          {
            printf("체력회복\n");
            player_ptr->hp += 70;
            s_bag_ptr[2].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[2].count);
          }
          else if (choose == 4)
          {
            printf("체력회복\n");
            player_ptr->hp += 150;
            s_bag_ptr[3].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[3].count);
          }
        }
        else if (item == 2)
        {
          printf("마을이동 주문서 칸입니다\n");
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
        else if (item == 3)
        {
          printf("장비강화주문서 칸입니다\n");
        }
        else if (item == 4)
        {
          printf("엘릭서 칸입니다\n");
        }
        printf("#####################################\n");
        printf("        %s의 공격\n", set.name);
        player_ptr->hp = attack(damage, set.MonDam, player_ptr->all_def, player_ptr->hp);
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);            
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 3) 
      {
        int nowlen = 100;
        put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);

        printf("#####################################\n");
        printf("        %s의 공격\n", set.name);
        player_ptr->hp = attack(damage, set.MonDam, player_ptr->all_def, player_ptr->hp); 
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);                 
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1;
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 4) 
      {
        printf("도망!");
        printf("#####################################\n");
        printf("        %s의 공격\n", set.name);
        player_ptr->hp = attack(damage, set.MonDam, player_ptr->all_def, player_ptr->hp); 
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);                
        printf("#####################################\n");
        break;
      }
      if (stage == 1)
      {
        set.MonDam = rand() % (15 - 10 + 1) + 10;
      }
      else if (stage == 2)
      {
        set.MonDam = rand() % (30 - 17 + 1) + 17;
      }
      else if (stage == 3)
      {
        set.MonDam = rand() % (45 - 20 + 1) + 20;
      }
      else if (stage == 4)
      {
        set.MonDam = rand() % (55 - 28 + 1) + 28;
      }
      else if (stage == 5)
      {
        set.MonDam = rand() % (75 - 32 + 1) + 32;
      }
    }
  }

  else if (flag == 2)
  {
    named fight;
    heroinfo(player_ptr->hp, &fight); 
    printf("*************************************\n");
    printf("  네임드 \"%s\"를 조우 했습니다.\n", fight.heroname); 
    printf("        몬스터 체력: %d \n", fight.heroHP);
    printf("        몬스터 공격력: %d \n", fight.heroDam);
    printf("*************************************\n");
    while (1)
    {
      printf("메뉴\n");
      printf("1.공격, 2.아이템, 3.장비, 4.도망\n");
      scanf("%d", &menu);

      if (menu == 1) 
      {
        printf("*************************************\n");
        printf("            당신의 공격\n");
        fight.heroHP = attack(damage, player_ptr->atk, Mondef, fight.heroHP);  
        printf("        %s의 남은 체력 : %d\n", fight.heroname, fight.heroHP); 
        printf("*************************************\n");

        if (fight.heroHP <= 0)
        {
          player_ptr->total_hp += player_ptr->total_hp * fight.PlusHP;
          player_ptr->gold += fight.gold;

          item_lo_ptr += 1;
          cl_get_2ti_20(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          int get_3drop = rand() % 100;
          int telleport = rand() % 100;
          if (get_3drop < 99)
          {
            item_lo_ptr += 1;
            cl_get_3ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
            s_bag_ptr[4].count += 1;
            printf("아이템 습득!\n");
          }
          if (telleport < 99)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[5].count += a;
            printf("아이템 습득!222222\n");
          }
          break;
        }

        printf("#####################################\n");
        printf("        %s의 공격\n", fight.heroname);
        player_ptr->hp = attack(damage, fight.heroDam, player_ptr->all_def, player_ptr->hp);
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);                
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1;
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 2) 
      {
        printf("아이템 선택\n");
        printf("1. 물약, 2. 마을이동주문서, 3. 장비강화주문서, 4. 엘릭서\n");
        scanf("%d", &item);
        if (item == 1)
        {
          printf("1. 빨간물약, 2. 주황물약, 3. 맑은물약, 4. 고농도 물약\n");
          scanf("%d", &choose);
          if (choose == 1)
          {
            printf("체력회복\n");
            player_ptr->hp += 30;
            s_bag_ptr[0].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[0].count);
          }
          else if (choose == 2)
          {
            printf("체력회복\n");
            player_ptr->hp += 50;
            s_bag_ptr[1].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[1].count);
          }
          else if (choose == 3)
          {
            printf("체력회복\n");
            player_ptr->hp += 70;
            s_bag_ptr[2].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[2].count);
          }
          else if (choose == 4)
          {
            printf("체력회복\n");
            player_ptr->hp += 150;
            s_bag_ptr[3].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[3].count);
          }
        }
        else if (item == 2)
        {
          printf("마을이동 주문서 칸입니다\n");
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
        else if (item == 3)
        {
          printf("장비강화주문서 칸입니다\n");
        }
        else if (item == 4)
        {
          printf("엘릭서 칸입니다\n");
        }
        printf("#####################################\n");
        printf("        %s의 공격\n", fight.heroname);
        player_ptr->hp = attack(damage, fight.heroDam, player_ptr->all_def, player_ptr->hp); 
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);                  
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 3) 
      {
        int nowlen = 100;
        put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);

        printf("#####################################\n");
        printf("        %s의 공격\n", fight.heroname);
        player_ptr->hp = attack(damage, fight.heroDam, player_ptr->all_def, player_ptr->hp);
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);               
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 4) 
      {
        printf("도망!");
        printf("#####################################\n");
        printf("        %s의 공격\n", fight.heroname);
        player_ptr->hp = attack(damage, fight.heroDam, player_ptr->all_def, player_ptr->hp); 
        printf("      %s의 남은 체력 : %d\n", username, player_ptr->hp);                 
        printf("#####################################\n");
        break;
      }
      fight.heroDam = rand() % (300 - 100 + 1) + 100;
    }
  }

  else if (flag == 3)
  {
    Boss bosset;

    boos1(player_ptr->hp, &bosset);
    printf("*************************************\n");
    printf("        %s와 조우했다!! \n", bosset.name);
    printf("        몬스터 체력: %d \n", bosset.BossHP);
    printf("        몬스터 공격력: %d \n", bosset.BossDam);
    printf("*************************************\n");
    while (1)
    {
      printf("메뉴\n");
      printf("1.공격, 2.아이템, 3.장비, 4.도망\n");
      scanf("%d", &menu);

      if (menu == 1)
      {
        printf("*************************************\n");
        printf("            당신의 공격\n");
        bosset.BossHP = attack(damage, player_ptr->atk, Mondef, bosset.BossHP);  
        printf("            %s의 남은 체력 : %d\n", bosset.name, bosset.BossHP); 
        printf("*************************************\n");

        if (bosset.BossHP <= 0)
        {
          BOSS_DEAD1 = 1;
          player_ptr->total_hp += player_ptr->total_hp * bosset.PlusHP;
          player_ptr->gold += bosset.gold;
          int get_3drop = rand() % (100 - 0 + 1) + 100;
          int get_4drop = rand() % (100 - 0 + 1) + 100;
          int telleport = rand() % (100 - 0 + 1) + 100;
          if (get_3drop < 21)
          {
            item_lo_ptr += 1;
            cl_get_3ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          else if (get_4drop < 6)
          {
            item_lo_ptr += 1;
            cl_get_4ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          if (telleport < 31)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[5].count += a;
          }

          break;
        }

        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                 
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1;
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 2) 
      {
        printf("아이템 선택\n");
        printf("1. 물약, 2. 마을이동주문서, 3. 장비강화주문서, 4. 엘릭서\n");
        scanf("%d", &item);
        if (item == 1)
        {
          printf("1. 빨간물약, 2. 주황물약, 3. 맑은물약, 4. 고농도 물약\n");
          scanf("%d", &choose);
          if (choose == 1)
          {
            printf("체력회복\n");
            player_ptr->hp += 30;
            s_bag_ptr[0].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[0].count);
          }
          else if (choose == 2)
          {
            printf("체력회복\n");
            player_ptr->hp += 50;
            s_bag_ptr[1].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[1].count);
          }
          else if (choose == 3)
          {
            printf("체력회복\n");
            player_ptr->hp += 70;
            s_bag_ptr[2].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[2].count);
          }
          else if (choose == 4)
          {
            printf("체력회복\n");
            player_ptr->hp += 150;
            s_bag_ptr[3].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[3].count);
          }
        }
        else if (item == 2)
        {
          printf("마을이동 주문서 칸입니다\n");
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
        else if (item == 3)
        {
          printf("장비강화주문서 칸입니다\n");
        }
        else if (item == 4)
        {
          printf("엘릭서 칸입니다\n");
        }
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);              
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 3) 
      {
        int nowlen = 100;
        put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);               
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 4)
      {
        printf("도망!");
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp);
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);               
        printf("#####################################\n");
        break;
      }
      bosset.BossDam = rand() % (450 - 180 + 1) + 180; 
    }
  }

  else if (flag == 4)
  {
    Boss bosset;

    boos2(player_ptr->hp, &bosset);
    printf("*************************************\n");
    printf("        %s와 조우했다!! \n", bosset.name);
    printf("        몬스터 체력: %d \n", bosset.BossHP);
    printf("        몬스터 공격력: %d \n", bosset.BossDam);
    printf("*************************************\n");

    while (1)
    {
      printf("메뉴\n");
      printf("1.공격, 2.아이템, 3.장비, 4.도망\n");
      scanf("%d", &menu);

      if (menu == 1) 
      {
        printf("*************************************\n");
        printf("            당신의 공격\n");
        bosset.BossHP = attack(damage, player_ptr->atk, Mondef, bosset.BossHP);  
        printf("            %s의 남은 체력 : %d\n", bosset.name, bosset.BossHP); 
        printf("*************************************\n");

        if (bosset.BossHP <= 0)
        {
          BOSS_DEAD2 = 1;
          player_ptr->total_hp += player_ptr->total_hp * bosset.PlusHP;
          player_ptr->gold += bosset.gold;
          int get_3drop = rand() % (100 - 0 + 1) + 100;
          int get_4drop = rand() % (100 - 0 + 1) + 100;
          int telleport = rand() % (100 - 0 + 1) + 100;
          int elc = rand() % (100 - 0 + 1) + 100;
          if (get_3drop < 21)
          {
            item_lo_ptr += 1;
            cl_get_3ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          else if (get_4drop < 11)
          {
            item_lo_ptr += 1;
            cl_get_4ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          if (telleport < 31)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[5].count += a;
          }
          if (elc < 11)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[7].count += a;
          }
          break; 
        }

        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1;
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 2) 
      {
        printf("아이템 선택\n");
        printf("1. 물약, 2. 마을이동주문서, 3. 장비강화주문서, 4. 엘릭서\n");
        scanf("%d", &item);
        if (item == 1)
        {
          printf("1. 빨간물약, 2. 주황물약, 3. 맑은물약, 4. 고농도 물약\n");
          scanf("%d", &choose);
          if (choose == 1)
          {
            printf("체력회복\n");
            player_ptr->hp += 30;
            s_bag_ptr[0].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[0].count);
          }
          else if (choose == 2)
          {
            printf("체력회복\n");
            player_ptr->hp += 50;
            s_bag_ptr[1].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[1].count);
          }
          else if (choose == 3)
          {
            printf("체력회복\n");
            player_ptr->hp += 70;
            s_bag_ptr[2].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[2].count);
          }
          else if (choose == 4)
          {
            printf("체력회복\n");
            player_ptr->hp += 150;
            s_bag_ptr[3].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[3].count);
          }
        }
        else if (item == 2)
        {
          printf("마을이동 주문서 칸입니다\n");
          int stage = 0; 
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
        else if (item == 3)
        {
          printf("장비강화주문서 칸입니다\n");
        }
        else if (item == 4)
        {
          printf("엘릭서 칸입니다\n");
        }
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                 
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 3)
      {
        int nowlen = 100;
        put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 4) 
      {
        printf("도망!");
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp);
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                  
        printf("#####################################\n");
        break;
      }
      bosset.BossDam = rand() % (550 - 300 + 1) + 300;
    }
  }

  else if (flag == 5)
  {
    Boss bosset;

    boos3(player_ptr->hp, &bosset);
    printf("*************************************\n");
    printf("        %s와 조우했다!! \n", bosset.name);
    printf("        몬스터 체력: %d \n", bosset.BossHP);
    printf("        몬스터 공격력: %d \n", bosset.BossDam);
    printf("*************************************\n");
    while (1)
    {
      printf("메뉴\n");
      printf("1.공격, 2.아이템, 3.장비, 4.도망\n");
      scanf("%d", &menu);

      if (menu == 1) 
      {
        printf("*************************************\n");
        printf("            당신의 공격\n");
        bosset.BossHP = attack(damage, player_ptr->atk, Mondef, bosset.BossHP);  
        printf("            %s의 남은 체력 : %d\n", bosset.name, bosset.BossHP);
        printf("*************************************\n");

        if (bosset.BossHP <= 0)
        {
          BOSS_DEAD3 = 1;
          player_ptr->total_hp += player_ptr->total_hp * bosset.PlusHP;
          player_ptr->gold += bosset.gold;

          int get_3drop = rand() % (100 - 0 + 1) + 100;
          int get_4drop = rand() % (100 - 0 + 1) + 100;
          int telleport = rand() % (100 - 0 + 1) + 100;
          int elc = rand() % (100 - 0 + 1) + 100;
          if (get_3drop < 31)
          {
            item_lo_ptr += 1;
            cl_get_3ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          else if (get_4drop < 21)
          {
            item_lo_ptr += 1;
            cl_get_4ti(bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr);
          }
          if (telleport < 31)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[5].count += a;
          }
          if (elc < 21)
          {
            int a = rand() % (3 - 1 + 1) + 1;
            s_bag_ptr[7].count += a;
          }
          printf("*************************************\n");
          printf(" 축하합니다 던전 정복! 계속 토벌하세요! ");
          printf("*************************************\n");
          break; 
        }

        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);            
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1;
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 2) 
      {
        printf("아이템 선택\n");
        printf("1. 물약, 2. 마을이동주문서, 3. 장비강화주문서, 4. 엘릭서\n");
        scanf("%d", &item);
        if (item == 1)
        {
          printf("1. 빨간물약, 2. 주황물약, 3. 맑은물약, 4. 고농도 물약\n");
          scanf("%d", &choose);
          if (choose == 1)
          {
            printf("체력회복\n");
            player_ptr->hp += 30;
            s_bag_ptr[0].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[0].count);
          }
          else if (choose == 2)
          {
            printf("체력회복\n");
            player_ptr->hp += 50;
            s_bag_ptr[1].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[1].count);
          }
          else if (choose == 3)
          {
            printf("체력회복\n");
            player_ptr->hp += 70;
            s_bag_ptr[2].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[2].count);
          }
          else if (choose == 4)
          {
            printf("체력회복\n");
            player_ptr->hp += 150;
            s_bag_ptr[3].count -= 1;

            printf(" 빨간 물약을 사용하였으며, 남은 물약의 갯수는 %d 입니다.\n", s_bag_ptr[3].count);
          }
        }
        else if (item == 2)
        {
          printf("마을이동 주문서 칸입니다\n");
          int stage = 0; 
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
        else if (item == 3)
        {
          printf("장비강화주문서 칸입니다\n");
        }
        else if (item == 4)
        {
          printf("엘릭서 칸입니다\n");
        }
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);             
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 3) 
      {
        int nowlen = 100;
        put_on(nowlen, parts_ptr, bag_ptr, s_bag_ptr, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, player_ptr, ability_ptr);

        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp); 
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);            
        printf("#####################################\n");

        if (player_ptr->hp <= 0)
        {
          player_ptr->hp = player_ptr->total_hp * 0.1; 
          int stage = 0;
          int x = 1, y = 1;
          village(stage, x, y, player_ptr, memory, m_count, Weapon_ptr, Top_ptr, Foot_ptr, Hand_ptr, Shoulder_ptr, Mouth_ptr, ability_ptr, bag_ptr, s_bag_ptr, parts_ptr);
        }
      }
      else if (menu == 4) 
      {
        printf("도망!");
        printf("#####################################\n");
        printf("        %s의 공격\n", bosset.name);
        player_ptr->hp = attack(damage, bosset.BossDam, player_ptr->all_def, player_ptr->hp);
        printf("        %s의 남은 체력 : %d\n", username, player_ptr->hp);                
        printf("#####################################\n");
        break;
      }
    }
  }
}

void store(int item_location, status *player_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Foot_ptr, struct Defensive *Hand_ptr, struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct S_Inventory *s_bag_ptr)
{
  int n;
  printf("<< system :구매하실 상품을 선택해 주세요 >> \n");
  printf("[ 보유 gold : %d ]\n", player_ptr->gold);
  printf("1. %s \n2. %s \n3. %s \n4. %s \n5. %s \n 6. %s \n", Weapon_ptr[1].name, Top_ptr[1].name, Foot_ptr[1].name, "기본 장갑", Shoulder_ptr[1].name, Mouth_ptr[1].name);
  scanf("%d", &n);
  getchar();

  switch (n)
  {
  case 1:
    if (player_ptr->gold < 50)
      break;
    strcpy(bag_ptr[item_location].name, Weapon_ptr[1].name);
    bag_ptr[item_location].num = Weapon_ptr[1].num;
    bag_ptr[item_location].status = Weapon_ptr[1].list.status;
    bag_ptr[item_location].stage = Weapon_ptr[1].list.stage;
    bag_ptr[item_location].count = Weapon_ptr[1].list.count;
    bag_ptr[item_location].tier = Weapon_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", Weapon_ptr[1].name);
    player_ptr->gold -= 50;
    item_location += 1;
    break;
  case 2:
    if (player_ptr->gold < 30)
      strcpy(bag_ptr[item_location].name, Top_ptr[1].name);
    bag_ptr[item_location].num = Top_ptr[1].num;
    bag_ptr[item_location].status = Top_ptr[1].list.status;
    bag_ptr[item_location].stage = Top_ptr[1].list.stage;
    bag_ptr[item_location].count = Top_ptr[1].list.count;
    bag_ptr[item_location].tier = Top_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", Top_ptr[1].name);
    player_ptr->gold -= 30;
    item_location += 1;
    break;
  case 3:
    if (player_ptr->gold < 30)
      strcpy(bag_ptr[item_location].name, Foot_ptr[1].name);
    bag_ptr[item_location].num = Foot_ptr[1].num;
    bag_ptr[item_location].status = Foot_ptr[1].list.status;
    bag_ptr[item_location].stage = Foot_ptr[1].list.stage;
    bag_ptr[item_location].count = Foot_ptr[1].list.count;
    bag_ptr[item_location].tier = Foot_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", Foot_ptr[1].name);
    player_ptr->gold -= 30;
    item_location += 1;
    break;
  case 4:
    if (player_ptr->gold < 30)
      strcpy(bag_ptr[item_location].name, Hand_ptr[1].name);
    bag_ptr[item_location].num = Hand_ptr[1].num;
    bag_ptr[item_location].status = Hand_ptr[1].list.status;
    bag_ptr[item_location].stage = Hand_ptr[1].list.stage;
    bag_ptr[item_location].count = Hand_ptr[1].list.count;
    bag_ptr[item_location].tier = Hand_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", "기본 장갑");
    player_ptr->gold -= 30;
    item_location += 1;
    break;
  case 5:
    if (player_ptr->gold < 30)
      break;
    strcpy(bag_ptr[item_location].name, Shoulder_ptr[1].name);
    bag_ptr[item_location].num = Shoulder_ptr[1].num;
    bag_ptr[item_location].status = Shoulder_ptr[1].list.status;
    bag_ptr[item_location].stage = Shoulder_ptr[1].list.stage;
    bag_ptr[item_location].count = Shoulder_ptr[1].list.count;
    bag_ptr[item_location].tier = Shoulder_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", Shoulder_ptr[1].name);
    player_ptr->gold -= 30;
    item_location += 1;
    break;
  case 6:
    if (player_ptr->gold < 30)
      break;
    strcpy(bag_ptr[item_location].name, Mouth_ptr[1].name);
    bag_ptr[item_location].num = Mouth_ptr[1].num;
    bag_ptr[item_location].status = Mouth_ptr[1].list.status;
    bag_ptr[item_location].stage = Mouth_ptr[1].list.stage;
    bag_ptr[item_location].count = Mouth_ptr[1].list.count;
    bag_ptr[item_location].tier = Mouth_ptr[1].list.tier;
    printf("%s을 구입하셨습니다.\n", Mouth_ptr[1].name);
    player_ptr->gold -= 30;
    item_location += 1;
    break;
  case 7:
    if (player_ptr->gold < 30)
      s_bag_ptr[0].count += 1;
    printf("%s을 구입하셨습니다.\n", s_bag_ptr[0].name);
    player_ptr->gold -= 30;
    break;
  }
}

void sanctuary(status *player_ptr)
{
  printf("╔════════════════════════════════════════════════════════════════════════╗\n");
  printf("            성직자 : 반갑습니다 용사님 체력회복이 필요하신가요?\n");
  printf("╚════════════════════════════════════════════════════════════════════════╝\n");
  printf("                          1. 체력회복\n ");
  printf("                          2. 나가기\n ");
}

void smeleter(status *player_ptr)
{
  printf("╔════════════════════════════════════════════════════════════════════════╗\n");
  printf("            드워프 : 제련소에 온걸 환영하네 뭘 도와줄까\n");
  printf("╚════════════════════════════════════════════════════════════════════════╝\n");
  printf("                          1. 장비강화주문서\n ");
  printf("                          2. 강화\n ");
  printf("                          3. 엘릭서\n ");
  printf("                          4. 나가기\n ");
}

void upgrade_li(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Hand_ptr,
                struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Defensive *Foot_ptr, status *player_ptr, struct Equip_Item *ability_ptr)
{

  system("clear");
  getchar();
  int j = 0;
  int i = 0;
  int up_choose = 0;
  int arr[40] = {};
  puts("\n<<system: 강화 필요한 장비를 선택해 주세요>>\n\n1 . 무기\n2 . 갑옷\n3 . 신발\n4 . 장갑\n5 . 망토\n6 . 마스크 \n");
  int ingame = 0;
  scanf("%d", &ingame);
  getchar();
  switch (ingame)
  {
    system("clear");
  case 1:
    system("clear");
    puts("소지하고 있는 무기의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (0 < bag_ptr[i].num && bag_ptr[i].num < 5)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (공격력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;  

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0; 
              bag_ptr[arr[i]].status = 0; 
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }
            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 2:
    system("clear");
    puts("소지하고 있는 갑옷의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (5 < bag_ptr[i].num && bag_ptr[i].num < 10)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;   

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0; 
              bag_ptr[arr[i]].status = 0; 
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }
            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 3:
    system("clear");
    puts("소지하고 있는 신발의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (10 < bag_ptr[i].num && bag_ptr[i].num < 15)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier; 
      char ch;
      int maxluck;
      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1;
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0; 
              bag_ptr[arr[i]].status = 0; 
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }
            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 4:
    system("clear");
    puts("소지하고 있는 장갑의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (15 < bag_ptr[i].num && bag_ptr[i].num < 20)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;  

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0;  
              bag_ptr[arr[i]].status = 0; 
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }
            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break;
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 5:
    system("clear");
    puts("소지하고 있는 망토의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (20 < bag_ptr[i].num && bag_ptr[i].num < 25)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status;
      bag_ptr[arr[i]].tier;   
      char ch;
      int maxluck;
      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0; 
              bag_ptr[arr[i]].status = 0;
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }
            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 6:
    system("clear");
    puts("소지하고 있는 마스크의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (25 < bag_ptr[i].num && bag_ptr[i].num < 30)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;   

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold > 50)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~20사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 21)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
            else
            {
              printf("실패..\n");
              strcpy(bag_ptr[arr[i]].name, "장비 부스러기");
              bag_ptr[arr[i]].stage = 0;  
              bag_ptr[arr[i]].status = 0; 
              bag_ptr[arr[i]].tier = 0;
              bag_ptr[arr[i]].num = 99;
              bag_ptr[arr[i]].count = 1;
            }

            player_ptr->gold -= 10;
          }
          else
          {
            printf("돈이 부족합니다.\n");
            break;
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break;
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  }
}

void put_on(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct S_Inventory *bags_ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5, status *player_ptr, struct Equip_Item *ability_ptr)
{
  struct Defensive temp = {"장비 없음", 0, {0, 0, 0, 0}};
  int ingame;
  int sel;
  int a;
  int arr[40] = {};

  printf("1. 상태창\n2. 인벤\n3. 장비\n");
  scanf("%d", &ingame);
  printf("%s 1 \n", bag_ptr[0].name);
  if (ingame == 1)
  {
    system("clear");

    player_ptr->atk = parts_ptr[0].each_parts.status;
    player_ptr->def[0] = parts_ptr[1].each_parts.status; 
    player_ptr->def[1] = parts_ptr[2].each_parts.status;
    player_ptr->def[2] = parts_ptr[3].each_parts.status;
    player_ptr->def[3] = parts_ptr[4].each_parts.status;
    player_ptr->all_def = (player_ptr->def[0] + player_ptr->def[1] + player_ptr->def[2] + player_ptr->def[3]);

    printf("\n [ 현재 유저 스텍 ]\n");
    printf("----------------------\n");
    printf(" HP     : %d \n", player_ptr->hp);
    printf(" 공격력 :  %d \n", player_ptr->atk);
    printf(" 방어력 :  %d \n", player_ptr->all_def);
    printf(" GOLD   : %d \n", player_ptr->gold);
    printf("----------------------\n\n");
    printf("\n [ 현재 장착 장비 ]\n");
    printf("---------------------------------------------------------\n");
    print_equip(parts_ptr);
    printf("---------------------------------------------------------\n");
  }
  else if (ingame == 2) 
  {
    system("clear");
    int j = 0;

    printf("\n [ 현재 소유 아이템 ]\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
      printf(" %d .  %s : (보유 수량 : %d 개) \n", i + 1, bags_ptr[i].name, bags_ptr[i].count);
      arr[j] = i;
      j++;
    }
    printf("---------------------------------------------------------\n");
  }
  else if (ingame == 3) 
  {
    system("clear");
    getchar();
    int j = 0;
    int i = 0;
    puts("\n<<system: 장착 필요한 장비를 입력해 주세요>>\n\n1 . 무기\n2 . 갑옷\n3 . 신발\n4 . 장갑\n5 . 망토\n6 . 마스크 \n");
    printf("\n\n [ 현재 장착 장비 ]\n");
    printf("---------------------------------------------------------\n");
    print_equip(parts_ptr);
    printf("---------------------------------------------------------\n\n");
    scanf("%d", &ingame);
    getchar();
    switch (ingame)
    {
      system("clear");
    case 1:
      system("clear");
      printf("%s 1 \n", bag_ptr[1].name);
      puts("소지하고 있는 무기의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (0 < bag_ptr[i].num && bag_ptr[i].num < 5)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (공격력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 무기를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {
        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[0].name);
          bag_ptr[arr[i]].num = parts_ptr[0].num;
          bag_ptr[arr[i]].stage = parts_ptr[0].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[0].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[0].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[0].each_parts.count;

          strcpy(parts_ptr[0].name, temp.name);
          parts_ptr[0].num = temp.num;
          parts_ptr[0].each_parts.inchants = temp.list.stage;
          parts_ptr[0].each_parts.status = temp.list.status;
          parts_ptr[0].each_parts.count = temp.list.count;
          parts_ptr[0].each_parts.tier = temp.list.tier;
        }
      }
      break;
    case 2:
      system("clear");
      puts("소지하고 있는 갑옷의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (5 < bag_ptr[i].num && bag_ptr[i].num < 10)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 방어구를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {
        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[1].name);
          bag_ptr[arr[i]].num = parts_ptr[1].num;
          bag_ptr[arr[i]].stage = parts_ptr[1].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[1].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[1].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[1].each_parts.count;

          strcpy(parts_ptr[1].name, temp.name);
          parts_ptr[1].num = temp.num;
          parts_ptr[1].each_parts.inchants = temp.list.stage;
          parts_ptr[1].each_parts.status = temp.list.status;
          parts_ptr[1].each_parts.count = temp.list.count;
          parts_ptr[1].each_parts.tier = temp.list.tier;
        }
      }
      break;
    case 3:
      system("clear");
      puts("소지하고 있는 신발의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (10 < bag_ptr[i].num && bag_ptr[i].num < 15)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 방어구를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {
        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[2].name);
          bag_ptr[arr[i]].num = parts_ptr[2].num;
          bag_ptr[arr[i]].stage = parts_ptr[2].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[2].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[2].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[2].each_parts.count;

          strcpy(parts_ptr[2].name, temp.name);
          parts_ptr[2].num = temp.num;
          parts_ptr[2].each_parts.inchants = temp.list.stage;
          parts_ptr[2].each_parts.status = temp.list.status;
          parts_ptr[2].each_parts.count = temp.list.count;
          parts_ptr[2].each_parts.tier = temp.list.tier;
        }
      }
      break;
    case 4:
      system("clear");
      puts("소지하고 있는 장갑의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (15 < bag_ptr[i].num && bag_ptr[i].num < 20)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 방어구를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {
        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[3].name);
          bag_ptr[arr[i]].num = parts_ptr[3].num;
          bag_ptr[arr[i]].stage = parts_ptr[3].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[3].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[3].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[3].each_parts.count;

          strcpy(parts_ptr[3].name, temp.name);
          parts_ptr[3].num = temp.num;
          parts_ptr[3].each_parts.inchants = temp.list.stage;
          parts_ptr[3].each_parts.status = temp.list.status;
          parts_ptr[3].each_parts.count = temp.list.count;
          parts_ptr[3].each_parts.tier = temp.list.tier;
        }
      }
      break;
    case 5:
      system("clear");
      puts("소지하고 있는 망토의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (20 < bag_ptr[i].num && bag_ptr[i].num < 25)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 방어구를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {

        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[4].name);
          bag_ptr[arr[i]].num = parts_ptr[4].num;
          bag_ptr[arr[i]].stage = parts_ptr[4].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[4].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[4].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[4].each_parts.count;

          strcpy(parts_ptr[4].name, temp.name);
          parts_ptr[4].num = temp.num;
          parts_ptr[4].each_parts.inchants = temp.list.stage;
          parts_ptr[4].each_parts.status = temp.list.status;
          parts_ptr[4].each_parts.count = temp.list.count;
          parts_ptr[4].each_parts.tier = temp.list.tier;
        }
      }
      break;
    case 6:
      system("clear");
      puts("소지하고 있는 마스크의 종류는 다음과 같습니다.\n");
      for (int i = 0; i < num; i++)
      {
        if (25 < bag_ptr[i].num && bag_ptr[i].num < 30)
        {
          arr[j] = i;
          printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
          j++;
        }
      }
      puts("장착하실 방어구를 선택해 주세요.");
      scanf("%d", &a);
      for (int i = 0; i < j; i++)
      {

        if (a == i + 1)
        {
          strcpy(temp.name, bag_ptr[arr[i]].name);
          temp.num = bag_ptr[arr[i]].num;
          temp.list.stage = bag_ptr[arr[i]].stage;
          temp.list.status = bag_ptr[arr[i]].status;
          temp.list.tier = bag_ptr[arr[i]].tier;
          temp.list.count = bag_ptr[arr[i]].count;

          strcpy(bag_ptr[arr[i]].name, parts_ptr[5].name);
          bag_ptr[arr[i]].num = parts_ptr[5].num;
          bag_ptr[arr[i]].stage = parts_ptr[5].each_parts.inchants;
          bag_ptr[arr[i]].status = parts_ptr[5].each_parts.status;
          bag_ptr[arr[i]].tier = parts_ptr[5].each_parts.tier;
          bag_ptr[arr[i]].count = parts_ptr[5].each_parts.count;

          strcpy(parts_ptr[5].name, temp.name);
          parts_ptr[5].num = temp.num;
          parts_ptr[5].each_parts.inchants = temp.list.stage;
          parts_ptr[5].each_parts.status = temp.list.status;
          parts_ptr[5].each_parts.count = temp.list.count;
          parts_ptr[5].each_parts.tier = temp.list.tier;
        }
      }
      break;
    }
  }
}

void print_equip(struct Equip_Items *parts_ptr)
{
  for (int i = 0; i < 6; i++)
  {
    if (i == 0)
      printf("%s : +%d 강 %s (공격력 : %d)\n", parts_ptr[i].parts, parts_ptr[i].each_parts.inchants, parts_ptr[i].name, parts_ptr[i].each_parts.status);

    else
      printf("%s : +%d 강 %s (방어력 : %d)\n", parts_ptr[i].parts, parts_ptr[i].each_parts.inchants, parts_ptr[i].name, parts_ptr[i].each_parts.status);
  }
}
void cl_get_2ti_20(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5) 
{
  int sizelen = sizeof ptr / sizeof ptr[0];
  if (0 < RANDNUM && RANDNUM <= 20)
  {
    int i = 2;
    int random_num = rand() % 6 + 1;
    switch (random_num)
    {
    case 1:
    {
      strcpy(ptr[sizelen].name, ptr0[i].name);
      ptr[sizelen].num = ptr0[i].num;
      ptr[sizelen].stage = ptr0[i].list.stage;
      ptr[sizelen].status = ptr0[i].list.status;
      ptr[sizelen].tier = ptr0[i].list.tier;
      ptr[sizelen].count = ptr0[i].list.count;
      break;
    }

    case 2:
    {
      strcpy(ptr[sizelen].name, ptr1[i].name);
      ptr[sizelen].num = ptr1[i].num;
      ptr[sizelen].stage = ptr1[i].list.stage;
      ptr[sizelen].status = ptr1[i].list.status;
      ptr[sizelen].tier = ptr1[i].list.tier;
      ptr[sizelen].count = ptr1[i].list.count;
      break;
    }
    case 3:
    {
      strcpy(ptr[sizelen].name, ptr2[i].name);
      ptr[sizelen].num = ptr2[i].num;
      ptr[sizelen].stage = ptr2[i].list.stage;
      ptr[sizelen].status = ptr2[i].list.status;
      ptr[sizelen].tier = ptr2[i].list.tier;
      ptr[sizelen].count = ptr2[i].list.count;
      break;
    }
    case 4:
    {
      strcpy(ptr[sizelen].name, ptr3[i].name);
      ptr[sizelen].num = ptr3[i].num;
      ptr[sizelen].stage = ptr3[i].list.stage;
      ptr[sizelen].status = ptr3[i].list.status;
      ptr[sizelen].tier = ptr3[i].list.tier;
      ptr[sizelen].count = ptr3[i].list.count;
      break;
    }
    case 5:
    {
      strcpy(ptr[sizelen].name, ptr4[i].name);
      ptr[sizelen].num = ptr4[i].num;
      ptr[sizelen].stage = ptr4[i].list.stage;
      ptr[sizelen].status = ptr4[i].list.status;
      ptr[sizelen].tier = ptr4[i].list.tier;
      ptr[sizelen].count = ptr4[i].list.count;
      break;
    }
    case 6:
    {
      strcpy(ptr[sizelen].name, ptr5[i].name);
      ptr[sizelen].num = ptr5[i].num;
      ptr[sizelen].stage = ptr5[i].list.stage;
      ptr[sizelen].status = ptr5[i].list.status;
      ptr[sizelen].tier = ptr5[i].list.tier;
      ptr[sizelen].count = ptr5[i].list.count;
      break;
    }
    }
  }
}
void cl_get_3ti(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5) 
{
  int sizelen = sizeof ptr / sizeof ptr[0];

  int i = 3;
  int random_num = rand() % 6 + 1;
  switch (random_num)
  {
  case 1:
  {
    strcpy(ptr[sizelen].name, ptr0[i].name);
    ptr[sizelen].num = ptr0[i].num;
    ptr[sizelen].stage = ptr0[i].list.stage;
    ptr[sizelen].status = ptr0[i].list.status;
    ptr[sizelen].tier = ptr0[i].list.tier;
    ptr[sizelen].count = ptr0[i].list.count;
    break;
  }

  case 2:
  {
    strcpy(ptr[sizelen].name, ptr1[i].name);
    ptr[sizelen].num = ptr1[i].num;
    ptr[sizelen].stage = ptr1[i].list.stage;
    ptr[sizelen].status = ptr1[i].list.status;
    ptr[sizelen].tier = ptr1[i].list.tier;
    ptr[sizelen].count = ptr1[i].list.count;
    break;
  }
  case 3:
  {
    strcpy(ptr[sizelen].name, ptr2[i].name);
    ptr[sizelen].num = ptr2[i].num;
    ptr[sizelen].stage = ptr2[i].list.stage;
    ptr[sizelen].status = ptr2[i].list.status;
    ptr[sizelen].tier = ptr2[i].list.tier;
    ptr[sizelen].count = ptr2[i].list.count;
    break;
  }
  case 4:
  {
    strcpy(ptr[sizelen].name, ptr3[i].name);
    ptr[sizelen].num = ptr3[i].num;
    ptr[sizelen].stage = ptr3[i].list.stage;
    ptr[sizelen].status = ptr3[i].list.status;
    ptr[sizelen].tier = ptr3[i].list.tier;
    ptr[sizelen].count = ptr3[i].list.count;
    break;
  }
  case 5:
  {
    strcpy(ptr[sizelen].name, ptr4[i].name);
    ptr[sizelen].num = ptr4[i].num;
    ptr[sizelen].stage = ptr4[i].list.stage;
    ptr[sizelen].status = ptr4[i].list.status;
    ptr[sizelen].tier = ptr4[i].list.tier;
    ptr[sizelen].count = ptr4[i].list.count;
    break;
  }
  case 6:
  {
    strcpy(ptr[sizelen].name, ptr5[i].name);
    ptr[sizelen].num = ptr5[i].num;
    ptr[sizelen].stage = ptr5[i].list.stage;
    ptr[sizelen].status = ptr5[i].list.status;
    ptr[sizelen].tier = ptr5[i].list.tier;
    ptr[sizelen].count = ptr5[i].list.count;
    break;
  }
  }
}
void cl_get_4ti(struct Inventory *ptr, struct Defensive *ptr0, struct Defensive *ptr1, struct Defensive *ptr2, struct Defensive *ptr3, struct Defensive *ptr4, struct Defensive *ptr5) 
{
  int sizelen = sizeof ptr / sizeof ptr[0];

  int i = 2;
  int random_num = rand() % 6 + 1;
  switch (random_num)
  {
  case 1:
  {
    strcpy(ptr[sizelen].name, ptr0[i].name);
    ptr[sizelen].num = ptr0[i].num;
    ptr[sizelen].stage = ptr0[i].list.stage;
    ptr[sizelen].status = ptr0[i].list.status;
    ptr[sizelen].tier = ptr0[i].list.tier;
    ptr[sizelen].count = ptr0[i].list.count;
    break;
  }

  case 2:
  {
    strcpy(ptr[sizelen].name, ptr1[i].name);
    ptr[sizelen].num = ptr1[i].num;
    ptr[sizelen].stage = ptr1[i].list.stage;
    ptr[sizelen].status = ptr1[i].list.status;
    ptr[sizelen].tier = ptr1[i].list.tier;
    ptr[sizelen].count = ptr1[i].list.count;
    break;
  }
  case 3:
  {
    strcpy(ptr[sizelen].name, ptr2[i].name);
    ptr[sizelen].num = ptr2[i].num;
    ptr[sizelen].stage = ptr2[i].list.stage;
    ptr[sizelen].status = ptr2[i].list.status;
    ptr[sizelen].tier = ptr2[i].list.tier;
    ptr[sizelen].count = ptr2[i].list.count;
    break;
  }
  case 4:
  {
    strcpy(ptr[sizelen].name, ptr3[i].name);
    ptr[sizelen].num = ptr3[i].num;
    ptr[sizelen].stage = ptr3[i].list.stage;
    ptr[sizelen].status = ptr3[i].list.status;
    ptr[sizelen].tier = ptr3[i].list.tier;
    ptr[sizelen].count = ptr3[i].list.count;
    break;
  }
  case 5:
  {
    strcpy(ptr[sizelen].name, ptr4[i].name);
    ptr[sizelen].num = ptr4[i].num;
    ptr[sizelen].stage = ptr4[i].list.stage;
    ptr[sizelen].status = ptr4[i].list.status;
    ptr[sizelen].tier = ptr4[i].list.tier;
    ptr[sizelen].count = ptr4[i].list.count;
    break;
  }
  case 6:
  {
    strcpy(ptr[sizelen].name, ptr5[i].name);
    ptr[sizelen].num = ptr5[i].num;
    ptr[sizelen].stage = ptr5[i].list.stage;
    ptr[sizelen].status = ptr5[i].list.status;
    ptr[sizelen].tier = ptr5[i].list.tier;
    ptr[sizelen].count = ptr5[i].list.count;
    break;
  }
  }
}
void weapon_li(struct Defensive *Weapon_ptr, struct Value *list_ptr)
{
  strcpy(Weapon_ptr[0].name, "맨 손");
  Weapon_ptr[0].num = 0;
  Weapon_ptr[0].list.status = 0;
  Weapon_ptr[0].list.stage = 0;
  Weapon_ptr[0].list.tier = 0;
  Weapon_ptr[0].list.count = 0;

  strcpy(Weapon_ptr[1].name, "기본 검");
  Weapon_ptr[1].num = 1;
  Weapon_ptr[1].list.status = 2;
  Weapon_ptr[1].list.stage = 0;
  Weapon_ptr[1].list.tier = 1;
  Weapon_ptr[1].list.count = 0;

  strcpy(Weapon_ptr[2].name, "장검");
  Weapon_ptr[2].num = 2;
  Weapon_ptr[2].list.status = 5;
  Weapon_ptr[2].list.stage = 0;
  Weapon_ptr[2].list.tier = 2;
  Weapon_ptr[2].list.count = 0;

  strcpy(Weapon_ptr[3].name, "일본도");
  Weapon_ptr[3].num = 3;
  Weapon_ptr[3].list.status = 10;
  Weapon_ptr[3].list.stage = 0;
  Weapon_ptr[3].list.tier = 3;
  Weapon_ptr[3].list.count = 0;

  strcpy(Weapon_ptr[4].name, "싸울아비 장검");
  Weapon_ptr[4].num = 4;
  Weapon_ptr[4].list.status = 20;
  Weapon_ptr[4].list.stage = 0;
  Weapon_ptr[4].list.tier = 4;
  Weapon_ptr[4].list.count = 0;
}
void top_li(struct Defensive *Top_ptr, struct Value *list_ptr)
{
  strcpy(Top_ptr[0].name, "맨 몸");
  Top_ptr[0].num = 5;
  Top_ptr[0].list.status = 0;
  Top_ptr[0].list.stage = 0;
  Top_ptr[0].list.tier = 0;
  Top_ptr[0].list.count = 0;

  strcpy(Top_ptr[1].name, "기본 갑빠");
  Top_ptr[1].num = 6;
  Top_ptr[1].list.status = 1;
  Top_ptr[1].list.stage = 0;
  Top_ptr[1].list.tier = 1;
  Top_ptr[1].list.count = 0;

  strcpy(Top_ptr[2].name, "반팔 갑빠");
  Top_ptr[2].num = 7;
  Top_ptr[2].list.status = 4;
  Top_ptr[2].list.stage = 0;
  Top_ptr[2].list.tier = 2;
  Top_ptr[2].list.count = 0;

  strcpy(Top_ptr[3].name, "후드 갑빠");
  Top_ptr[3].num = 8;
  Top_ptr[3].list.status = 8;
  Top_ptr[3].list.stage = 0;
  Top_ptr[3].list.tier = 3;
  Top_ptr[3].list.count = 0;

  strcpy(Top_ptr[4].name, "용 갑빠");
  Top_ptr[4].num = 9;
  Top_ptr[4].list.status = 13;
  Top_ptr[4].list.stage = 0;
  Top_ptr[4].list.tier = 4;
  Top_ptr[4].list.count = 0;
}
void foot_li(struct Defensive *Foot_ptr, struct Value *list_ptr)
{
  strcpy(Foot_ptr[0].name, "맨 발");
  Foot_ptr[0].num = 10;
  Foot_ptr[0].list.status = 0;
  Foot_ptr[0].list.stage = 0;
  Foot_ptr[0].list.tier = 0;
  Foot_ptr[0].list.count = 0;

  strcpy(Foot_ptr[1].name, "기본 장화");
  Foot_ptr[1].num = 11;
  Foot_ptr[1].list.status = 1;
  Foot_ptr[1].list.stage = 0;
  Foot_ptr[1].list.tier = 1;
  Foot_ptr[1].list.count = 0;

  strcpy(Foot_ptr[2].name, "슬리퍼");
  Foot_ptr[2].num = 12;
  Foot_ptr[2].list.status = 4;
  Foot_ptr[2].list.stage = 0;
  Foot_ptr[2].list.tier = 2;
  Foot_ptr[2].list.count = 0;

  strcpy(Foot_ptr[3].name, "운동화");
  Foot_ptr[3].num = 13;
  Foot_ptr[3].list.status = 8;
  Foot_ptr[3].list.stage = 0;
  Foot_ptr[3].list.tier = 3;
  Foot_ptr[3].list.count = 0;

  strcpy(Foot_ptr[4].name, "에어조단");
  Foot_ptr[4].num = 14;
  Foot_ptr[4].list.status = 13;
  Foot_ptr[4].list.stage = 0;
  Foot_ptr[4].list.tier = 4;
  Foot_ptr[4].list.count = 0;
}
void Hand_li(struct Defensive *Hand_ptr, struct Value *list_ptr)
{
  strcpy(Hand_ptr[0].name, "맨 손");
  Hand_ptr[0].num = 15;
  Hand_ptr[0].list.status = 0;
  Hand_ptr[0].list.stage = 0;
  Hand_ptr[0].list.tier = 0;
  Hand_ptr[0].list.count = 0;

  strcpy(Hand_ptr[1].name, "기본 장갑");
  Hand_ptr[1].num = 16;
  Hand_ptr[1].list.status = 1;
  Hand_ptr[1].list.stage = 0;
  Hand_ptr[1].list.tier = 1;
  Hand_ptr[1].list.count = 0;

  strcpy(Hand_ptr[2].name, "고무 장갑");
  Hand_ptr[2].num = 17;
  Hand_ptr[2].list.status = 4;
  Hand_ptr[2].list.stage = 0;
  Hand_ptr[2].list.tier = 2;
  Hand_ptr[2].list.count = 0;

  strcpy(Hand_ptr[3].name, "면 장갑");
  Hand_ptr[3].num = 18;
  Hand_ptr[3].list.status = 8;
  Hand_ptr[3].list.stage = 0;
  Hand_ptr[3].list.tier = 3;
  Hand_ptr[3].list.count = 0;

  strcpy(Hand_ptr[4].name, "가죽 장갑");
  Hand_ptr[4].num = 19;
  Hand_ptr[4].list.status = 13;
  Hand_ptr[4].list.stage = 0;
  Hand_ptr[4].list.tier = 4;
  Hand_ptr[4].list.count = 0;
}
void Shoulder_li(struct Defensive *Shoulder_ptr, struct Value *list_ptr)
{
  strcpy(Shoulder_ptr[0].name, "맨 어깨");
  Shoulder_ptr[0].num = 20;
  Shoulder_ptr[0].list.status = 0;
  Shoulder_ptr[0].list.stage = 0;
  Shoulder_ptr[0].list.tier = 0;
  Shoulder_ptr[0].list.count = 0;

  strcpy(Shoulder_ptr[1].name, "기본 망토");
  Shoulder_ptr[1].num = 21;
  Shoulder_ptr[1].list.status = 1;
  Shoulder_ptr[1].list.stage = 0;
  Shoulder_ptr[1].list.tier = 1;
  Shoulder_ptr[1].list.count = 0;

  strcpy(Shoulder_ptr[2].name, "면 망토");
  Shoulder_ptr[2].num = 22;
  Shoulder_ptr[2].list.status = 4;
  Shoulder_ptr[2].list.stage = 0;
  Shoulder_ptr[2].list.tier = 2;
  Shoulder_ptr[2].list.count = 0;

  strcpy(Shoulder_ptr[3].name, "비단 망토");
  Shoulder_ptr[3].num = 23;
  Shoulder_ptr[3].list.status = 8;
  Shoulder_ptr[3].list.stage = 0;
  Shoulder_ptr[3].list.tier = 3;
  Shoulder_ptr[3].list.count = 0;

  strcpy(Shoulder_ptr[4].name, "방탄 망토");
  Shoulder_ptr[4].num = 24;
  Shoulder_ptr[4].list.status = 13;
  Shoulder_ptr[4].list.stage = 0;
  Shoulder_ptr[4].list.tier = 4;
  Shoulder_ptr[4].list.count = 0;
}
void Mouth_li(struct Defensive *Mouth_ptr, struct Value *list_ptr)
{
  strcpy(Mouth_ptr[0].name, "맨 얼굴");
  Mouth_ptr[0].num = 25;
  Mouth_ptr[0].list.status = 0;
  Mouth_ptr[0].list.stage = 0;
  Mouth_ptr[0].list.tier = 0;
  Mouth_ptr[0].list.count = 0;

  strcpy(Mouth_ptr[1].name, "기본 마스크");
  Mouth_ptr[1].num = 26;
  Mouth_ptr[1].list.status = 1;
  Mouth_ptr[1].list.stage = 0;
  Mouth_ptr[1].list.tier = 1;
  Mouth_ptr[1].list.count = 0;

  strcpy(Mouth_ptr[2].name, "K80 마스크");
  Mouth_ptr[2].num = 27;
  Mouth_ptr[2].list.status = 4;
  Mouth_ptr[2].list.stage = 0;
  Mouth_ptr[2].list.tier = 2;
  Mouth_ptr[2].list.count = 0;

  strcpy(Mouth_ptr[3].name, "K94 마스크");
  Mouth_ptr[3].num = 28;
  Mouth_ptr[3].list.status = 8;
  Mouth_ptr[3].list.stage = 0;
  Mouth_ptr[3].list.tier = 3;
  Mouth_ptr[3].list.count = 0;

  strcpy(Mouth_ptr[4].name, "타이거 마스크");
  Mouth_ptr[4].num = 29;
  Mouth_ptr[4].list.status = 13;
  Mouth_ptr[4].list.stage = 0;
  Mouth_ptr[4].list.tier = 4;
  Mouth_ptr[4].list.count = 0;
}
void medicine_li(struct Thing *rec_ptr, struct medicine *potoin_ptr)
{
  strcpy(potoin_ptr[0].name, "빨간 물약");
  potoin_ptr[0].num = 30;
  potoin_ptr[0].rec.plus_hp = 30;
  potoin_ptr[0].rec.tier = 1;

  strcpy(potoin_ptr[1].name, "주황 물약");
  potoin_ptr[1].num = 31;
  potoin_ptr[1].rec.plus_hp = 50;
  potoin_ptr[1].rec.tier = 2;

  strcpy(potoin_ptr[2].name, "맑은 물약");
  potoin_ptr[2].num = 32;
  potoin_ptr[2].rec.plus_hp = 70;
  potoin_ptr[2].rec.tier = 3;

  strcpy(potoin_ptr[3].name, "고농도 물약");
  potoin_ptr[3].num = 33;
  potoin_ptr[3].rec.plus_hp = 150;
  potoin_ptr[3].rec.tier = 4;
}
void items_li(struct items *item_ptr, struct other_It *cost_ptr)
{
  strcpy(item_ptr[0].name, "마을 이동 주문서");
  item_ptr[0].num = 34;
  item_ptr[0].cost.count = 0;
  item_ptr[0].cost.price = 100;
  strcpy(item_ptr[1].name, "순간 이동 주문서");
  item_ptr[1].num = 35;
  item_ptr[1].cost.count = 0;
  item_ptr[1].cost.price = 0;
  strcpy(item_ptr[2].name, "장비 강화 주문서");
  item_ptr[2].num = 36;
  item_ptr[2].cost.count = 0;
  item_ptr[2].cost.price = 300;
  strcpy(item_ptr[3].name, "엘릭서");
  item_ptr[3].num = 37;
  item_ptr[3].cost.count = 0;
  item_ptr[3].cost.price = 0;
}
void Equip_li(struct Equip_Items *parts_ptr, struct Equip_Item *ability_ptr)
{
  strcpy(parts_ptr[0].parts, " 무기  ");
  strcpy(parts_ptr[0].name, "기본 검");
  parts_ptr[0].num = 1;
  parts_ptr[0].each_parts.status = 2;
  parts_ptr[0].each_parts.tier = 1;
  parts_ptr[0].each_parts.inchants = 0;
  parts_ptr[0].each_parts.count = 1;

  strcpy(parts_ptr[1].parts, " 갑옷  ");
  strcpy(parts_ptr[1].name, "기본 갑빠");
  parts_ptr[1].num = 6;
  parts_ptr[1].each_parts.status = 1;
  parts_ptr[1].each_parts.tier = 1;
  parts_ptr[1].each_parts.inchants = 0;
  parts_ptr[1].each_parts.count = 1;

  strcpy(parts_ptr[2].parts, " 신발  ");
  strcpy(parts_ptr[2].name, "기본 장화");
  parts_ptr[2].num = 11;
  parts_ptr[2].each_parts.status = 1;
  parts_ptr[2].each_parts.tier = 1;
  parts_ptr[2].each_parts.inchants = 0;
  parts_ptr[2].each_parts.count = 1;

  strcpy(parts_ptr[3].parts, " 장갑  ");
  strcpy(parts_ptr[3].name, "기본 장갑");
  parts_ptr[3].num = 16;
  parts_ptr[3].each_parts.status = 1;
  parts_ptr[3].each_parts.tier = 1;
  parts_ptr[3].each_parts.inchants = 0;
  parts_ptr[3].each_parts.count = 1;

  strcpy(parts_ptr[4].parts, " 망토  ");
  strcpy(parts_ptr[4].name, "기본 망토");
  parts_ptr[4].num = 21;
  parts_ptr[4].each_parts.status = 1;
  parts_ptr[4].each_parts.tier = 1;
  parts_ptr[4].each_parts.inchants = 0;
  parts_ptr[4].each_parts.count = 1;

  strcpy(parts_ptr[5].parts, " 마스크");
  strcpy(parts_ptr[5].name, "기본 마스크");
  parts_ptr[5].num = 26;
  parts_ptr[5].each_parts.status = 1;
  parts_ptr[5].each_parts.tier = 1;
  parts_ptr[5].each_parts.inchants = 0;
  parts_ptr[5].each_parts.count = 1;
}
void status_li(status *player_ptr, struct Equip_Items *parts_ptr, struct Equip_Item *ability_ptr)
{
  player_ptr->hp = 1000;
  player_ptr->all_def = (player_ptr->def[0] + player_ptr->def[1] + player_ptr->def[2] + player_ptr->def[3]);
  player_ptr->total_hp;
  player_ptr->atk = parts_ptr[0].each_parts.status * 100000;
  player_ptr->gold = 300; 
}
void upgrade_elic(int num, struct Equip_Items *parts_ptr, struct Inventory *bag_ptr, struct Defensive *Weapon_ptr, struct Defensive *Top_ptr, struct Defensive *Hand_ptr,
                  struct Defensive *Shoulder_ptr, struct Defensive *Mouth_ptr, struct Defensive *Foot_ptr, status *player_ptr, struct Equip_Item *ability_ptr)
{

  system("clear");
  getchar();
  int j = 0;
  int i = 0;
  int up_choose = 0;
  int arr[40] = {};
  puts("\n<<system: 강화 필요한 장비를 선택해 주세요>>\n\n1 . 무기\n2 . 갑옷\n3 . 신발\n4 . 장갑\n5 . 망토\n6 . 마스크 \n");
  int ingame = 0;
  scanf("%d", &ingame);
  getchar();
  switch (ingame)
  {
    system("clear");
  case 1:
    system("clear");
    puts("소지하고 있는 무기의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (0 < bag_ptr[i].num && bag_ptr[i].num < 5)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (공격력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage; 
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;  

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 100;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 2:
    system("clear");
    puts("소지하고 있는 갑옷의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (5 < bag_ptr[i].num && bag_ptr[i].num < 10)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status;
      bag_ptr[arr[i]].tier;  

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 3:
    system("clear");
    puts("소지하고 있는 신발의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (10 < bag_ptr[i].num && bag_ptr[i].num < 15)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage; 
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;  
      char ch;
      int maxluck;
      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 4:
    system("clear");
    puts("소지하고 있는 장갑의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (15 < bag_ptr[i].num && bag_ptr[i].num < 20)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;   
      char ch;
      int maxluck;
      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1;
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 5:
    system("clear");
    puts("소지하고 있는 망토의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (20 < bag_ptr[i].num && bag_ptr[i].num < 25)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier; 

      char ch;
      int maxluck;

      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;
              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break; 
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  case 6:
    system("clear");
    puts("소지하고 있는 마스크의 종류는 다음과 같습니다.\n");
    for (int i = 0; i < num; i++)
    {
      if (25 < bag_ptr[i].num && bag_ptr[i].num < 30)
      {
        arr[j] = i;
        printf("%d . +%d 강 %s (방어력 : %d)\n", j + 1, bag_ptr[i].stage, bag_ptr[i].name, bag_ptr[i].status);
        j++;
      }
    }
    puts("강화하실 무기를 선택해 주세요.");
    scanf("%d", &up_choose);
    if (up_choose == i + 1)
    {
      bag_ptr[arr[i]].name;
      bag_ptr[arr[i]].stage;  
      bag_ptr[arr[i]].status; 
      bag_ptr[arr[i]].tier;  
      char ch;
      int maxluck;
      printf("강화\n");
      while (1)
      {
        maxluck = 20;
        printf("========================================================\n");
        printf("  현재 강화:%d 강  %d%% 확률  강화하시겠습니까? Y/N\n", bag_ptr[arr[i]].stage, maxluck);
        printf("========================================================\n");
        printf("강화 비용은 10원입니다\n");
        ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
          if (player_ptr->gold >= 0)
          {
            srand(time(NULL));
            int random = rand() % 100 + 1; 
            printf("강화중.\n");
            printf("1~100사이의 숫자를 뽑으면 성공!\n");
            printf("\n뽑은 숫자는!!!: %d\n", random);
            if (random < 101)
            {
              printf("성공!\n");
              bag_ptr[arr[i]].stage += 1;

              if (bag_ptr[arr[i]].stage == 1)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.1;
              }
              else if (bag_ptr[arr[i]].stage == 2)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.2;
              }
              else if (bag_ptr[arr[i]].stage == 3)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.3;
              }
              else if (bag_ptr[arr[i]].stage == 4)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.4;
              }
              else if (bag_ptr[arr[i]].stage == 5)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.5;
              }
              else if (bag_ptr[arr[i]].stage == 6)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.6;
              }
              else if (bag_ptr[arr[i]].stage == 7)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.7;
              }
              else if (bag_ptr[arr[i]].stage == 8)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.8;
              }
              else if (bag_ptr[arr[i]].stage == 9)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 1.9;
              }
              else if (bag_ptr[arr[i]].stage == 10)
              {
                bag_ptr[arr[i]].status = bag_ptr[arr[i]].status * 2;
              }
              printf("현재 공격력 = %d\n", bag_ptr[arr[i]].status);
            }
          }
        }
        else if (ch == 'n' || ch == 'N')
        {
          printf("종료하시겠습니까? Y/N\n");
          ch = getch();
          if (ch == 'y' || ch == 'Y')
          {
            break;
          }
        }
        else
        {
          printf("Y또는 N만 입력해주세요.\n");
        }
        if (bag_ptr[arr[i]].stage == 10)
        {
          printf("최대 강화치입니다.\n");
          break;
        }
      }
      printf("현재 장비 능력 = %d", bag_ptr[arr[i]].status);
      printf("종료.\n아무키나 눌러주세요..");
      getch();
    }
    break;
  }
}
