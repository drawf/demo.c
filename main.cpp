#include <iostream>

void testBasicType() {

    //字符类型 char
    char c = 'c';
    printf("c 的值：%c --> char 所占字节：%d\n", c, sizeof(char));
    //c 的值：c --> char 所占字节：1

    //短整形 short
    short sh = 32;
    printf("sh 的值：%d --> short 所占字节：%d\n", sh, sizeof(short));
    //sh 的值：32 --> short 所占字节：2

    //整形 int
    int i = 90;
    printf("i 的值：%d --> int 所占字节：%d\n", i, sizeof(int));
    //i 的值：90 --> int 所占字节：4

    //长整形 long
    long l = 12312;
    printf("l 的值：%ld --> long 所占字节：%d\n", l, sizeof(long));
    //l 的值：12312 --> long 所占字节：8

    //单精度浮点型 float
    float f = 12.3;
    printf("f 的值：%f --> float 所占字节：%d\n", f, sizeof(float));
    //f 的值：12.300000 --> float 所占字节：4

    //双精度浮点型 double
    double d = 234.3433;
    printf("d 的值：%lf --> double 所占字节：%d\n", d, sizeof(double));
    //d 的值：234.343300 --> double 所占字节：8

    printf("Hello %s\n", "World!");
    //Hello World!

    printf("无符号八进制：%o\n", 023);
    printf("有符号八进制：%#o\n", 023);
    //无符号八进制：23
    //有符号八进制：023

    printf("无符号十六进制：%x\n", 0x23443);
    printf("有符号十六进制：%#x\n", 0x23443);
    //无符号十六进制：23443
    //有符号十六进制：0x23443

    //关于printf()中的输出占位符：%c、%d等，其中%为输出格式描述符。

    //char --> %c
    //short、int --> %d ：d为digital（数字）
    //long --> %ld
    //float --> %f
    //double --> %lf

    //字符串 --> %s
    //无符号八进制 --> %o
    //有符号八进制 --> %#o
    //无符号十六进制 --> %x
    //有符号十六进制 --> %#x

}

void testPointer() {

    int i = 50;//定义变量 i=50
    int *p;//声明 int 类型的指针变量 p，指针也是变量
    p = &i;//在指针变量 p 中存储 i 的地址，&i 是取变量 i 的地址

    printf("i 的地址：%#x\n", &i);
    printf("i 的地址：%#x\n", p);//p 变量中存的是 i 的地址
    printf("p 的地址：%#x\n", &p);
    printf("i 的值：%d\n", *p);//用一元运算符 * 来返回 p 变量存的地址的变量的值，即 i 的值
    //i 的地址：0x55d1674c
    //i 的地址：0x55d1674c
    //p 的地址：0x5e5d2740
    //i 的值：50

    /*指针变量的强大之处就在于，他能通过内存地址去操作对应内存地址的内容*/
    *p = 20;//通过 *p 我们操作 i 变量，给 i 变量赋值20
    printf("i 的值变成了：%d\n", *p);
    //i 的值变成了：20

}

/*指针变量也是变量，所以指针也是可以运算的*/
void testPointerVariable() {
    int arr[] = {75, 40, 25, 80};

    printf("数组的地址：%#x\n", &arr);
    printf("这样得到数组的地址：%#x\n", arr);
    printf("第一个元素的地址：%#x\n", &arr[0]);
    printf("数组的值：%d\n", arr);
    printf("第一个元素的值：%d\n", *arr);
    //数组的地址：0x55b89730
    //这样得到数组的地址：0x55b89730
    //第一个元素的地址：0x55b89730
    //数组的值：1438160688
    //第一个元素的值：75

    /*0x55b89730 转为十进制为 1438160688，且*arr返回的是第一个元素的值，*/
    /*所以数组类型的变量，存储就是首个元素的地址*/

    printf("=============\n");

    for (int i = 0; i < 4; i++) {
        printf("索引方式取数组元素：%d\n", arr[i]);
    }

    printf("=============\n");

    int *pInt = arr;
    for (int j = 0; j < 4; j++) {
        printf("指针方式取数组元素：%d\n", *pInt);
        pInt++;
    }

    //索引方式取数组元素：75
    //索引方式取数组元素：40
    //索引方式取数组元素：25
    //索引方式取数组元素：80
    //=============
    //指针方式取数组元素：75
    //指针方式取数组元素：40
    //指针方式取数组元素：25
    //指针方式取数组元素：80

    /*通过指针变量 pInt 自增的方式，打印出了数组各元素的值，不难发现数组是*/
    /*用一段连续的内存空间存储数据，我们可以用同类型的指针，通过运算来直接操作内存*/
    /*注意：指针类型需要跟数组类型一致，在CLion编辑器下，两类型不一致时会报错，如：*/
    /*incompatible pointer types 'float *' and 'int[4]'*/

}


