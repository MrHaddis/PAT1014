#include <stdio.h>

//MrHaddis
//源码地址：https://github.com/MrHaddis/PAT1014.git

int main() {
    char str;
    int count = 0;
    //接收输入的数组
    char chars[4][61];
    //代表星期的数组
    char dayArray[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    //定义获取的次数 2次即可获取完成
    int time = 0;
    //获取输入
    while (count < 4) {
        int index = 0;
        while ((str = getchar()) != '\n') {
            chars[count][index++] = str;
        }
        count++;
    }
    //循环
    for (int j = 0; j < 60; j++) {
        if ('\n' != chars[0][j] && '\n' != chars[1][j]) {
            //两个值相等
            if (chars[0][j] == chars[1][j]) {
                //这个值代表的数字
                int i = chars[0][j] - 'A';
                //time ==0 代表第一个相同的数字 是星期几
                //==1是 代表第二个 代表时间的数字
                //这些边界条件不能少
                if (chars[0][j] >= 'A' && chars[0][j] <= 'G' && time == 0) {
                    //这里不能用%c输出，卡了我好久
//                    for (int k = 0; k < 4; ++k) {
//                        printf("%c", dayArray[i][k]);
//                    }
                    //要用%s输出
                    printf("%s ", dayArray[i]);
                    time = 1;
                } else if (chars[0][j] >= '0' && chars[0][j] <= '9' && time == 1) {
                    //0-9点要用 值去-‘0’的值
                    printf("0%d", chars[0][j] - '0');
                    break;
                } else if ((chars[0][j] >= 'A' && chars[0][j] <= 'N') && time == 1) {
                    //A以后要用10
                    printf("%d", i + 10);
                    break;
                }
            }
        }
    }
    //循环输出分钟
    for (int l = 0; l < 60; ++l) {
        if ('\n' != chars[2][l] && '\n' != chars[3][l]) {
            if (chars[2][l] == chars[3][l]) {
                if (chars[2][l] >= 'A' && chars[2][l] <= 'Z'
                    || chars[2][l] >= 'a' && chars[2][l] <= 'z') {
                    //输出一个以后就可以中断了
                    if (l < 10) {
                        //十分钟以内补0
                        printf(":0%d", l);
                        break;
                    } else {
                        //10以后不用补
                        printf(":%d", l);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
