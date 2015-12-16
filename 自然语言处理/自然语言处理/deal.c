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
/*定义全局变量判断关键词*/
char judge_word[][6] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}, {"ten"}};
//==================================================================
//函数名：judge
//作者：曾朝栋
//日期：2015/12/12
//功能：接受input传递的字符串并转化为机器可以识别的语言，计算出结果
//输入参数：char Num[6][6]，int N
//返回值：num1 ＋num2（计算的结果）
//修改记录：2015/12/14代码格式化 修改人：李子晨
//==================================================================
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
                if(count_1 == 1) {
                    num_1 *= 10;
                }
                num_1 += count_2;
                break;
            }
            if(strcmp(Num[count_1],judge_word[count_2]) == 0 && sign == 0) {
                if(num_2 != 0) {
                    num_2 *= 10;
                }
                num_2 += count_2;
                break;
            }
        }
    }
    return num_1 + num_2;
}
//==================================================================
//函数名：input_asg
//作者：李子晨
//日期：2015/12/11
//功能：将输入的自然语言以字符串的形式存储
//输入参数：char Num[6][6]
//返回值：return count
//修改记录：
//==================================================================

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
//==================================================================
//函数名：output
//作者：曾朝栋
//日期：2015/12/14
//功能：将计算后的结果转化为自然语言输出
//输入参数：int number
//返回值：无
//修改记录：2015/12/14 代码格式化 修改人李子晨
//==================================================================

void output(int number) {
    if((number/100) > 0) {
        printf("%s ", judge_word[number/100]);
    }
    if((number/10) > 0) {
        printf("%s ", judge_word[(number%100)/10]);
    }
    printf("%s\n", judge_word[number%10]);
}