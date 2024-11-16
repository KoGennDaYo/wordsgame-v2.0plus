#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include <Windows.h>
#include <errno.h>


#define MAX_LENGTH 999

void wordinput()
{
    char input[MAX_LENGTH];
    int errorreturn;
    FILE* fp;
    fp = fopen("../cfile/words.txt", "a");
    if (fp == NULL) {
        errorreturn = errno;
        printf("无法打开文件：%s\n",strerror(errorreturn));
        return;
    }
    printf("请按照格式'单词 单词释义'输入内容，输入'f'退出：\n");

    while (1)
    {
        //fseek(fp, 0, SEEK_END);
        gets_s(input, MAX_LENGTH);
        if (strcmp(input, "f") == 0)
        {
            printf("添加完毕，已退出程序。");
            return;
        }
        else fwrite(input, 1, strlen(input), fp);
    }


    fclose(fp);
    return;
}

void login()
{
    char current_path[MAX_PATH];
    char file_path[MAX_PATH];

    // 获取当前程序的工作目录
    if (!GetCurrentDirectory(MAX_PATH, current_path)) {
        perror("获取当前工作目录失败");
        return 1;
    }

    // 构建上级文件夹内cfile文件的相对路径
    if (_snprintf(file_path, MAX_PATH, "%s\\..\\cfile\\wordsreturn.txt", current_path) < 0) {
        perror("构建文件路径失败");
        return 1;
    }

    // 使用ShellExecute函数打开文件
    HINSTANCE result = ShellExecute(NULL, "open", file_path, NULL, NULL, SW_SHOWNORMAL);

    if ((int)result <= 32) {
        printf("打开文件窗口时出错，错误码：%d\n", (int)result);
        return 1;
    }

    return 0;
}