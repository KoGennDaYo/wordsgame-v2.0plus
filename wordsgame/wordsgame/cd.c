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
    printf("\t欢迎进行词汇游戏\n");
    printf("\t随机生成词汇中......\n");
    printf("\t生成完毕！\n");
    printf("\t功能列表如下：\n");
    printf("\t1.第一关\n");
    printf("\t2.第二关\n");
    printf("\t3.第三关\n");
    printf("\t4.单词写入\n");
    printf("\t5.错题本\n");
    printf("=======================================\n");
    printf("请输入您的选择：");
    scanf("%d", &mode);
    if (mode > 3 && mode < 6)
    {
        mode == 4 ? wordinput() : login();
    }
    else if (mode >= 6)
    {
        printf("模式选择有误，已退出游戏。");
    }
    else if (mode <= 3)
    {
        level = mode;
        printf("选择完毕，输入y以开始游戏：");
        scanf("%s", &choose);
        if (choose == 'y')
        {
            readWordsFromFile();
            playGame();
        }
        else
        {
            printf("输入有误，已退出游戏。");
        }
    }
}