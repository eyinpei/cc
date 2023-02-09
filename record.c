#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 

//----------------------输入两个整数A和B,求A+B,需要不停的接收系统的测试输入

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){  //scanf("%d %d",&a,&b)!=EOF == ~scanf("%d %d",&a,&b)
        printf("%d\n",a+b);
    }

    return 0;
}


//----------------------编写一个程序，输入a、b、c三个值，输出其中最大值。
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%d",a>b?a>c?a:c:b>c?b:c);
    return 0;
} 


//----------------------凯撒密码
int main()
{
    char n[11];
    gets(n);

    for(int i = 0;n[i]!='\0';i++){
        if(n[i]>='A' && n[i]<='Z'){
            n[i] = (n[i] + 4 - 'A')%26 + 'A';
        }
        if(n[i]>='a' && n[i]<='z'){
            n[i] = (n[i] + 4 -'a')%26 + 'a';
        }
        
    }
    puts(n);

    return 0;
} 

//----------------------输入一行电报文字，将字母变成其下一字母
int main(){
    char n[200];
    gets(n);
    int len = strlen(n);
    for(int i =0;i < len;i++){
        if(n[i]>='a'&&n[i]<='z'){
            n[i] = (n[i]+1-'a')%26+'a';
        }
        if(n[i]>='A'&&n[i]<='Z'){
            n[i] = (n[i]+1-'A')%26+'A';
        }
        
    }
    puts(n);
    return 0;
}

//----------------------(递归)有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

int fun(int n){
    if(n<=3){
        return n;
    }
    else{
        return fun(n-1)+fun(n-3);       
    }

}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(n ==0||n>55)
            return 0;
        else
            printf("%d\n",fun(n));
    }
    

    return 0;
} 


//----------------------输入一个华氏温度，要求输出摄氏温度。公式为 c=5(F-32)/9，取位2小数。
int main(){
    float n;
    scanf("%f",&n);
    printf("c=%.2f",5*(n-32)/9);
    return 0;
}
/*在C语言中用于格式化输入输出时：

整数值用%d;
实数（浮点数）用%f；
float，单精度浮点型，对应%f。
double,双精度浮点型，对应%lf。
即 %f 和 %lf分别对应float类型和double类型用于格式化输入输出时的格式符号。
用于输入时:
scanf函数是通过指针指向变量的。
%f告诉scanf函数在所传地址位置上存储一个float型值，
而%lf告诉scanf函数在所传地址位置上存储一个double型值。
如果给出了错误的转换说明，那么scanf函数将可能存储错误的字节数量。
double 类型使用了%f格式，会导致输入值错误。
float类型使用%lf格式不仅会导致输入错误，还可能引起程序崩溃。
用于输出时:
float类型可以使用%lf格式，没啥好处。
double类型如果使用了%f格式可能会导致输出错误。
因此在printf函数调用中%f既可以表示float型又表示double型的参数。*/


//----------------------分段函数----------------------
/*有一个函数
y={  x      x<1
    |  2x-1   1<=x<10
    { 3x-11  x>=10

写一段程序，输入x，输出y*/

int main(){
    int x;
    scanf("%d",&x);
    if(x<1){
        printf("%d",x);
    }
    else if(x>=1&&x<10){
        printf("%d",2*x-1);
    }
    else{
        printf("%d",3*x-11);
    }

    return 0;

}


//----------------------给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以及90分以上为A，80-89分为B，70-79分为C，60-69分为D，60分以下为E。

int main(){
    int n;
    while(~scanf("%d",&n)){
        /*if(n/10>=9){
            printf("A");
            break;
        }
        if(n/10>=8){
            printf("B");
            break;
        }
        if(n/10>=7){
            printf("C");
            break;
        }
        if(n/10>=6){
            printf("D");
            break;
        }
        else{
            printf("E");
            break;
        }*/
        switch(n/10){
            case 10:
            case 9:
            printf("A\n");
            break;
            case 8:
            printf("B\n");
            break;
            case 7:
            printf("C\n");
            break;
            case 6:
            printf("D\n");
            break;
            default:
            printf("E\n");
            break;
        }
    }
    return 0;
}

/*----------------------给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321,应输出123(
三行 第一行 位数 第二行 用空格分开的每个数字，注意最后一个数字后没有空格 第三行 按逆序输出这个数----------------------*/

int main(){
    /*int n;
    static int count= 1;
    scanf("%d",&n);
    int m =n;
    while(m/10!=0){
        count++;
        m = m/10;
    }
    printf("%d\n",count);

    m = n;
    int str[count-1];
    for(int i = count;i >0;i--){
        int p = pow(10,i-1);         //pow(x,n)，求x的n次，函数库为math.h
        printf("%d",m/p);
        str[i-1] = m/p;
        m = m%p;
        if(i > 1){
            printf(" ");
        }
        else{
            printf("\n");
        }

    }

    for(int i = 0;i <count;i++){
        printf("%d",str[i]);
    }*/

    char str[10];
    gets(str);
    int len = strlen(str);
    printf("%d\n",len);

    for(int i = 0;i < len;i++){
        printf("%c",str[i]);
        if(i < len-1)
            printf(" ");
        else
            printf("\n");
    }

    for(int i = len-1;i >=0;i--){
        printf("%c",str[i]);
    }
    return 0;
}


