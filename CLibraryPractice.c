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

/*------------assert.h--------------*/
//檢查任兩邊大於第三邊
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

/*------------stdint.h--------------*/


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

/*------------string.h--------------*/

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

void main(){

    //distancexy();     //兩點座標算距離
    //evenOrOdd();      //檢查奇偶數
    //roundDown();      //無條件進位到整數第N位(進位到個位，N=1；十位,N=2；百位,N=3;類推N=...)
    //roundUP();        //無條件捨去到整數第N位(捨去到個位，N=1；十位,N=2；百位,N=3;類推N=...)
    //Cauchy();         //柯西不等式
    //triangle();       //檢查任兩邊大於第三邊
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
    //RandWByCharacter();   //讀檔案，逐個字符寫入新檔案(%c中文字會變亂碼)
    //compareSpeed();         //比較同一篇文章 逐行or逐字元 寫入檔案執行速度(scanf輸入開啟的檔名)
}
