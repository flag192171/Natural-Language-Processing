//
//  main.c
//  自然语言处理
//
//  Created by 李子晨 on 15/12/15.
//  Copyright © 2015年 李子晨. All rights reserved.
//

#include<stdio.h>
#include<string.h>

int input_asg(char Num[6][6]); //输入_赋值(函数)
int judge(char Num[6][6], int N);
void output(int number);
char judge_word[][6] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}, {"ten"}};

int main()
{
    char Num[6][6];
    int result,N;
    
    while(1) {
        N = input_asg(Num);
        result = judge(Num, N);
        if(result != 0) {
            output(result);
        }	else {
            break;
        }
    }
    return 0;
}

int input_asg(char Num[6][6]) {
    int count;
    
    for(count = 0; count < 6; count += 1) {
        scanf("%s",*(Num + count));
        if(Num[count][0] == '=')
            return count;
    }
}

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

void output(int number) {
    if((number/100) > 0) {
        printf("%s ", judge_word[number/100]);
    }
    if((number/10) > 0) {
        printf("%s ", judge_word[(number%100)/10]);
    }
    printf("%s\n", judge_word[number%10]);
}