//----------------------写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果两个整数由键盘输入。

int gcd(int a,int b);
int lcm(int a,int b);

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d",gcd(a,b),lcm(a,b));

    return 0;

}
/*
int gcd(int a,int b){
    if(a%b!=0){
        a = a%b;
        gcd(b,a);
    }
    else{
        printf("%d ",b);
    }
    return 0;
}


int lcm(int a,int b){
    for(int i = 2;;i++){
        if(a*i%b==0){
            printf("%d",a*i);
            break;
        }
    }
    return 0;
}*/

//利用辗转相除法求出最大公约数，而得出两个数的最大公约数，把两数相乘再除以最大公约数就能求出最小公倍数。

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}


//----------------------输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。


int main(){
    char n[200];
    int countc=0,countn = 0,counts = 0,counto = 0;
    gets(n);
/*  %c格式对应的是单个字符,对应类型为char
    %s格式对应的是字符串,对应类型为char *  
    char a;
    char b[20];
    scanf("%c",&a); //只能输入一个字符。
    scanf("%s",b); //不超过20字符的字符串，字符串下标为0~19。 */
    int len = strlen(n);
    for(int i = 0; i <len ;i++){
        if(n[i]>='a'&&n[i]<='z'){
            countc++;
        }
        else if(n[i]>='A'&&n[i]<='Z'){
             countc++;
        }
        else if(n[i]>='0'&&n[i]<='9'){
            countn++;
        }
        else if(n[i]==' '){
            counts++;
        }
        else{
            counto++;
        }
    }

    printf("%d %d %d %d",countc,countn,counts,counto);
    return 0;
}

/*
int count(char n[]);

int main(){
    char n[100];
    gets(n);
    count(n);
    return 0;
}

int count(char n[]){
    int len = strlen(n);
    int num1=0,num2=0,num3=0,num4=0;
    for(int i = 0;i < len;i++){
        if(n[i]>='a'&&n[i]<='z'||n[i]>='A'&&n[i]<='Z'){
            num1++;
        }
        else if(n[i]>='0'&&n[i]<='9'){
            num2++;
        }
        else if(n[i]==' '){
            num3++;
        }
        else{
            num4++;
        }
    }
    printf("%d %d %d %d",num1,num2,num3,num4);
    return 0;
}
*/


//----------------------求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。


int main(){
    int n,a=0;
    int sum = 0;
    scanf("%d",&n);
    for(int i = 0;i <n;i++){
        a = pow(10,i)*2+a;
        sum +=a;
        
    }

    printf("%d",sum);
    return 0;
}

//----------------------求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字(n不超过20)。

int main(){
    int n;
    long long sum = 0,a=1;
    scanf("%d",&n);


    // for(int j = 1;j <=n;j++){
    //     a =1;
    //     for(int i = 1;i <=j;i++){
    //         a =a*i;
    //     }
    //     sum = sum+a;
    // }

    for(int i = 1;i <=n;i++){
        a = a*i;
        sum +=a;
    }
    printf("%lld",sum);



    return 0;
}


//----------------------求以下三数的和,保留2位小数 1~a之和 1~b的平方和 1~c的倒数和(1+2+...+a + 1^2+2^2+...+b^2 + 1/1+1/2+...+1/c)

int main(){
    int a,b;
    double c;    
    scanf("%d %d %lf",&a,&b,&c);
    double sum = 0;
//  float c;
//  scanf("%d %d %f",&a,&b,&c);
//  float sum = 0;   

    for(int i = 0;i <a;i++){
        sum +=i+1;
    }
    for(int i = 0;i < b;i++){
        sum = sum + pow(i+1,2);
    }
    for(double i = 0;i < c;i++){
//  for(float i = 0;i < c;i++){
        sum = sum +1/(i+1);
    }

    printf("%.2lf",sum);
//  printf("%.2f",sum);
    return 0;
}


//----------------------打印出所有"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该本身。 例如：153是一个水仙花数，因为153=1^3+5^3+3^3。 
int main(){
    for(int i = 100;i <1000;i++){
        int k = i,sum = 0;
        for(int j = 2; j >=0;j--){
            int p = pow(10,j);
            sum += pow((k/p),3);
            k = k%p;
        }
        if(sum == i){
            printf("%d\n",sum);
        }
    }
    return 0;
}

//----------------------"完数"。6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子? its factors are ? ? ?
// 1000

