//
//  main.c
//  自然语言处理
//
//  Created by 李子晨 on 15/12/15.
//  Copyright © 2015年 李子晨. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define SIZE 100
void alpha(char * start);
void lower(char * start);
int sum(char * start);

int main(int argc, const char * argv[]) {
    char word[SIZE];
    char * start;
    
    puts("please enter the word");
    start = gets(word);
    alpha(start);
    lower(start);
    int score;
    score = sum(start);
    printf("the score of this word is %d\n",score);
    return 0;
}
void alpha(char * start) {
    for (; *start != '\0'; start++) {
        if (!isalpha(*start)) {
            *start = 96;
        }
    }
}

void lower(char * start) {
    for (; *start != '\0'; start++) {
        *start = tolower(*start);
    }
}
int sum(char * start) {
    int total = 0;
    
    for (; *start != '\0'; start++) {
        total += ((int)*start - 96);
    }
    return total;
}

