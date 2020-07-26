#include<stdio.h>

int fct; //機能を表す数字を格納する変数
int cnt, idt, in_num; //cnt=配列の要素数、idt=for文で使う'i'の代わり、in_num=それぞれの要素
void num_max_min(void); //最大値、最小値を表示するメソッド
void num_sum(void); //入力値x1からx2までの総和


int main(void){
    printf("機能一覧\n1:最大値、最小値の表示 2:2つの値x1～x2までの和 0:終了\n");
    while(1){
        printf("使用する機能の値を入力してください:");
        scanf("%d", &fct);
        if(fct < 0 || fct > 2){
            printf("値が不適切です。入力し直してください。\n");
            continue; //ループ処理の先頭まで戻る
        }
        else if(fct == 1){
            num_max_min();
            printf("---------------------------------------------\n");
        }
        else if(fct == 2){
            num_sum();
            printf("---------------------------------------------\n");
        }
        else if(fct == 0){
            printf("-------------------THE END-------------------");
            break; //ループを抜ける
        }
    }

    return 0;
}


void num_max_min(void){
    printf("\nいくつ数値を入力しますか？ << ");
    scanf("%d", &cnt); //配列の要素数および繰り返し回数の入力

    int array[cnt]; //長さがcntの配列を宣言
    for(idt = 0; idt < cnt; idt++){
        printf("要素を入力してください : ");
        scanf("%d", &in_num);
        array[idt] = in_num;
    }

    int min = array[0]; //最小値の初期化
    int max = array[0]; //最大値の初期化
    for(idt = 0; idt < cnt; idt++){
        if(min > array[idt]){
            min = array[idt];
        }
        if(max < array[idt]){
            max = array[idt];
        }
    }

    printf("\n最大値: %d, 最小値: %d\n", max, min);
}


void num_sum(void){
    int cin1, cin2;
    int sum = 0, max = 0, min = 0;

    printf("\n2つの値,(カンマ)区切りで入力してください:");
    scanf("%d,%d", &cin1, &cin2);

    //ここから最大値、最小値の判定
    if(cin1 > cin2){
        max = cin1;
        min = cin2;
    }
    else if(cin1 < cin2){
        max = cin2;
        min = cin1;
    }
    //ここまで
    sum = (min + max)*(max - min + 1)/2; //最小値～最大値までの総和を計算

    printf("%d～%dまでの合計は%dです。\n", min, max, sum);
}