// 6 its factors are 1 2 3 
// 28 its factors are 1 2 4 7 14 
// 496 its factors are 1 2 4 8 16 31 62 124 248 
int main(){
    int n,i,j;
    scanf("%d",&n);
    for( i = 6;i <=n;i++){
        int str[50]={0};
        int *p = str;                               //定义str时开辟了一片内存空间，指针p指向str的首地址，*p=j是在该内存地址存入变量，而指向该内存地址的有p和&str，两种表示都可以取出变量
        for( j =1;j <= i/2;j++){
            if(i%j==0){
                p++;
                *p=j;                               
                str[0] += j;                
            }    
        }
        if(str[0] == i){
                printf("%d its factors are",i);
                for(p=&str[1];*p!=0;p++){          //p = &str[1]代表将str[1]的地址赋给了p，*p意思是取地址所指向的值，指针可进行变量的运算
                    printf(" %d",*p);
                }
                printf("\n");
            }
/*        if(str[0] == i){
        printf("%d its factors are",i);
        for(int t = 1;str[t]!=0;t++){          //输出时可以不使用指针，用数组进行输出，
            printf(" %d",str[t]);
        }
        printf("\n");
    }   */
    }
    return 0;
}

// 指针
// p存放的是地址
// &p对p取地址
// *p顺着地址找到变量

/*
int main(){
    int n,i,j;
    scanf("%d",&n);
    for( i = 6;i <=n;i++){
        int str[50]={0};
        int p = 1;
        for( j =1;j <= i/2;j++){
            if(i%j==0){
                str[p]=j;
                p++;
                str[0] += j;                
            }    
        }
       if(str[0] == i){
        printf("%d its factors are",i);
        for(int t = 1;str[t]!=0;t++){          //输出时可以不使用指针，用数组进行输出，
            printf(" %d",str[t]);
        }
        printf("\n");
    }   
    }
    return 0;
}*/


//----------------------有一分数序列： 2/1 3/2 5/3 8/5 13/8 21/13...... 求出这个数列的前N项之和，保留两位小数。

int main(){
    float n,sum = 0,p = 2,q = 1,tmp;
    scanf("%f",&n);
    for(float i = 1;i <=n;i++){
        sum+=p/q;
        tmp = q;
        q = p;
        p = p+tmp;
    }
    printf("%.2f",sum);
    return 0;
}


//----------------------一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。 它在第N次落地时反弹多高？共经过多少米？ 保留两位小数。
//它在第N次落地时反弹多高？共经过多少米？ 保留两位小数，空格隔开，放在一行

// int main(){
//     float m,n;
//     scanf("%f %f",&m,&n);
//     float sum=m;
//     for(int i = 0;i <n;i++){       
//         m = m*0.5;
//         if(i <n-1){
//             sum += m*2;
//         }
//     }
//     printf("%.2f %.2f",m,sum);
//     return 0;
// }

//等比数列计算

int main(){
    float m,n,sum;
    scanf("%f %f",&m,&n);
    sum = (m*(1-pow(0.5,n)))/0.5+(0.5*m*(1-pow(0.5,n-1)))/0.5;
    m = m*pow(0.5,n);
    printf("%.2f %.2f",m,sum);
    return 0;
}

//----------------------用迭代法求 平方根：公式：求a的平方根的迭代公式为： X[n+1]=(X[n]+a/X[n])/2 要求前后两次求出的差的绝对值少于0.00001。 输出保留3位小数
int main(){
    int n;
    scanf("%d",&n);
    double a = 2.0,b;
    while(fabs(a-b)>1E-5){
        b = a;
        a = (b+n/b)/2;
    }
    printf("%.3lf",a);
    return 0;

}

/*迭代法和递归法
一、含义不同：

递归是重复调用函数自身实现循环。迭代是函数内某段代码实现循环，循环代码中参与运算的变量同时是保存结果的变量，当前保存的结果作为下一次循环计算的初始值。
递归循环中，遇到满足终止条件的情况时逐层返回来结束。迭代则使用计数器结束循环。当然很多情况都是多种循环混合采用，这要根据具体需求。

二、结构不同：

递归与迭代都是基于控制结构：
迭代用重复结构，而递归用选择结构。 递归与迭代都涉及重复：迭代显式使用重复结构，而递归通过重复函数调用实现重复。

递归与迭代都涉及终止测试：
迭代在循环条件失败时终止，递归在遇到基本情况时终止，使用计数器控制重复的迭代和递归都逐渐到达终止点：
迭代一直修改计数器，直到计数器值使循环条件失败；递归不断产生最初问题的简化副本，直到达到基本情况。

*/
//----------------------用简单素数筛选法求N以内的素数

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 2;i <=n;i++){
        int flag = 1;
        for(int j = 2;j<=i;j++){
            if(i%j==0&&i!=j){
                flag = 0;
            }
        }
        if(flag == 1){
            printf("%d\n",i);
        }

    }
    return 0;
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i = 2;i <=n;i++){
        for(j = 2;j<i;j++){
            if(i%j==0)
            break;
        }
        if(i==j)
        printf("%d\n",i);
    }
    return 0;
}

//----------------------输入两个正整数m和n(m<n)，求m到n之间(包括m和n)所有素数的和
int isprime(int m);


int main(){
    int m,n,sum = 0;
    scanf("%d %d",&m,&n);

    for(int i = m;i <=n;i++){
        sum += isprime(i);
    }

    printf("%d",sum);
    return 0;

}

int isprime(int m){
    int isprime = 1;
    if(m ==1){                                  //注意1不是素数
        return 0;
    }
    for(int i = 2;i<=m;i++){
        if(m%i==0&&i!=m){
            isprime = 0;
            break;
        }
    }
    if(isprime ==0){
        return 0;
    }
    else{
        return m;
    }
}

