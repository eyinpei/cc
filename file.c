#include<stdio.h>

/*输出      %[flag][width][.prec][hlL]type

[flag]标志
printf("%9d\n",123);
printf("%-9d\n",123);           左对齐
printf("%+9d\n",123);           强制输出+
printf("%09d\n",123);           0填充

[width]宽度
printf("%9.2f\n",123);          整个输出占9，其中小数部分为2
printf("%*d\n",6,123);          6用于满足*，123用于满足%d，加起来共6位数

[.prec]修饰符，用于修饰类型
hh  单个字节
h   short
l   long
ll  long long
L   long double
printf("%hhd\n",12345);         warning输出为57，因为12345为int。它的16进制为3039，取后两位39，十进制为57，
强制转换            
printf("%hhd\n",(char)12345);   可以得到无warning的57

type
printf
i或d        int
u           unsigned int
o           八进制
x           十六进制
X           字母大写的十六进制
f或F        float,6
e或E        指数
g或G        float
a或A        十六进制浮点数
c           char
p           指针
n           读入/写出的个数

int num;
printf("%d%n\n",(char)12345,&num);      输出%n之前的内容后，输出内容的个数填入指针num所指的变量中
printf("%d%n\n",12345,&num);
printf("%dty%n\n",12345,&num);
printf("%d\n",num);

scanf
d           int
i           整数，可能为十六进制或者八进制
u           unsigned int
o           八进制
x           十六进制
a,e,f,g     float
c           char
s           字符串
[...]       所允许的字符
p           指针
*           跳过
数字        最大字符数
hh          char
h           short
l           long，double
ll          long long
L           long double
int num；
scanf("%*d%d",&num);                    
printf("%d\n",num);*/

// int main(){
//     int num1,num2;
//     int i1 = scanf("%d %d",&num1,&num2);
//     int i2 = printf("%d\n",num1);
//     printf("%d,%d\n",i1,i2);
//     return 0;
// }
/*
printf和scanf的返回值
scanf的返回值返回的是变量的数量
printf返回值返回的是变量的字符数
1234
1234
1,5

123
789
123
2,4
*/

/*
.\a.exe > 12.out
输出结果至文件中
.\a.exe < 12.in
读取文件中的数据，输出结果
.\a.exe < 12.in > 12.out
读取文件中的数据，输出结果至文件中
*/



/*
打开文件的标准代码
FILE* fp("file","r");
if*fp{
    fscanf(fc,...);
    fclose(fp);
}
else{
    ...
}

fopen
r           打开只读
r+          打开读写，从文件头开始
w           打开只写，如果不存在则新建，如果存在则清空
w+          打开读写，如果不存在则新建，如果存在则清空
a           打开追加，如果不存在则新建，如果存在则从文件尾开始
...x        只新建，如果文件已存在则不能打开
*/

int main(){
    FILE* fp = fopen("12.in","r");
    if( fp ){
        int num;
        fscanf(fp,"%d",&num);
        printf("%d\n",num);
        fclose(fp);
    }
    else{
        printf("can't open the file");
    }
    return 0;
}
