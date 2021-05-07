//
//  main.c
//  WordCount
//
//  Created by Abby on 2021/5/7.
//

#include <stdio.h>
#include <string.h>

// 统计单词数
int wordNum(char s[]){
    int sum=0; // 初始化单词个数
    int flag=0; // 初始化标记位,默认不是同一个单词
    for (int i=0; s[i]; i++) {
        if (s[i]==' ') { // 空格是单词的分界
            flag=0;
        }else if (flag==0){
            sum++; // 统计单词个数
            flag=1;
        }
    }
    return sum;
}

// 统计字符数
int charNum(char s[]){
    int sum=0;
    for (int i=0; s[i]!='\0'; i++) {
        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) {
            sum++;
        }
    }
    return sum;
}

char s[100000];
int main(int argc, const char * argv[]) {
    char bf[256];
    FILE *fp = NULL;
    int sum=0;
    fp=fopen(argv[2], "r");
    if (fp==NULL) {
        printf("文件读取失败");
        return -1;
    }
    
    while (!feof(fp)) {
        if (fgets(bf,255,fp)!=NULL) {
            strcat(s, bf);
        }
    }
    
    puts(s);
    if (argc!=3) {
        printf("出现错误\n");
    }else{
        if (strcmp(argv[1], "-w")==0) {
            sum=wordNum(bf);
            printf("单词数: %d\n",sum);
        }else if (strcmp(argv[1], "-w")==0){
            sum=charNum(bf);
            printf("字符数： %d\n",sum);
        }
    }
    return 0;
}
