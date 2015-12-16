//
//  deal.c
//  自然语言处理
//
//  Created by 李子晨 on 15/12/16.
//  Copyright © 2015年 李子晨. All rights reserved.
//

#include "deal.h"
#include <stdio.h>
#include <string.h>
char judge_word[][6] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}, {"ten"}};

int judge(char Num[6][6], int N) {
    int count_1 = 0;
    int count_2 = 0;
    int num_1 = 0;
    int num_2 = 0;
    int sign = 1;
    
    for(count_1 = 0; count_1 < N; count_1++) {
        if(Num[count_1][0] == '+') {
            sign =0;
        }
        for(count_2 = 0; count_2 < 10; count_2++) {
            
            if(strcmp(Num[count_1],judge_word[count_2]) == 0 && sign == 1) {
                if(count_1 == 1)
                    num_1 *= 10;
                num_1 += count_2;
                break;
            }
            if(strcmp(Num[count_1],judge_word[count_2]) == 0 && sign == 0) {
                if(num_2 != 0)
                    num_2 *= 10;
                num_2 += count_2;
                break;
            }
        }
    }
    return num_1 + num_2;
}
int input_asg(char Num[6][6]) {
    int count;
    
    puts("please enter the equation\nfor example： one + one =\nenter \"zero ＋ zero ＝\" to quit");
    for(count = 0; count < 6; count += 1) {
        scanf("%s",*(Num + count));
        if(Num[count][0] == '=')
            return count;
    }
    return 0;
}
void output(int number) {
    if((number/100) > 0) {
        printf("%s ", judge_word[number/100]);
    }
    if((number/10) > 0) {
        printf("%s ", judge_word[(number%100)/10]);
    }
    printf("%s\n", judge_word[number%10]);
}