//----------------------排序:快速排序、希尔排序、冒泡排序、归并排序、堆排序等经典排序算法，并能够进行时空复杂性和稳定性的分析；
int order(int a[]);
int main(){
    int a[3];
    for(int i = 0 ;i <3;i++){
        scanf("%d",&a[i]);
    }
    order(a);
    for(int i =0;i<3;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}

//插入排序
//直接插入排序：每趟排序将无序数列的元素按照顺序查找插入在有序数列中的对应位置。    稳定；空间复杂度O(1)；时间复杂度O(n^2)
int order(int a[]){
    for(int i = 1;i <3;i++){
        int tmp = a[i],j;
        for(j = i-1;j>=0&&tmp<a[j];j--){
                a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }   
} 

//希尔排序                                      不稳定；空间复杂度O(1)；时间复杂度O未知，但是优于直接插入排序
int order(int a[]){
    int tmp,d,i,j;
    for(d = 3/2;d>0;d = d/2){
        for(i = d;i<3;i++){
                tmp = a[i];
                for(j = i-d;j>=0&&tmp < a[j];j=j-d){            //注意希尔排序是插入排序的一种，每趟序列间隔d元素的为一个数列，对该数列进行插入排序
                    a[j+d] = a[j];
                }
                a[j+d] = tmp;
        }
    }
    return 0;
    
}



//交换排序
//冒泡排序：进行两两比较，按照升序或降序进行排列，每趟排序可以确定一个元素在数列中的位置。      稳定；空间复杂度O(1)，时间复杂度O(n^2)；
int order(int a[]){
    for(int i = 0;i <3;i++){
        int tmp;
        for(int j = 0;j <3-i;j++){
            if(a[j]>a[j+1]){
                    tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1]=tmp; 
                }        
        }
    }
}

//快速排序




//选择排序
//简单选择排序：每趟排序从无序数列中找出符合条件（最大或者最小）的元素添加到有序队列的末尾，每趟排序可以确定一个元素在数列中的位置。        不稳定；空间复杂度O(1)，时间复杂度O(n^2)；
int order(int a[]){
    for(int i = 0;i <3;i++){
        int tmp,min = i ;
        for(int j =i;j<3;j++){
            min = a[min]<a[j]?min:j;
        }
        if(min!=i){
            tmp = a[min];
            a[min] =a[i];
            a[i] = tmp;
        }
    }
}

//堆排序







//归并排序





//----------------------求一个3×3矩阵对角线元素之和。
int main(){
    int n[3][3],sum1=0,sum2=0;
    for(int i = 0;i <3;i++){
        for(int j = 0;j <3;j++){
            scanf("%d",&n[i][j]);
            if(i==j){
                sum1 += n[i][j];
            }
            if(i+j==2){
                sum2 += n[i][j];
            }
        }
    }
    printf("%d %d",sum1,sum2);
    return 0;

}

//----------------------已有一个已正序排好的9个元素的数组，今输入一个数要求按原来排序的规律将它插入数组中。
/*第一行，原始数列。 第二行，需要插入的数字。*/

//1.设置一个长为10的数组，找到m小于n[i]的位置，进行插入，后续左右的元素依次后移，令n[10]=max
int main(){
    int n[10]={0};
    for(int i = 0;i <9;i++){
        scanf("%d",&n[i]);
        getchar();
    }

    int tmp,m;
    scanf("%d",&m);

    for(int i = 0;i <=9;i++){
        if(m<n[i]){
            tmp = m;
            m = n[i];
            n[i]=tmp;
        } 
        if(i==9){
            n[9]=m;
        }
    }
    for(int i = 0; i<=9;i++){
        printf("%d\n",n[i]);
    }

    return 0;

}


//2.以m在数组中的位置为断点，先输出前半部分，然后输出m，最后输出后半部分
int main(){
    int n[9]={0};
    for(int i = 0;i < 9;i++){
        scanf("%d",&n[i]);
        getchar();
    }

    int m,tmp;
    scanf("%d",&m);

    for(int i = 0;i <9;i++){
        if(m>n[i]){
            printf("%d\n",n[i]);
        }
        if(m<n[i]){
            tmp = i;
            printf("%d\n",m);
            break;
        }   
    }
    
    for(int i = tmp;i < 9;i++){
        printf("%d\n",n[i]);
    }

    return 0;
}

//----------------------输入10个数字，然后逆序输出。
int main(){
    int n[10]={0};
    for(int i = 0;i <10;i++){
        scanf("%d",&n[i]);
        getchar();
    }

    for(int i = 9; i>=0;i--){
        printf("%d ",n[i]);
    }
    return 0;

}

//----------------------求方程 的根，用三个函数分别求当b^2-4ac大于0、等于0、和小于0时的根，并输出结果。从主函数输入a、b、c的值。

int main(){
    float a,b,c;
    float x1,x2;
    scanf("%f %f %f",&a,&b,&c);
    float det = b*b - 4*a*c;
    if(det >0){
        float q=sqrt(det);                              //封装在math.h中，开根号
        printf("%.3f %.3f",x1=(-b+q)/(2*a),x2 = (-b-q)/(2*a));
    }
    if(det ==0){
        float q=sqrt(det);
        printf("%.3f %.3f",x1 = -b/(2*a),x2=-b/(2*a));
    }
    if(det <0){
        float q=sqrt(-det);
        printf("x1=-%.3f+%.3fi ",b/(2*a),q/(2*a));
        printf("x2=-%.3f-%.3fi",b/(2*a),q/(2*a));
    }

    return 0;
}


//----------------------写一个判断素数的函数，在主函数输入一个整数，输出是否是素数的消息。如果是素数输出prime 如果不是输出not prime
int isprime(int n);

int main(){
    int n;
    scanf("%d",&n);
    if(isprime(n)==1){
        printf("prime");
    }
    if(isprime(n)==0){
        printf("not prime");
    }
    return 0;
}

int isprime(int n){
    int isprime = 1;
    for(int i = 2;i <n;i++){
        if(n%i==0){
            isprime =0;
            break;
        }
    }
    return isprime;
}
//----------------------写一个函数，使给定的一个二维数组（３×３）转置，即行列互换。
int main(){
    int n[3][3]={0};
    for(int i =0;i <3;i++){
        for(int j = 0;j <3;j++){
            scanf("%d",&n[i][j]);
        }
    }

    for(int i = 0; i < 3;i++){
        for(int j = 0;j<3;j++){
            printf("%d ",n[j][i]);
        }
        printf("\n");
    }
    return 0;
}

//----------------------写一函数，使输入的一个字符串按反序存放，在主函数中输入并输出反序后的字符串（不包含空格）。
int exchange(char n[],char m[]);

int main(){
    char n[20],m[20];
    gets(n);
    exchange(n,m);
    puts(m);
    return 0;
}

int exchange(char n[],char m[]){
    int len = strlen(n);
    int i=0;
    for(;i < len;i++){
        m[i]=n[len-i-1];
    }
    m[i]='\0';          //puts()输出字符串时要遇到'\0’也就是字符结束符才停止

    return 0;

}

//----------------------写一函数，将两个字符串连接
int main(){
    char n[20],m[20];
    gets(n);
    gets(m);
    strcat(n,m);            //strcat()就是将两个char型进行连接，在头文件string.h中。strcat(a,b)。把b所指字符串添加到a结尾处(覆盖a结尾处的'\0')。
    puts(n);
    return 0;
}

/*
int scp(char n[],char m[]);

int main(){
    char n[20],m[20];
    gets(n);
    gets(m);
    scp(n,m);
    puts(n);
    return 0;
}

int scp(char n[],char m[]){
    int lenn = strlen(n),lenm = strlen(m);
    int i=lenn,j=0;
    for(;i<lenn+lenm;i++){
        n[i] = m[j];
        j++;
    }
    return 0;
}
*/

//----------------------写一函数，将一个字符串中的元音字母复制到另一个字符串，然后输出。
void Zftq(char n[200]);

int main(){
    char n[200];
    gets(n);
    Zftq(n);
    return 0;
}

void Zftq(char n[200]){
    for(int i =0;n[i]!='\0';i++){
        if(n[i]=='a'||n[i]=='e'||n[i]=='i'||n[i]=='o'||n[i]=='u'){
            printf("%c",n[i]);
        }
    }
}

//----------------------写一函数，输入一个四位数字，要求输出这四个数字字符，但每两个数字间空格。如输入1990，应输出"1 9 9 0"。
int print(char n[]);

int main(){
    char n[4];
    gets(n);
    print(n);
    return 0;
}

int print(char n[]){
    for(int i = 0;i < 4;i++){
        printf("%c",n[i]);
        if(i<3){
            printf(" ");
        }
    }
}

//----------------------宏定义：使两个参数的值互换，并写出程序，输入两个数作为使用宏时的实参。输出已交换后的两个值。
/*宏的定义和使用
带参数的宏
在 C 语言中，可以采用命令 #define 来定义宏。该命令允许把一个名称指定成任何所需的文本，例如一个常量值或者一条语句。在定义了宏之后，无论宏名称出现在源代码的何处，预处理器都会把它用定义时指定的文本替换掉。
#define         ARRAY_SIZE 100
double   data[ARRAY_SIZE];
惯例将宏名称每个字母采用大写，这有助于区分宏与一般的变量

没有参数的宏
#define 宏名称 替换文本                                    替代文本本身也可以为空

带参数的宏
#define 宏名称( [形参列表] ) 替换文本                       带有形参的宏通常也称为类函数宏（function-like macro）。
#define 宏名称( [形参列表 ,] ... ) 替换文本
“形参列表”是用逗号隔开的多个标识符，它们都作为宏的形参。当使用这类宏时，实参列表中的实参数量必须与宏定义中的形参数量一样多
当定义一个宏时，必须确保宏名称与左括号之间没有空白符。如果在名称后面有任何空白，那么命令就会把宏作为没有参数的宏，且从左括号开始采用替换文本。
#define DISTANCE( x, y ) ((x)>=(y) ? (x)-(y) : (y)-(x))
d = DISTANCE( a, b+0.5 );
展开如下
d = ((a)>=(b+0.5) ? (a)-(b+0.5) : (b+0.5)-(a));
*/
#define EXCHANGE(a,b) a = a+b,b=a-b,a=a-b

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    EXCHANGE(a,b);
    printf("%d %d",a,b);
    return 0;
}