/*
 * C语言的函数定义和Java的函数定义类似，只是没有 public ，private 等这样的权限控制
 *
 * 返回值类型 函数名(参数类型 参数名称, ...){
 *      函数体
 * }
 */
int add(int num1, int num2) {
    return num1 + num2;
}

/*
 * 通过传入指针类型可以在方法中修改参数原来的值
 */
void changeNumByPointer(int *pInt) {
    printf("形参 pInt 的地址：%#x\n", pInt);
    *pInt = 90;
}

/*
 * 非指针类型的形参，会为 i 变量开辟新的内存空间，所以做不到修改参数原来的值
 */
void changeNum(int i) {
    printf("形参 i 的地址：%#x\n", &i);
    i = 80;
}

void testChangeNum() {

    int i = 10;
    printf("i 原来的值：%d\n", i);
    printf("i 原来的地址：%#x\n", &i);
    //i 原来的值：10
    //i 原来的地址：0x50f548fc

    changeNumByPointer(&i);
    printf("i 现在的值：%d\n", i);
    //形参 pInt 的地址：0x50f548fc
    //i 现在的值：90

    changeNum(i);
    printf("i 现在的值：%d\n", i);
    //形参 i 的地址：0x50f548cc
    //i 现在的值：90
}

void testSecondaryPointer() {

    int i = 10;
    int *pInt = &i;//一级地址存 i 的地址
    int **pInt1 = &pInt;//二级地址存 pInt 的地址

    printf("i 的地址：%#x\n", &i);
    printf("pInt 的地址：%#x\n", &pInt);
    printf("用二级指针取 pInt 的地址：%#x\n", pInt1);
    printf("用二级指针取 i 的地址：%#x\n", *pInt1);
    printf("用二级指针取 i 的值：%d\n", **pInt1);
    //i 的地址：0x56d688fc
    //pInt 的地址：0x56d688f0
    //用二级指针取 pInt 的地址：0x56d688f0
    //用二级指针取 i 的地址：0x56d688fc
    //用二级指针取 i 的值：10

    **pInt1 = 20;
    printf("用二级指针修改 i 的值：%d\n", i);
    //用二级指针修改 i 的值：20

}

void logcat() {
    printf("随便打印一下..\n");
}

void testFuncPointer() {
    //函数指针定义：返回值类型 (函数指针)(函数参数) = 函数地址
    void (*pFunc)() = &logcat;

    pFunc();
    printf("函数的地址：%#x\n", logcat);
    printf("函数的地址：%#x\n", &logcat);
    printf("函数指针的值：%#x\n", pFunc);
    printf("函数指针的地址：%#x\n", &pFunc);
    //函数的地址：0xd5754c0
    //函数的地址：0xd5754c0
    //函数指针的值：0xd5754c0
    //函数指针的地址：0x5268b8f8
}

int minus(int num1, int num2) {
    return num1 - num2;
}

/*接收 一个返回值为int类型，输入两个int类型参数的函数指针 和 两个int类型参数*/
void calculate(int(*pFunc)(int, int), int num1, int num2) {
    int i = pFunc(num1, num2);
    printf("计算完成：%d\n", i);
}

void testFuncPointer1() {

    calculate(&add, 2, 3);
    //计算完成：5
    calculate(&minus, 2, 3);
    //计算完成：-1

}

void callback(char *msg) {
    printf("网络请求回调：%s\n", msg);
}

void requestNet(char *url, void(*pCallBack)(char *)) {
    printf("请求url：%s\n", url);
    sleep(2);//模拟网络耗时
    char *msg = "我是返回的数据";
    pCallBack(msg);

    //请求url：www.baidu.com
    //网络请求回调：我是返回的数据
}

