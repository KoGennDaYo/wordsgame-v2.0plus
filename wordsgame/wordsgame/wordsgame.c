#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include <Windows.h>

#define MAX_WORDS 999
#define MAX_LENGTH 999

char englishWords[MAX_WORDS][MAX_LENGTH];
char chineseWords[MAX_WORDS][MAX_LENGTH];

int level = 1;
char choose = 0;
int mode;

void readWordsFromFile() {
    FILE* fp;
    char word[MAX_LENGTH], meaning[MAX_LENGTH];

    fp = fopen("../cfile/words.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件\n");
        return;
    }

    int index = 0;
    while (fscanf(fp, "%s %s", word, meaning) != EOF) {
        strcpy(englishWords[index], word);
        strcpy(chineseWords[index], meaning);
        index++;
    }
    fclose(fp);
}

// 游戏主逻辑
void playGame() {
    int correctCount = 0, totalQuestions = 10, num = 0;
    int currentQuestion = 0;
    srand((unsigned int)time(NULL));
    int errorreturn;
    char air = ' ';
    FILE* fp2;
    fp2 = fopen("../cfile/wordsreturn.txt", "w");
    if (fp2 == NULL) {
        errorreturn = errno;
        printf("无法打开文件：%s\n", strerror(errorreturn));
        return;
    }
    while (1) {
        if (num == totalQuestions) {
            double accuracy = (double)correctCount / totalQuestions * 100;
            printf("=================================================\n\n");
            printf("\t关卡 %d 结束，您的准确率为：%.2f%%\n\n", level, accuracy);
            printf("=================================================\n\n");

            if (accuracy > 80.0) {
                level++;
                if (level == 2) {
                    totalQuestions = 15;
                    printf("\t难度升级！\n");
                    printf("\t第二关单词数： %d 个\n\n", totalQuestions);
                    printf("=================================================\n\n");
                }
                else if (level == 3) {
                    totalQuestions = 20;
                    printf("\t难度升级！\n");
                    printf("\t第三关单词数： %d 个\n", totalQuestions);
                    printf("=================================================\n");
                }
                else if (level == 4) {
                    printf("\t恭喜通关！\n");
                    printf("=================================================\n");
                    return;
                }
                num = 0;
                correctCount = 0;
                continue;
            }
            else {
                printf("\t游戏结束\n\n");
                printf("=================================================\n");
                return;
            }
        }
    currentQuestion = rand() % 201;
    printf("单词：%s\n", englishWords[currentQuestion]);
    printf("[调试demo]答案：%s\n", chineseWords[currentQuestion]);
    char answer[MAX_LENGTH];
    printf("您的回答是：");
    scanf("%s", answer);

        if (strcmp(answer, chineseWords[currentQuestion]) == 0) {
            correctCount++;
            printf("回答正确，加一分\n");
        }
        else {
            printf("回答错误\n");
            fwrite(englishWords[currentQuestion], 1, sizeof(englishWords[currentQuestion]), fp2);
            fwrite(chineseWords[currentQuestion], 1, sizeof(chineseWords[currentQuestion]), fp2);
        }
        num++;
    }
    fclose(fp2);
    return;
}

int main() {
    cd();
    return 0;
}