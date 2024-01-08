//老師好，之前在趕論文final，抱歉現在開始追。
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*math.h*/

// double sqrt(double x) / double pow(double x, double y) 兩點座標算距離
void distancexy(){

    int x1, y1, x2, y2;
    printf("please enter first coordinater (x1 , y1).\n");
    scanf("%d , %d",&x1 ,&y1);
    printf("please enter sencend (x2 , y2).\n");
    scanf("%d , %d",&x2 ,&y2);

    int dis;
    dis = (int)sqrt(pow((x1 - x2),2)+pow((y1 - y2),2));
    printf("The distance is %d\n", dis);

}

// double fmod(double x, double y) 檢查奇偶數
void evenOrOdd(){
    int x;
    int remainder;
    printf("please enter a number.\n");
    scanf("%d",&x);

    remainder = (int)fmod((double)x , 2);

    if(remainder == 0)
        printf("The number %d is even\n", (int)x);
    else
        printf("The number %d is odd.\n", (int)x);
}

//double ceil(double x) 無條件進位到整數第N位(進位到個位，N=1；十位,N=2；百位,N=3)
void roundUP(){
    int x;
    int n;
    double y;
    printf("please enter a number.\n");
    scanf("%d",&x);
    printf("Is rounding up to N position?\n");
    scanf("%d",&n);

    y = x/(pow(10 , (n - 1)));
    y = ceil(y);
    y = y * (pow(10 , (n - 1)));
    printf("Round up to %d position.\n", n);
    printf("%d is rounded up to %d", x, (int)y);
}

//double floor(double x) 無條件捨去到整數第N位(捨去到個位，N=1；十位,N=2；百位,N=3)
void roundDown(){
    int x,n;
    double y;
    printf("please enter a number.\n");
    scanf("%d",&x);
    printf("Is Rounding Down to N position?\n");
    scanf("%d",&n);

    y = x/(pow(10 , (n - 1)));
    y = floor(y);
    y = y * (pow(10 , (n - 1)));
    printf("Round down to %d position.\n", n);
    printf("%d is rounded down to %d", x, (int)y);
}

//double fabs(double x) 柯西不等式
void Cauchy(){
    int a,b,c,d;
    double y1,y2;
    printf("please enter four number to calculate Cauchy's inequality.\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    y1 = sqrt(pow(a,2) + pow(b,2)) * sqrt(pow(c,2) + pow(d,2));
    y2 = fabs(a * c + b * d);
    if(y1 >= y2)
        printf("As %f >= %f ,The result of Cauchy's inequality hold \n", y1,y2);
    else
        printf("As %f < %f ,The result of Cauchy's inequality don't hold \n", y1,y2);
}

/*------------assert.h-只有一個函式assert()-------------*/
//又說是巨集
//void assert(int expression) 檢查任兩邊大於第三邊 
void triangle(){
    int a,b,c;
    int t1,t2,t3;
   
    printf("Please enter three side lengths of the triangle.\n");
    scanf("%d,%d,%d", &a,&b,&c);
    t1=a+b;
    t2=a+c;
    t3=b+c;
    assert(t1 > c); 
    assert(t2 > b);
    assert(t3 > a);
    printf("Three side lengths of %d, %d, %d are correst.\n", a,b,c);
    
}
//檢查檔案是否可以開啟
void checkFileOp(void)
{
    
    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);

    FILE *fd;
    fd = fopen (fileName, "r");
    assert (fd);
    printf("File can open.");
    fclose(fd);
}

/*------------ctype.h--------------*/
//int isupper(int c) int tolower(int c)檢查是大寫→大寫轉小寫
void upToLower(){
    int count=0;
    char enterText[30]={0};
    printf("Please enter a sentence and change uppercase to lowercase.\n");
    
    fgets(enterText, 30, stdin); //stdin由鍵盤輸入之意

    for(int h=0; h<sizeof(enterText) ; h++) //檢查是否有大寫
        count += isupper(enterText[h]);

    if(count >0){
        printf("Your sentence is converted :");
        for(int k=0 ; k<sizeof(enterText) ; k++)
            enterText[k] = tolower(enterText[k]);
    }
    printf("\n");
    puts(enterText);
}