void testFuncPointer2() {
    char *url = "www.baidu.com";
    requestNet(url, &callback);
}

/*字符数组*/
void testCharArray() {

    char arr[15] = {'a', 'b', ' ', 'd', 'e'};
    printf("字符数组：%s\n", arr);//用 %s 占位符可将字符数组作为字符串打印出来
    //字符数组：ab de

    arr[1] = 'Y';//修改第二个元素
    printf("修改了第二个字符：%s\n", arr);
    //修改了第二个字符：aY de

}

/*字符指针*/
void testCharPointer() {

    char *s = "Hello World!";//是一段连续的内存地址
    printf("字符指针内存地址：%#x\n", s);//返回的是首个字符 H 的内存地址
    printf("打印字符串：%s\n", s);
    //字符指针内存地址：0x7ce4c63
    //打印字符串：Hello World!

    char *t = s + 4;//这样 t 就指向了首个 o 字符
    printf("o 字符的地址：%#x\n", t);
    //o 字符的地址：0x7ce4c67

    //截取字符串 llo World!
    s += 2;//s 指向了首个 l 字符
    while (*s) {
        printf("%c", *s);
        s++;
    }
    //llo World!

}

/*拼接字符串*/
void testSpliceString() {

    //用来存储合并字符串的容器
    char arr[50] = {'=', '='};

    char *c1 = "abcd";
    char *c2 = "efg";

    strcat(arr, c1);//将 c1 拼接到 arr ，不会清除原来的数据
    strcat(arr, c2);
    printf("拼接结果：%s\n", arr);
    //拼接结果：==abcdefg

    strcpy(arr, c1);//strcpy，将 c1 拼接到 arr ，会清除原来的数据
    strcat(arr, c2);
    printf("拼接结果：%s\n", arr);
    //拼接结果：abcdefg

}

/*查找单个字符*/
void testQueryChar() {

    char *s = "abcdefg hijklmn;";
    char *p = strchr(s, 'g');//查找某个字符，返回该字符的指针
    printf("截取 g 字符往后的字符串：%s\n", p);
    //截取 g 字符往后的字符串：g hijklmn;

    if (p) {//p 存储的是 g 字符的内存地址
        printf("g 字符索引位置：%d\n", p - s);
        //g 字符索引位置：6

        printf("截取 g 字符往后的字符串：");
        while (*p) {//用指针递增的方法打印 g 字符往后的字符串
            printf("%c", *p);
            p++;
        }
        //截取 g 字符往后的字符串：g hijklmn;

    } else {
        printf("没有找到 g 字符\n");
    }
}

/*查找字符串*/
void testQueryString() {

    char *s = "这是一个中abcdefg hijk文字符串！";
    char *k = "abc";

    char *p = strstr(s, k);//查找某个字符串，返回该字符串的指针（其实是该字符串的首字符 a 的指针）
    printf("截取 abc 字符串往后的字符串：%s\n", p);
    //截取 abc 字符串往后的字符串：abcdefg hijk文字符串！

    if (p) {
        printf("abc 字符串索引位置：%d\n", p - s);
        //abc 字符串索引位置：15

        printf("打印 b 字符：%c\n", *++p);//p+1就得到了 b 的内存地址
        //打印 b 字符：b

    } else {
        printf("没有找到 abc 字符串\n");
    }
}

/*定义一个Person结构体，关键字为struct*/
struct Person {
    char *name;
    int age;
};

struct News {
    char title[123];
    char *content;
};

/*简单使用*/
void testSimpleStruct() {

    struct Person person = {"张三", 25};
    printf("name:%s ==> age:%d\n", person.name, person.age);
    //name:张三 ==> age:25

    person.name = "Bob";
    person.age = 23;
    printf("name:%s ==> age:%d\n", person.name, person.age);
    //name:Bob ==> age:23

    struct News news;
    //news.title = "我是新闻标题"; 这是错误的赋值方法！报错为：array is not assignable
    // 因为 news.title 是数组类型，"我是新闻标题"是 char * 类型
    strcpy(news.title, "我是新闻标题");//正确的赋值方法
    news.content = "我是内容";
    printf("title:%s ==> content:%s\n", news.title, news.content);
    //title:我是新闻标题 ==> content:我是内容

}