//----------------------宏定义：输入两个整数，求他们相除的余数。用带参的宏来实现，编程序。
#define REMAINDER(a,b) a%b

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",REMAINDER(a,b));
    return 0;

}



//----------------------宏定义：三角形面积。
#define S(a,b,c) (a+b+c)/2
#define AREA(s,a,b,c) sqrt(s*(s-a)*(s-b)*(s-c))

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    float s = S(a,b,c);
    printf("%.3f",AREA(s,a,b,c));
    return 0;

}



//----------------------宏定义：闰年判断
#define LEAP_YEAR(y) y%4==0&&y%100!=0||y%400==0?printf("L"):printf("N")

int main(){
    int y;
    scanf("%d",&y);
    LEAP_YEAR(y);
    return 0;

}

//----------------------实数的打印
int main(){
    float n;
    scanf("%f",&n);
    for(int i = 0; i < 3;i++){
        for(int j = 0; j<=i;j++){
            printf("%6.2f ",n);
        }
        printf("\n");
    }
    return 0;

}
/*
6.2f的格式，意思就是用占位符 %6.2f 的形式来输出
其中 f 表示单精度浮点数，即 float 类型，小数点后的2表示要保留两位小数
小数点前的6表示输出的数字共占6位（小数点也算一位），如果不足6位则用空格补全，数字靠右对齐

如果想让数字靠左对齐可以在占位符中写负号，例如: %-6.2f
如果想用数字0来补全空位可以在占位符前多写个0，例如: %06.2
*/


