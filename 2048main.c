#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "merge.h"
#define version "0.1"

//���˵�����
int showmenu();

//�ж���Ϸ�Ƿ����
int gamecontinue(int (*arr)[4]);

//�ڵ�ͼ������һ���������kΪ����4�ĸ��ʣ��������2
void newnum(int (*map)[4], double k);

//��ӡ��ͼ
int showmap(int (*map)[4], int score);

//ͳ��Ŀǰ�ĵ÷�
int scoremap(int map[][4]);

//��Ϸ������
void game();

//�߷ְ�������
void scores();

//������
int main(void)
{
    printf("Welcome to 2048 Version: 0.1 Powered by Jin_Wenze:\n");
    system("pause");
    system("cls");
    int running = 1;
    while(running)
    {
        int selection = showmenu();
        if(selection == 3) break;
        switch(selection)
        {
            case 1:
                game();
                break;
            case 2:
                scores();
                break;
            case 3:
                running = 0;
                break;
        }
    }
    system("cls");
    printf("...Powered by Jin_Wenze...\n");
    system("pause");
    return 0;
}


int gamecontinue(int (*arr)[4])
{
    int map[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = arr[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i < 5; i++)count += merge(map,i);
    if(count == 0) return 0;
    else return 1;
}

int showmap(int (*map)[4],int score)
{
    printf("�÷֣�  %d\n", score);
    for(int i = 0; i < 4; i++)
    {
        printf("%d\t%d\t%d\t%d\n\n", map[i][0], map[i][1], map[i][2], map[i][3]);
    }
}

int showmenu()
{
    printf("��������Ӧ����ĸ��ѡ��\n");
    printf("1.��ʼ��Ϸ\n");
    printf("2.�߷ְ� (������)\n");        //����ͨ���ļ��������ʵ��
    printf("3.�˳�\n");
    int x;
    scanf("%d",&x);                                  //���ڼ����������
    return x;
}

void game()
{
    //������Ϸ��ʼ��
    int map[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = 0;
        }
    }
    
    int move = 0;
    while(1)
    {
        system("cls");
        newnum(map, 0.7);               //�������ò��ִ����
        showmap(map,scoremap(map));
        if(gamecontinue(map) == 0) break;
        int check = 0;                  //��������Ƿ�������
        while(check == 0)
        {
            printf("�������ֽ��в���: 1 ���� 2 ���� 3 ���� 4 ����\n");
            scanf("%d", &move);             //�����������
            check = merge(map, move);
            if(check == 0) printf("������Ч��");
        }
    }
    printf("��Ϸ�ѽ�����\n");
}

void scores()
{
    system("cls");
    printf("Runing function scores\n");
}

void newnum(int (*map)[4], double k)
{
    srand((unsigned)time(NULL));
    int count = 0; //����ͳ�Ƶ�ͼ���ж���0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++) if(map[i][j] == 0) count ++;
    }
    int seed = rand() % count + 1;
    count = 0;
    int notdone = 1;
    for(int i = 0; i < 4 && notdone; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] == 0)
            {
                count ++;
                if(count == seed)
                {
                    double iftwo = rand() % 100 / 100.0;
                    if(iftwo < k) map[i][j] = 2;
                    if(iftwo >= k) map[i][j] = 4;
                    notdone = 0;
                    break;
                }
            }
        }
    }
}

int scoremap(int map[][4])
{
    int score = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            score += map[i][j];
        }
    }
    return score;
}