/*定义结构体时，同时定义一个或多个它的变量或指针。按照属性不能初始化原则，变量或指针都是没有值的*/
struct Product {
    char *name;
    char *desc;
} product, *pProduct, product1;

/*匿名结构体，可以做单例使用*/
struct {
    char *name;
    int age;
} *pStudent, student;

void testSimpleStruct2() {

    product.name = "苹果手机";
    product.desc = "就是贵";
    printf("name:%s ==> desc:%s\n", product.name, product.desc);
    //name:苹果手机 ==> desc:就是贵

    product1.name = "小米手机";
    product1.desc = "广告就是多";
    pProduct = &product1;
    /*通过指针操作属性，结构体指针使用 p->xx 操作符，相当于 (*p).xx 的简写*/
    printf("name:%s ==> desc:%s\n", (*pProduct).name, pProduct->desc);
    //name:小米手机 ==> desc:广告就是多

    pStudent = &student;
    (*pStudent).name = "张三";
    pStudent->age = 23;
    printf("name:%s ==> age:%d\n", student.name, student.age);
    //name:张三 ==> age:23

};

struct ProductBean {
    int total;
    int state;

    /*嵌套已定义好的结构体*/
    struct Product product;

    /*嵌套新声明的结构体*/
    struct Readme {
        char *content;
    } readme;
};

void testSimpleStruct3() {

    ProductBean pb = {10, 1, {"苹果手机", "就是贵"}, "售出不退"};
    printf("total:%d ==> state:%d ==> name:%s ==> desc:%s ==> content:%s\n",
           pb.total, pb.state, pb.product.name, pb.product.desc, pb.readme.content);
    //total:10 ==> state:1 ==> name:苹果手机 ==> desc:就是贵 ==> content:售出不退

    ProductBean pb1;
    ProductBean *p = &pb1;
    p->total = 2;
    p->state = 1;
    p->product.name = "小米手机";
    p->product.desc = "就是便宜";
    p->readme.content = "开机不会爆炸";
    printf("total:%d ==> state:%d ==> name:%s ==> desc:%s ==> content:%s\n",
           p->total, p->state, p->product.name, p->product.desc, p->readme.content);
    //total:2 ==> state:1 ==> name:小米手机 ==> desc:就是便宜 ==> content:开机不会爆炸

};

void testStructArray() {

    Person person1 = {"张三", 21};
    Person person2 = {"李四", 33};

    Person persons[] = {person1, person2, {"赵六", 55}};

    //计算数组长度
    int len = sizeof(persons) / sizeof(Person);
    printf("数组长度：%d\n", len);
    //数组长度：3

    //通过指针遍历数组
    for (Person *pPerson = persons; pPerson < persons + len; pPerson++) {
        printf("name:%s ==> age:%d\n", pPerson->name, pPerson->age);
    }
    //name:张三 ==> age:21
    //name:李四 ==> age:33
    //name:赵六 ==> age:55

}

void testMalloc() {
    //静态内存分配创建数组，数组大小是固定的
    //int i = 10;
    //int a[i];

    int len = 5;
    printf("数组的长度：%d\n", len);
    //数组的长度：5

    //开辟内存，大小为len*4字节，p是数组的首地址，p就是数组的名称
    int *p = (int *) malloc(len * sizeof(int));

    //给数组元素赋值（使用这一块刚刚开辟出来的连续的内存空间）
    for (int i = 0; i < len; i++) {
        p[i] = rand() % 100;
        printf("数组元素值为：%d ==> 地址为：%#x\n", p[i], &p[i]);
    }
    //数组元素值为：7 ==> 地址为：0x8ec02850
    //数组元素值为：49 ==> 地址为：0x8ec02854
    //数组元素值为：73 ==> 地址为：0x8ec02858
    //数组元素值为：58 ==> 地址为：0x8ec0285c
    //数组元素值为：30 ==> 地址为：0x8ec02860

    int addLen = 5;
    printf("数组增加的长度：%d\n", addLen);
    //数组的长度：5

    //新内存大小为(len+addLen)*4字节
    int *p1 = (int *) realloc(p, (len + addLen) * sizeof(int));
    if (p1 == NULL) {
        printf("内存重新分配失败");
    } else {
        for (int i = 0; i < len + addLen; i++) {
            p1[i] = rand() % 100;
            printf("数组元素值为：%d ==> 地址为：%#x\n", p1[i], &p1[i]);
        }
    }
    //数组元素值为：72 ==> 地址为：0x8ec02850
    //数组元素值为：44 ==> 地址为：0x8ec02854
    //数组元素值为：78 ==> 地址为：0x8ec02858
    //数组元素值为：23 ==> 地址为：0x8ec0285c
    //数组元素值为：9 ==> 地址为：0x8ec02860
    //数组元素值为：40 ==> 地址为：0x8ec02864
    //数组元素值为：65 ==> 地址为：0x8ec02868
    //数组元素值为：92 ==> 地址为：0x8ec0286c
    //数组元素值为：42 ==> 地址为：0x8ec02870
    //数组元素值为：87 ==> 地址为：0x8ec02874

    //手动释放内存，free()释放动态分配的内存空间
    if (p != NULL) {
        free(p);
        p = NULL;
    }

    if (p1 != NULL) {
        free(p1);
        p1 = NULL;
    }

}