//----------------------用函数和带参的宏，从三个数中找出最大的数。
#define MAX(a,b,c) (a>b?a:b)>c?(a>b?a:b):c

int max(float a,float b,float c);

int main(){
    float a,b,c;
    
    printf("%.3f\n",MAX(a,b,c));
    max(a,b,c);

    return 0;
}

int max(float a,float b,float c){
    printf("%.3f",(a>b?a:b)>c?(a>b?a:b):c);
    return 0;
}

//----------------------三个字符串的排序

int main(){
    char str1[20],str2[20],str3[30];
    gets(str1);
    gets(str2);
    gets(str3);

    puts(strcmp(str1,str2)<0?(strcmp(str1,str3)<0?str1:str3):(strcmp(str2,str3)<0?str2:str3));
    puts(strcmp(str1,str2)>0?(strcmp(str1,str3)<0?str1:strcmp(str2,str3)>0?str2:str3):strcmp(str2,str3)>0?(strcmp(str1,str3)>0?str1:str3):str2);
    puts(strcmp(str1,str2)>0?(strcmp(str1,str3)>0?str1:str3):(strcmp(str2,str3)>0?str2:str3));
}

//字符串比较大小的函数strcmp(char *a, char *b)
//     a) a == b 返回0
//     b)a < b 返回负值
//     c) a > b返回正值

//----------------------输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。写三个函数； ①输入10个数；②进行处理；③输出10个数。
int min(int n[]);
int max1(int n[]);

int main(){
    int n[10];
    for(int i = 0;i <10;i++){
        scanf("%d",&n[i]);
    }

    min(n);
    max1(n);

    for(int i = 0;i <10;i++){
        printf("%d ",n[i]);
    }

    return 0;

}

int min(int n[]){
    int tmp ,min = 0;
    for(int i = 0;i <10;i++){
        min = n[min]<n[i]?min:i;
    }

    tmp = n[0];
    n[0] = n[min];
    n[min] = tmp;
    
    return 0;
}

int max1(int n[]){
    int tmp ,max = 0;
    for(int i = 0;i <10;i++){
        max = n[max]>n[i]?max:i;
    }

    tmp = n[9];
    n[9] = n[max];
    n[max] = tmp;
    
    return 0;
}

//----------------------有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数。写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数,输入数据的个数n n个整数 移动的位置m
int move(int str[],int n);

int main(){
    int n,m;
    scanf("%d",&n);
    int str[n];
    for(int i =0;i < n;i++){
        scanf("%d",&str[i]);
    }

    move(str,n);

    for(int i =0;i < n;i++){
        printf("%d ",str[i]);
    }
    return 0;
}

int move(int str[],int n){
    int m,tmp;
    scanf("%d",&m);
    for(int i = 0; i < m;i++){
        tmp = str[n-1];
        for(int j = n-1;j >=0;j--){
            str[j+1] = str[j]; 
        }
        str[0] = tmp;
    }
    return 0;
}