//int isupper(int c) int tolower(int c)檢查是小寫→小寫轉大寫
void lowerToUp(){
    int count=0;
    char enterText[30]={0};
    printf("Please enter a sentence and change lowercase to uppercase.\n");
    
    fgets(enterText, 30, stdin); //stdin由鍵盤輸入之意

    for(int h=0; h<sizeof(enterText) ; h++) //檢查是否有小寫
        count += islower(enterText[h]);

    if(count >0){
        printf("Your sentence is converted :");
        for(int k=0 ; k<sizeof(enterText) ; k++)
            enterText[k] = toupper(enterText[k]);
    }
    printf("\n");
    puts(enterText);
}

// isxdigit() 單個檢查是否為十六進位，並修改至正確
void LegalIPV4(){
    char ipv4[9]="";
    char count=0;
    char check[8]={1};
    printf("Please enter Hexadecimal IPV4\n");
    scanf("%8s",ipv4);

    do{
        count = 0;
        for(int i=0 ; i<8 ; i++){
            if(isxdigit(ipv4[i])==0){
                printf("The %dth charactor isn't right,enter again.\n",i);
                scanf("%8s",ipv4);
                check[i] = 0;  //0表示不正確
                }
            else
                check[i] = 1;  //1表示正確輸入16進位
            
            count += check[i];
        }
        if(count ==8) break;
    }while(count ==0);
    printf("The Ip :%s is correct.",ipv4);
}

//int isalnum(int c)/ void *memset(void *str, int c, size_t n) 檢查密碼是否為字母或數字，並修改正確
void checkPassword(){
    char passwordd[10];
    char count=0;
    memset(passwordd, 27, 11); //27表示未填的空格
    printf("Please enter a password containing letters and numbers.\n");
    scanf("%10s",passwordd);

    for(int i=0 ; i <10 ; i++){
        if(passwordd[i] == 27)
            break;
        else
            count++; //計算填入的密碼有多長
    }
        for(int i=0 ; i<count ; i++){
            if(isalnum(passwordd[i])==0){
                printf("The %dth charactor isn't right,enter whole password again.\n",i);
                scanf("%10s",passwordd);
                i--;
                }
        }
    printf("The password :%s is correct.",passwordd);
}

//int ispunct(int c) 密碼第一項要是標點符號
void checkPassword2(){
    char passwordd[10]={'a',};
    char count=0;
    memset(passwordd, 27, 10); //27表示未填的空格
    printf("Please enter a password containing letters and numbers and first word must be punctuaion.\n");
    scanf("%10s",passwordd);
    
    for(int i=0 ; i <10 ; i++){
        if(passwordd[i] == 27)
            break;
        else
            count++; //計算填入的密碼有多長
    }
        while(ispunct(passwordd[0])==0){
            printf("first word must be punctuaion,enter whole password again.\n");
            scanf("%10s",passwordd);
        }
        
        for(int i=1 ; i<count-1 ; i++){
            if(isalnum(passwordd[i])==0){
                printf("The %dth charactor isn't right,enter whole password again.\n",i);
                scanf("%10s",passwordd);
                i--;
                }
        }
    printf("The password :%s is correct.",passwordd);
}

/*------------stdio.h--------------*/

//FILE *fopen(const char *filename, const char *mode)寫有日期的日記
void diary(){
    FILE * fp;
    char word[100];
    scanf("%[^\n]",word);

    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime ); 
    info = localtime( &rawtime );
    strftime(buffer, 80, "%Y-%m-%d ", info);
 
    fp = fopen ("article.txt", "w+");
    fprintf(fp, "%s\n", buffer);
    fprintf(fp, "%s", word);
    fclose(fp);
}

//int fclose(FILE *stream) 開完建檔計算英文字數
void readFileCountWords(){
    
    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fp;
    int c;
    int wordCount=0;
    
    fp = fopen(fileName,"r"); //讀取文章
    while(1)
    {
        c = fgetc(fp);
        if( feof(fp) )
        {
            break ;
        }
        printf("%c", c);
        if(isalpha(c))
            wordCount++;
    }
    printf("\nThe article has %d words.",wordCount);
    fclose(fp);
}