void testStructMalloc() {

    Person *person = (Person *) malloc(sizeof(Person) * 5);
    Person *p = person;
    p->name = "小明";
    p->age = 17;
    p++;
    p->name = "小李";
    p->age = 22;
    p++;
    p->name = "小王吧";
    p->age = 13;

    for (Person *i = person; i < person + 3; i++) {
        printf("name:%s ==> age:%d\n", i->name, i->age);
    }
    //name:小明 ==> age:17
    //name:小李 ==> age:22
    //name:小王吧 ==> age:13

}

struct Dog {
    char *name;
    int age;

    //结构体中不能有函数实体
    void (*wow)(char *);
};

void dogWow(char *msg) {
    printf("dog 说:%s\n", msg);
}

void testDogWow() {

    Dog dog = {"吉娃娃", 2, dogWow};//将函数名称赋值给函数指针
    dog.wow("汪汪！");
    printf("函数的地址：%#x\n", dogWow);
    //dog 说:汪汪！
    //函数的地址：0xcf56d20

}

typedef char *Name;//简单别名

struct ImageInfo {
    char *name;
    int size;
    char *path;
};

typedef ImageInfo aImg;//结构体别名，只是个新名字，不是变量

void reImageName(ImageInfo *pImageInfo, char *msg) {
    pImageInfo->name = msg;
}

void testAlias() {
    Name a = "小李子";//Name 为 char* 类型
    printf("Name的值：%s\n", a);
    //Name的值：小李子

    aImg img = {"风景图", 122, "我是图片路径"};
    reImageName(&img, "美女图");
    printf("name:%s ==> size:%d ==> path:%s\n", img.name, img.size, img.path);
    //name:美女图 ==> size:122 ==> path:我是图片路径

}

union mVal {
    char c;//1 byte
    short s;//2 byte
    int i;//4 byte
    long l;//8 byte
};

void testUnion() {

    mVal u;
    u.c = 'd';
    u.i = 10;//最后一次赋值有效

    printf("char:%c ==> int:%d ==> 大小：%d\n", u.c, u.i, sizeof(u));
    //char:
    //==> int:10 ==> 大小：8
    //u.c的值被损坏了，使用共同体的主要目的是，同一时间只使用一个变量

}

enum NetStatus {
    NET_SUCCESS,
    NET_ERROR
};

void testWriteTextFile() {
    char *path = "/Users/drawf/Desktop/c.txt";
    char *content = "我是测试内容，i am test content!";

    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("打开文件失败");
        return;
    }

    fputs(content, fp);

    fclose(fp);
}

void testReadTextFile() {
    char *path = "/Users/drawf/Desktop/c.txt";

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("打开文件失败");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {
        printf("%s", buffer);
    }

    fclose(fp);

}

void testBinaryFile() {
    char *currFile = "/Users/drawf/Desktop/c.txt";
    char *destFile = "/Users/drawf/Desktop/c_copy.txt";

    FILE *currFile_p = fopen(currFile, "rb");
    FILE *destFile_p = fopen(destFile, "wb");

    int buffer[1024];
    int len;

    while ((len = fread(buffer, sizeof(int), 1024, currFile_p)) != 0) {
        fwrite(buffer, sizeof(int), len, destFile_p);
    }

    fclose(destFile_p);
    fclose(currFile_p);
}