//----------------------有n人围成一圈，顺序排号。从第1个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来的第几号的那位
//数组
int main(){
   int n,str[50],i,j;
   scanf("%d",&n);
   int current = -1;                      //开始报数后，current前移带数组下标为0的位置

   for(int i = 0;i <n;i++){
      str[i] = i+1;
   }

   while(n!=1){
      for(j = 0;j < 3;j++){
         current = (current+1)%n;               //这里求出的是数组的下标
      }

      for(j = current;j<n-1;j++){
         str[j] = str[j+1];
      }
      n--;
      current--;
   }

   printf("%d",str[0]);
   return 0;
}

//链表
typedef struct node{
   int data;
   struct node *next;
}Node,*List;

List Init_list(int n);                    //初始化表，传入的n为所要求的人数 
void find_del(List head,int m,int k);

int main(){
   int n;
   scanf("%d",&n);
   List head = (Node *)malloc(sizeof(Node));
   head = Init_list(n);                    
   find_del(head,1,3);

   return 0;

}

List Init_list(int n){                           //初始化表，传入的n为所要求的人数 
   List t = (List)malloc(sizeof(Node));
   t->next = NULL;  
   List head = t;                   //定义一个头节点，存放指针t的地址，为了最后一个节点指向头节点的后一个数据，也就是1的位置 
   for(int i = 1;i <=n;i++){
      List tmp = (List)malloc(sizeof(Node));
      tmp->data = i;
      tmp ->next = NULL;
      t ->next = tmp;
      t = tmp;
   }
   t->next = head ->next;              //此时的t作为尾节点，其指针指向1(也就是head->next) （循环）

   return head;
}

void find_del(List head,int m,int k){     
   Node *p,*t;                      //这里定义两个指针，p指向正在报数的地址，t指向p的前驱节点 
   int i;
   p = head->next;
   // p = head;
   // for(i = 1;i <=m;i++){            //这里做的是定位到第几个数据开始报，因为题目从1开始报数，所以这里其实可以不用写成循环。直接用p=head->next就可以
   //    t = p;                        //每循环一次t指向p，p指向下一个节点 
   //    p = p->next;
   // }
   while(p->next!=p){              //循环链表，p=p->next代表只剩下p节点
      for(i = 1;i<k;i++){
         t = p;
         p = p->next;
      }
      t->next = p->next;
      free(p);
      p = t->next;
   }
    printf("%d",p->data);                            //while出来，即为所剩下来的数据 
    free(p);                                        
    p = NULL;   

}

//----------------------定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，注意闰年问题。
typedef struct{
   int year;
   int month;
   int day;
}Year;