//int fprintf(FILE *stream, const char *format, ...)讀檔案並逐行寫入新檔案
int readAndWrite(){

    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];

    FILE *fpWrite; //寫入的文件
    fpWrite = fopen ("copyArticle.txt", "w+");

    if(fpread == NULL) 
    {
        perror("Error: ");
    }
    while(1)
    {
        if( feof(fpread) )
        { 
            break ;
        }
        if( fgets (strRead, 200, fpread)!=NULL ) 
        {
            fprintf(fpWrite, "%s", strRead);
        }
    }
    fclose(fpread);
    fclose(fpWrite);
    return 0;
}

//int fgetc(FILE *stream)讀檔案，逐個字符寫入新檔案
int RandWByCharacter()
{
    int c;
    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];

    FILE *fpWrite; //寫入的文件
    fpWrite = fopen ("copyArticle.txt", "w+");

    if(fpread == NULL) 
    {
        perror("Error: ");
    }
    while(1)
    {
        if( feof(fpread) ){
            break ;}
        c = fgetc(fpread);
        fprintf(fpWrite, "%c", c);
    }
    fclose(fpread);
    fclose(fpWrite);
    return 0;
}


//char *fgets(char *str, int n, FILE *stream)列印出文件
void printArticle(){

    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];

    if(fpread == NULL) 
    {
        perror("Error: ");
    }
    while(1)
    {
        if( feof(fpread) )
        { 
            break ;
        }
        if( fgets (strRead, 200, fpread)!=NULL ) 
        {
            printf("%s",strRead);
        }
    }
    fclose(fpread);
}
//int remove(const char *filename) 複製文件後，刪除舊文件
void deletOldFile(){

    int ret;
    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];

    FILE *fpWrite; //寫入的文件
    fpWrite = fopen ("copyArticle.txt", "w+");

    if(fpread == NULL) 
        perror("Error: ");
    while(1)
    {
        if( feof(fpread) )
            break ;

        if( fgets (strRead, 200, fpread)!=NULL ) 
            fprintf(fpWrite, "%s", strRead);
    }
    fclose(fpread);
    fclose(fpWrite);

    ret = remove(fileName);
    if(ret == 0) 
        printf("%s file has been deleted.",fileName);
    else 
        printf("ERROR: %s file cna't be deleted.",fileName);

}

//int sprintf(char *str, const char *format, ...) 整數轉字串，回傳字串
char * int2string(char * str , int num)
{

    sprintf(str, "Transfer is :%d", num);
    puts(str);

    return str;
}

/*------------stdint.h--------------*/
//無符號整數 指定 巨集處理整數大小(維基修改)
void uintSize(){

    //無符號整數 指定 巨集處理整數大小  
    uint8_t ux8 = UINT8_C(8);;
    uint16_t ux16 = UINT16_C(16);
    uint32_t ux32 = UINT32_C(16);
    uint64_t ux64 = UINT64_C(16);

    printf("%lu\n",sizeof(ux8));
    printf("%ld\n",sizeof(ux16));
    printf("%lu\n",sizeof(ux32));
    printf("%ld\n",sizeof(ux64));
}

//整數常量巨集(維基修改),印出值
void intMaxLeast(){

   //使用巨集 給值
    intmax_t ymax = INTMAX_C(3490);   //INTMAX_C(value)把有符號整型值 value 擴展以適應數據類型 intmax_t
    uintmax_t uymax = UINTMAX_C(3490);
    int_least8_t z8least= INT8_C(128);  //INTN_C(value) 把有符號整型值 value 擴展以適應數據類型 int_leastN_t
    uint_least8_t uz8least= UINT8_C(128);
    int_least16_t zl16east= INT16_C(256);
    uint_least16_t uz16least= UINT16_C(256);

    printf("%ld , %ld\n",sizeof(ymax) , ymax);
    printf("%lu , %lu\n",sizeof(uymax) , uymax);
    printf("%ld , %ld\n",sizeof(z8least) , z8least);
    printf("%lu , %lu\n",sizeof(uz8least) , uz8least);
    printf("%ld , %ld\n",sizeof(zl16east) , zl16east);
    printf("%lu , %lu\n",sizeof(uz16least) , uz16least);
}
//最快速的整數型態 (維基修改),印出值
void intfast(){
    //使用巨集 給值
    int_fast8_t xf8= INT8_C(128);  //位寬不少於指定值的最快速的整型
    uint_fast8_t xuf8= UINT8_C(128);
    int_fast16_t xf16= INT16_C(256);
    uint_fast16_t xuf16= UINT16_C(256);
    int_fast32_t xf32= INT16_C(512);
    uint_fast32_t xuf32= UINT16_C(512);

    printf("%ld , %ld\n",sizeof(xf8) , xf8);
    printf("%lu , %lu\n",sizeof(xuf8) , xuf8);
    printf("%ld , %ld\n",sizeof(xf16) , xf16);
    printf("%lu , %lu\n",sizeof(xuf16) , xuf16);
    printf("%ld , %ld\n",sizeof(xf32) , xf32);
    printf("%lu , %lu\n",sizeof(xuf32) , xuf32);
}

