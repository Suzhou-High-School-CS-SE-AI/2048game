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
int newnum(int (*map)[4], float k);

//��ӡ��ͼ
int showmap(int (*map)[4]);

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
    return 1;
}

int showmap(int (*map)[4])
{
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
    int map[4][4] = {{2,2,4,8},{4,2,4,8},{4,4,2,2},{2,4,2,4}};
    /*for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = 0;
        }
    }
    */
    int move = 0;
    while(1)
    {
        system("cls");

        showmap(map);
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
}

void scores()
{
    system("cls");
    printf("Runing function scores\n");
}

int newnum(int (*map)[4], float k)
{
    srand((unsigned)time(NULL));
    int count = 0; //����ͳ�Ƶ�ͼ���ж���0
}