int main(){
   Year year;
   int str[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   scanf("%d %d %d",&year.year,&year.month,&year.day);
   if(year.year%4!=0){
      int sum = year.day;
      for(int i = 0;i <year.month-1;i++){
         sum += str[i];
      } 
      printf("%d",sum);
   }

   else{
      int sum = year.day;
      str[1] = 29;
      for(int i = 0;i <year.month-1;i++){
         sum += str[i];
      } 
      printf("%d",sum);
   }
   return 0;

}

//----------------------现有有N个学生的数据记录，每个记录包括学号、姓名、三科成绩。 
//编写一个函数input,用来输入一个学生的数据记录。 编写一个函数print,打印一个学生的数据记录。 在主函数调用这两个函数，读取N条记录输入，再按要求输出。 N<100
typedef struct {
   char num[100];
   char name[100];
   int score[3];
}stu;

int input(stu student[],int n);
int print1(stu student[],int n);

int main(){
   int n;
   scanf("%d",&n);
   stu student[n];
   input(student,n);
   print1(student,n);

   return 0;
}

int input(stu student[],int n){
   for(int i = 0;i <n;i++){
      scanf("%s %s %d %d %d",&(student[i].num),&(student[i].name),&(student[i].score[0]),&(student[i].score[1]),&(student[i].score[2]));
   }

   return 0;
}

int print1(stu student[],int n){
   for(int i = 0;i <n;i++){
      printf("%s,%s,%d,%d,%d\n",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
   }
   return 0;
}

//----------------------现有有N个学生的数据记录，每个记录包括学号、姓名、三科成绩。 
//要求打印出3门课的总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩）
//输入：学生数量N占一行每个学生的学号、姓名、三科成绩占一行，空格分开。
//输出：各门课的平均成绩 最高分的学生的数据（包括学号、姓名、3门课成绩）
typedef struct {
   char num[100];
   char name[100];
   int score[3];
}stu;

int input(stu student[],int n);
int print2(stu student[],int n);

int main(){
   int n;
   scanf("%d",&n);
   stu student[n];
   input(student,n);
   print2(student,n);

   return 0;
}

int input(stu student[],int n){
   for(int i = 0;i <n;i++){
      scanf("%s %s %d %d %d",&(student[i].num),&(student[i].name),&(student[i].score[0]),&(student[i].score[1]),&(student[i].score[2]));
   }

   return 0;
}

int print2(stu student[],int n){
   int sum1 = 0,sum2 = 0, sum3 = 0,i = 0,tmp = 0;
   for(;i <n;i++){
      sum1 = sum1 + student[i].score[0];
      sum2 = sum2 + student[i].score[1];
      sum3 = sum3 + student[i].score[2];
      tmp = (student[tmp].score[0]+student[tmp].score[1]+student[tmp].score[2])>(student[i].score[0]+student[i].score[1]+student[i].score[2])?tmp:i;
   }
   printf("%d %d %d\n",sum1/n,sum2/n,sum3/n);
   printf("%s %s %d %d %d",student[tmp].num,student[tmp].name,student[tmp].score[0],student[tmp].score[1],student[tmp].score[2]);
   return 0;
}


//----------------------已有a、b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。
//第一行，a、b两个链表元素的数量N、M,用空格隔开。 接下来N行是a的数据 然后M行是b的数据 每行数据由学号和成绩两部分组成
typedef struct Node{
   int num;
   int score;
   struct Node *next;
}LNode,*Llist;

Llist Initlist(int n);                                            //初始化链表
Llist Copylist(LNode * heada,LNode * headb,int n,int m);          //将两个链表合并（将b的头节点复制到a的尾节点后面）
Llist Sortlist(LNode * heada,int n);                              //冒泡排序，实现学号的从小到大排列
void Output(LNode * heada,int n);                                 //输出

int main(){
   int n,m;
   scanf("%d %d",&n,&m);
   LNode * heada = (LNode *)malloc(sizeof(LNode));                //链表a的头节点
   LNode * headb = (LNode *)malloc(sizeof(LNode));                //链表b的头节点

   heada = Initlist(n);
   headb = Initlist(m);

   Copylist(heada,headb,n,m);
   Sortlist(heada,n+m);
   Output(heada,n+m);

   return 0;

}

Llist Initlist(int n){
   LNode * p = (Llist)malloc(sizeof(LNode));
   p->next = NULL;
   LNode * head = p;
   for(int i = 0;i<n;i++){
      LNode * tmp = (LNode *)malloc(sizeof(LNode));
      tmp->next = NULL;
      scanf("%d %d",&tmp->num,&tmp->score);
      p->next = tmp;
      p = tmp;
   }
   return head;
}

Llist Copylist(LNode * heada,LNode * headb,int n,int m){
   LNode * p = heada;
   int i = 0;
   while(i<n){                                                 //不断把tmp指针后移到链表a的尾节点，然后将a的尾节点tmp指向b的头节点的next节点
      i++;
      p = p->next;
   }
   p->next = headb->next;
   return heada;
}

Llist Sortlist(LNode * heada,int n){                        //冒泡排序
   LNode * tmp = (LNode *)malloc(sizeof(LNode));
   for(int i = 0;i<n-1;i++){
      LNode * p = heada->next;
      for(int j = 0;j <n-i-1;j++){
         if(p->num>p->next->num){                           //p和p的下一个节点的学号进行比较，如果p的学号大，交换数据
            tmp->num = p->next->num;
            tmp->score = p->next->score;
            p->next->num = p->num;
            p->next->score = p->score;
            p->num = tmp->num;
            p->score = tmp->score;
         }
         p = p->next;                                       //p节点后移
      }
   }
   free(tmp);
   return heada;
}

void Output(LNode * heada,int n){
   LNode * tmp = (LNode *)malloc(sizeof(LNode));
   for(int i = 0;i <n;i++){
      tmp = heada->next;                                    //tmp和head同步后移
      printf("%d %d\n",tmp->num,tmp->score);
      heada = tmp;
   }
   free(tmp);
}

//----------------------输出八进制
int main(){
    int n;
    scanf("%d",&n);
    printf("%o",n);
    return 0;
}
/*
输出十进制：%d；
输出八进制：%o；
输出十六进制：%x；
输出单个字符：%c；
输出字符串：%s；
输出变量所在的地址：%p；*/

//----------------------绝对值
/*abs（）和fabs（）的区别：
1、abs（）是针对整型数求绝对值，fabs（）是针对浮点数（小数）求绝对值。 
2、abs（）需要调用stdlib.h头文件，fabs（）需要设备math.h头文件。*/

//----------------------指针&和交接运算符*
int test(int *n);
int testm(int m);

int main(){
    int n = 10,m = 20;
    test(&n);
    testm(m);
    printf("n = %d\n",n);   //n = 11
    printf("m = %d",m);     //m = 20
    return 0;
}

int test(int *n){
    *n = 11;
    return 0;
}

int testm(int m){
    m = 110;
    return 0;
}
/**
 * &n，获取n的地址
 * *n，获取n地址指向的对象
 */

//------------------clock---------------------------
//clock():捕捉从程序开始运行到clock()被调用所耗费的时间，这个时间单位是clock tick，即“时钟打点”
//常数CLK_TCK：机器时钟每秒所走的时钟打点数
#include<time.h>

clock_t start,stop;
// clock_t是函数clock()返回的变量类型
double duration;
// 记录被侧函数运行时间，以秒为单位
int main(){
    start = clock();
    // 开始计时，存入start
    Myfunction();
    // 调用被测函数
    stop = clock();
    // 结束计时
    duration = ((double)(stop-start))/CLK_TCK;
    // 计算运行时间
    // 其他不在测试范围的处理，如输出duration的值
    return 0;
}