//指標的整數型態 (維基修改),印出值
void intPtr(){

    //指標的整數型態
    intptr_t ptr= INT8_C(128);    //是 long int
    uintptr_t ptru= UINT8_C(128); //是 long unsigned int
    intptr_t ptr2= INT16_C(256);  
    uintptr_t ptru2= UINT16_C(256);

    printf("%ld , %ld\n",sizeof(ptr) , ptr);
    printf("%lu , %lu\n",sizeof(ptru) , ptru);
    printf("%ld , %ld\n",sizeof(ptr2) , ptr2);
    printf("%lu , %lu\n",sizeof(ptru2) , ptru2);

}
//有符號整數(維基修改),印出值
void intSize(){

    //有符號整數 指定 巨集處理整數大小  
    int8_t x8 = INT8_C(127); //128 will overflow
    int16_t x16 = INT16_C(32767); //(2^15 -1) 32768 will overflow
    int32_t x32 = INT32_C(512);
    int64_t x64 = INT64_C(1024);

    printf("%ld , %ld\n",sizeof(x8) , x8);
    printf("%ld , %ld\n",sizeof(x16) , x16);
    printf("%ld , %ld\n",sizeof(x32) , x32);
    printf("%ld , %ld\n",sizeof(x64) , x64);

}

/*------------stdlib.h--------------*/
//int atoi(const char *str) 計算三個數字的平均數，將字串轉成整數
void avgForThree(){
    char num[30];
	int numchange[30]={0};
	int value,value2;
	char i=0;
  	float avg;

	setbuf(stdout, NULL);

	while(scanf("%s", num)!=EOF) 
	{
        printf("Enter Three-digit integer.");
        value = atoi(num);
		for(int i=2; i>=0; i--)
		{
			value2 = value % 10;
			numchange[i] = value % 10;
			value = (value-value2)/10;
		}
		avg = (float)((numchange[0]+numchange[1]+numchange[2])/3);
		printf("%.6f",avg);
	}
}

//	void srand(unsigned int seed) 隨機產生座標，給定數字範圍
void randomm(){
    int N;
    printf("Determine axis range for 0 to N\n");
    scanf("%d",&N);
    srand( time(NULL) ); //設定亂數種子
    int tr = rand();
    int ts = rand();
    int r = tr % N;
    int s = ts % N;
    printf("random is %d\n", r);
    printf("The axis position is (%d , %d)\n", r, s);
}


//	int rand(void) 產生大樂透
    void lotto(){
    time_t t;
    char ch;
    int chosee[6]={0};
    int i=0;
    int check=0;
    int tr;
    srand( time(NULL) ); //設定亂數種子
    printf("Get Lotto number.\n");
    
    do{ 
        check=0;
        tr = rand()%50;
        for(int j=0 ; j<=i ; j++)
        {
            if(chosee[j] == tr)
                check++;
                break;
        }
        if(check ==0){
            chosee[i] = tr;
            i++;}
    }while(i < 6);

    printf("Lotto number is :\n");
    for(int k=0 ; k<6 ; k++)
        printf("%d ", chosee[k]); 
}

//int abs(int x) 算距離一維座標
void disOneAxis()
{
    int x,y;
    int distance;
    long long size;
    size = pow(2,32)/2; 
    printf("Enter two numbers in the range %d to %d\n",size,-1*size);
    printf("Separate two numbers with space.\n");
    scanf("%d%d",&x,&y);
    distance = x-y;
    distance = abs(distance);
    printf("The distance is : %d",distance);
}

