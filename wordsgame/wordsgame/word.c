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
        printf("�޷����ļ���%s\n",strerror(errorreturn));
        return;
    }
    printf("�밴�ո�ʽ'���� ��������'�������ݣ�����'f'�˳���\n");

    while (1)
    {
        //fseek(fp, 0, SEEK_END);
        gets_s(input, MAX_LENGTH);
        if (strcmp(input, "f") == 0)
        {
            printf("�����ϣ����˳�����");
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

    // ��ȡ��ǰ����Ĺ���Ŀ¼
    if (!GetCurrentDirectory(MAX_PATH, current_path)) {
        perror("��ȡ��ǰ����Ŀ¼ʧ��");
        return 1;
    }

    // �����ϼ��ļ�����cfile�ļ������·��
    if (_snprintf(file_path, MAX_PATH, "%s\\..\\cfile\\wordsreturn.txt", current_path) < 0) {
        perror("�����ļ�·��ʧ��");
        return 1;
    }

    // ʹ��ShellExecute�������ļ�
    HINSTANCE result = ShellExecute(NULL, "open", file_path, NULL, NULL, SW_SHOWNORMAL);

    if ((int)result <= 32) {
        printf("���ļ�����ʱ���������룺%d\n", (int)result);
        return 1;
    }

    return 0;
}