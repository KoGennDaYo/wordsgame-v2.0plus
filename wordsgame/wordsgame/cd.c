#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include <Windows.h>

extern int level;
extern int mode;
extern char choose;

void cd()
{
    printf("=======================================\n");
    printf("\t��ӭ���дʻ���Ϸ\n");
    printf("\t������ɴʻ���......\n");
    printf("\t������ϣ�\n");
    printf("\t�����б����£�\n");
    printf("\t1.��һ��\n");
    printf("\t2.�ڶ���\n");
    printf("\t3.������\n");
    printf("\t4.����д��\n");
    printf("\t5.���Ȿ\n");
    printf("=======================================\n");
    printf("����������ѡ��");
    scanf("%d", &mode);
    if (mode > 3 && mode < 6)
    {
        mode == 4 ? wordinput() : login();
    }
    else if (mode >= 6)
    {
        printf("ģʽѡ���������˳���Ϸ��");
    }
    else if (mode <= 3)
    {
        level = mode;
        printf("ѡ����ϣ�����y�Կ�ʼ��Ϸ��");
        scanf("%s", &choose);
        if (choose == 'y')
        {
            readWordsFromFile();
            playGame();
        }
        else
        {
            printf("�����������˳���Ϸ��");
        }
    }
}