//void *calloc(size_t nitems, size_t size) 將動態記憶體陣列的字串顯示兩種型態
void strDisTwoType(){
    char input[50];
    char *strArr;
    int arrLen = 50;
    int i;  //為什麼allocation裡的for的i都事先宣告?

    strArr = calloc( arrLen, sizeof(char) );  //strArr取得記憶體,可視為陣列，初始化為0
    if( strArr == NULL )
        fprintf(stderr, "Can't get required memory\n"); //將錯誤訊息寫入File *stderr

    printf("Enter a sentence within fifty words.\n");
    scanf("%[^\n]", input);
    strcpy(strArr,input);

    for (i = 0; i < strlen(strArr); ++i) {
        printf("%d ", strArr[i]);
    }
    printf("\n");
    puts(strArr);
    free(strArr);

}

//div_t div(int numer, int denom)除法與驗算
void Division()
{
    div_t output;
    int x,y;
    
    printf("Enter Divisor and dividend ,Separate two numbers with space.\n");
    scanf("%d%d",&x,&y);

    output = div(x, y);
    printf("%d ÷ %d = %d.....%d\n",x,y, output.quot,output.rem);
    printf("乘法驗算 : ( %d - %d ) = %d x %d",x,output.rem,y,output.quot);
}
//double strtod(const char *str, char **endptr) 計算班級的成績平均數
void gradeAvg(){
    char str[30];
    char *ptr;
    double ret;
    char n;
    double avg;

    printf("Enter class size\n");
    scanf("%d",&n);
    for(int i=0 ; i<n ;i++)
    {
        printf("Enter the %dth student’s grade.\n",i+1);
        scanf("%s",str);
        ret = strtod(str, &ptr);
        avg += ret;
    }
    avg = avg/n;
    printf("Class average of grade is %lf\n", avg);
}

//long int strtol(const char *str, char **endptr, int base)16進位 字串轉 長整數
void str16ToInt(){
    char *endptr;
    long int num;
    char input[10];
    char str[10] = {'\0'};
    char x16[10] = {'\0'};

    printf("Enter a hexadecimal number within 10 digits.\n");
    scanf("%s",input);

    strcpy(str, input); //123放入str
    strcpy(x16,"0x");
    strcat(x16 , str);  //ox123: 組合成16進位，但為字串
    puts(x16);

    num = strtol(x16, &endptr, 0); //如果寫0，會根據字串前綴做判斷

    if (*endptr != '\0') {
        printf("String tansfer to INT False.\n");
    } else {
        printf("Transfer is: %ld\n", num); //結果0x123是轉成10進位數291
    }
}

//int system(const char *command) 操作命令題字元 輸入指令
void command(){

    char command[50];
    char input[50];
    printf("輸入命令提示字元的指令.\n");
    scanf("%s",input);

    strcpy( command, input );
    system(command);

}

/*------------string.h--------------*/