void testEncryptFile() {
    char *currFile = "/Users/drawf/Desktop/c.txt";
    char *encryptedFile = "/Users/drawf/Desktop/c_encrypted.txt";

    FILE *currFile_p = fopen(currFile, "rb");
    FILE *encryptedFile_p = fopen(encryptedFile, "wb");

    int buffer;
    while ((buffer = fgetc(currFile_p)) != EOF) {
        fputc(buffer ^ 8, encryptedFile_p);
    }

    fclose(encryptedFile_p);
    fclose(currFile_p);
}

void testDecryptFile() {
    char *encryptedFile = "/Users/drawf/Desktop/c_encrypted.txt";
    char *decryptedFile = "/Users/drawf/Desktop/c_decrypted.txt";

    FILE *encryptedFile_p = fopen(encryptedFile, "rb");
    FILE *decryptedFile_p = fopen(decryptedFile, "wb");

    int buffer;
    while ((buffer = fgetc(encryptedFile_p)) != EOF) {
        fputc(buffer ^ 8, decryptedFile_p);
    }

    fclose(decryptedFile_p);
    fclose(encryptedFile_p);
}

void testFileSize() {
    char *currFile = "/Users/drawf/Desktop/c.txt";
    FILE *p = fopen(currFile, "r");

    fseek(p, 0l, SEEK_END);
    long size = ftell(p);

    printf("文件大小：%ld byte\n", size);

    fclose(p);
}


#define MAX 100
#define NAME "bob"

void testMax() {
    int i = 99;
    if (i < MAX) {
        printf("i<Max");
    }

    printf("%s", NAME);
}

void _jni_define_func_write() {
    printf("write\n");
}

void _jni_define_func_read() {
    printf("read\n");
}

#define jni(NAME) _jni_define_func_##NAME()

void testJni() {

    jni(write);
    jni(read);
}

#define LOG(LEVEL, FORMAT, ...) printf(#LEVEL);printf(#FORMAT,__VA_ARGS__);
#define LOGI(FORMAT, ...) LOG("INFO:",#FORMAT,__VA_ARGS__);
#define LOGE(FORMAT, ...) LOG("ERROR:",#FORMAT,__VA_ARGS__);
#define LOGW(FORMAT, ...) LOG("WARN:",#FORMAT,__VA_ARGS__);

#define ABC(LEVEL) printf(#LEVEL)


void testLog() {
//    ABC("info");

//    LOG("abc:", "%s", "sjakdf");

//    LOGI("%s", "就哭了jkl")
    LOGE("%d", 1242)
}

int main() {

//    testBasicType();

//    testPointer();

//    testPointerVariable();

//    testChangeNum();

//    testSecondaryPointer();

//    testFuncPointer();

//    testFuncPointer1();

//    testFuncPointer2();

//    testCharArray();

//    testCharPointer();

//    testSpliceString();

//    testQueryChar();

//    testQueryString();

//    testSimpleStruct();

//    testSimpleStruct2();

//    testSimpleStruct3();

//    testStructArray();

//    testMalloc();

//    testStructMalloc();

//    testDogWow();

//    testAlias();

    testUnion();
//====================
//    printf("res:%d", add(2, 5));

//    int i = 90;
//    printf("i 的内存地址：%#x\n", &i);
//    testChangeNum(&i);
//    printf("i 的值：%d", i);

//    testPointers();

//    testFuncPointer();

//    testFuncPointer1(&add, 3, 5);
//    testFuncPointer1(minus, 3, 5);

//    requestNet("www.baidu.com", netCallBack);

//    testCharArray();

//    testCharPointer();

//    testSpliceString();

//    testQueryChar();

//    testQueryString();

//    testStrToInt();

//    testStruct();

//    testStruct2();

//    testStruct3();

//    testStructArr();

//    testStructMalloc();

//    testDogWow();

//    testAlias();

//    testWriteTextFile();

//    testReadTextFile();

//    testBinaryFile();

//    testEncryptFile();

//    testDecryptFile();

//    testFileSize();

//    testUnion();

//    testMax();

//    testJni();

//    testLog();
    return 0;
}