//void *memcpy(void *str1, const void *str2, size_t n)
//將檔案每行前兩個文字覆蓋 "@@""
void starOnText()
{
    char fileName[100];
    printf("Enter the file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];
    
    FILE *fpWrite; //寫入的文件
    fpWrite = fopen ("copyArticle.txt", "w+");

    char src[] = "@@";

    if(fpread == NULL) 
    {
        perror("Error: ");
    }
    while(1)
    {
        if( feof(fpread) )
            break ;
        if( fgets (strRead, 200, fpread)!=NULL ) 
        {
            memcpy(strRead, src, strlen(src)); //文件每行前兩字改成@@
            fprintf(fpWrite, "%s", strRead);
        }
    }
    fclose(fpread);
    fclose(fpWrite);
}

//void *memset(void *str, int c, size_t n) 將句子搜尋關鍵字並覆蓋space
void textOnspace()
{
    char text[] ="Scholar John et al said: There is evidence that obese people are more likely to have high blood pressure and diabetes.";
    char str[200];
    
    strcpy(str, text);

    for(int i=0 ; i<strlen(str) ; i++)
    {
        if(str[i]=='e' && str[i+1]=='t' && str[i+2]==' ' && str[i+3]=='a' && str[+4]=='l')    
            {
                memset(str,' ',i+5); //搜尋 et al 覆蓋space
            }
    }
    puts(str);

}

//char *strrchr(const char *str, int c) 輸入你的信箱，會輸出你的帳號
void findAccount()
{
    int account;
    char str[100];
    printf("Enter your E-mail, and display your account.\n");
    scanf("%s",str);
    const char ch = '@';
    char *ret;
    
    ret = strrchr(str, ch);
    account = (int)(ret - str); //陣列@的記憶體位址-第一位記憶體位置
    printf("Account is :");
    for(int i=0 ; i<account ; i++)
        printf("%c",str[i]);
}

//int strncmp(const char *str1, const char *str2, size_t n) 開啟兩文件比較文字內容是否全相等
void compareTwofile()
{
    char check=0;
    int ret;
    
    char fileName[100];
    printf("Enter the first file name to open.\n");
    scanf("%s", fileName);
    
    FILE *fpread; //讀的文件1
    fpread = fopen(fileName,"r");  //可以直接用陣列名稱const char *filename
    char strRead[200];
    
    char fileName2[100];
    printf("Enter the second file name to open.\n");
    scanf("%s", fileName2);

    FILE *fpread2; //讀的文件2
    fpread2 = fopen(fileName2,"r");  //可以直接用陣列名稱const char *filename
    char strRead2[200];

    if(fpread == NULL || fpread2 == NULL) 
        perror("Error: ");
        
    while(check ==0)
    {
        if( feof(fpread) )
            break ;
        if( fgets (strRead, 200, fpread)!=NULL && fgets (strRead2, 200, fpread2)!=NULL) 
        {
            ret = strncmp(strRead, strRead2, strlen(strRead));
            if(ret == 0)
                continue;
            else
                check++;
        }
    }
    fclose(fpread);
    fclose(fpread2);

    if(check == 0)
        printf("The contents of two Text are equal.");
    else
        printf("The contents of two Text arn't equal.");

}

//char *strncpy(char *dest, const char *src, size_t n)找信箱的帳號
void findMail()
{
    char dest[20];
    memset(dest, '\0', sizeof(dest));
    
    int account;
    char str[100];
    printf("Enter your E-mail, and display your account.\n");
    scanf("%s",str);
    const char ch = '@';
    char *ret;
    
    ret = strrchr(str, ch);
    account = (int)(ret - str); //陣列@的記憶體位址-第一位記憶體位置

    printf("Account is : ");
    strncpy(dest, str, account);
    printf("%s",dest);
}

/*------------time.h--------------*/
//time_t time(time_t *seconds) 文字加亂碼
void mash(){
    char catch[100] = "I love you.";
    char mash[100];
    char *ptr;
    long ret;
    printf("Enter a sentence.\n");
    scanf("%[^\n]",catch);
    for(int i=0 ; i<strlen(catch) ; i++)
    {
        srand( time(NULL) ); //設定亂數種子
        int tr = rand()%128;
        mash[i*2] = catch[i];
        mash[i*2+1] = (int)tr;
    }
    printf("原始文字是：|%s|\n",catch);
    printf("加密的文字是：|%s|\n",mash);
}

//clock_t clock(void) 比較同一篇文章 逐行or逐字元 寫入檔案執行速度
void compareSpeed()
{
   clock_t start_t, end_t;
   double total_t;
   int i,j;

   start_t = clock();
   //以下放計算程式跑了多少時間---------
   i = readAndWrite();
   end_t = clock(); 
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU total time :%f\n", total_t  );

   start_t = clock();
   //以下放計算程式跑了多少時間---------
   j = RandWByCharacter();
   end_t = clock(); 
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU total time :%f\n", total_t  );
}

//char *ctime(const time_t *timer) 顯示現在時間，並將年修改到前面
void currentTime()
{
    char times[40];
    char times2[40];
    time_t curtime;
    time(&curtime);  //time()是放秒數
    strcpy(times , ctime(&curtime));
    for(int i=0 ; i<=3 ; i++)
        times2[i] = times[i+20];
    for(int j=3 ; j<=18 ; j++)
    {
        times2[j+1] = times[j];
    }
   printf("Current Time is: %s", times2);
}

//struct tm *gmtime(const time_t *timer) CMT時間 台灣美國倫敦
#define BST (+1)
#define NST (+8)
#define EST (-8)
void CMTtime()
{
 
   time_t rawtime;
   struct tm *info;
 
   time(&rawtime); //取得格林威治時間
   info = gmtime(&rawtime );
   
   printf("格林威治時間：\n");
   printf("Britain : %2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
   printf(" Taiwan : %2d:%02d\n", (info->tm_hour+NST)%24, info->tm_min);
   printf("America : %2d:%02d\n", (info->tm_hour+EST)%24, info->tm_min);
}

//struct tm *localtime(const time_t *timer) 顯示當地時間，並將年修改到前面
void localTime()
{
    char times[40];
    char times2[40];
    time_t curtime;
    struct tm *info;
    time(&curtime);  //time()是放秒數

    info = localtime( &curtime );

    strcpy(times , asctime(info)); //是一個函數，其參數為struct tm
    
    for(int i=0 ; i<=3 ; i++)
        times2[i] = times[i+20];
    for(int j=3 ; j<=18 ; j++)
    {
        times2[j+1] = times[j];
    }
   printf("Local Time is: %s", times2);
}



void main(){

    //distancexy();     //兩點座標算距離
    //evenOrOdd();      //檢查奇偶數
    //roundDown();      //無條件進位到整數第N位(進位到個位，N=1；十位,N=2；百位,N=3;類推N=...)
    //roundUP();        //無條件捨去到整數第N位(捨去到個位，N=1；十位,N=2；百位,N=3;類推N=...)
    //Cauchy();         //柯西不等式
    //triangle();       //檢查任兩邊大於第三邊
    //checkFileOp();    //檔案是否可以開啟(scanf輸入開啟的檔名)
    //upToLower();      //檢查是大寫→大寫轉小寫
    //lowerToUp();      //檢查是小寫→小寫轉大寫
    //LegalIPV4();      //單個檢查是否為十六進位，並修改至正確
    //checkPassword();  //檢查密碼是否為字母或數字，並修改正確
    //checkPassword2(); //密碼第一項要是標點符號
    //avgForThree();    //計算三個數字的平均數，將字串轉成整數，保留小數精度6位
    //randomm();        //隨機產生座標，給定數字範圍
    //mash();           //文字加亂碼
    //lotto();          //大樂透產生機
    //diary();          //寫日記有日期的創文字檔
    //readFileCountWords();//開完建檔計算英文字數(scanf輸入開啟的檔名)
    //readAndWrite();     //讀檔案並逐行寫入新檔案(scanf輸入開啟的檔名)
    //printArticle();     //列印出文件(scanf輸入開啟的檔名)
    //deletOldFile();     //複製文件後，刪除舊文件(scanf輸入開啟的檔名)
    //RandWByCharacter(); //讀檔案，逐個字符寫入新檔案(%c中文字會變亂碼)
    //uintSize();         //無符號整數 指定 巨集處理整數大小
    //intMaxLeast();      //整數常量巨集(維基修改),印出值
    //intfast();          //最快速的整數型態 (維基修改),印出值
    //intPtr();           //指標的整數型態 (維基修改),印出值
    //intSize();          //有符號整數(維基修改),印出值
    //compareSpeed();     //比較同一篇文章 逐行or逐字元 寫入檔案執行速度(scanf輸入開啟的檔名)
    //starOnText();       //將檔案每行前兩個文字覆蓋 "@@"
    //textOnspace();      //將句子搜尋關鍵字並覆蓋space
    //findAccount();      //輸入你的信箱，會輸出你的帳號 by strrchr()
    //compareTwofile();   //開啟兩文件比較文字內容是否全相等(scanf輸入開啟的檔名)
    //findMail();         //找信箱的帳號 by strncpy()
    //currentTime();      //顯示現在時間，並將年修改到前面
    //CMTtime();          //CMT時間 台灣美國倫敦
    //localTime();        //顯示當地時間，並將年修改到前面
    //disOneAxis();       //算距離一維座標
    //strDisTwoType();    //將動態記憶體陣列的字串顯示兩種型態
    //Division();         //除法與驗算
    //gradeAvg();         //計算班級成績的平均數
    //str16ToInt();       //16進位 字串轉 長整數
    //command();          //操作命令題字元 輸入指令

    /*
    char str[10];       //整數轉字串，輸入(空字串，整數)。char * int2string(char * str , int num)
    int2string(str ,123);
    */

}
