// 10727229 黃雅萱 資訊二乙
// 10727241 王薏婷 資訊二乙


#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cctype>
#include<string>


using namespace std ;


struct Title {
    unsigned long long title ;     //存費氏

	Title * first ;
	Title * last ;

	Title * next ;
} ;

void FindFactor2( unsigned long long model, int i, long long int times,long long int count );
void Numbers2( int n, int i, long long int &times  );
void Numbers( int n );
void FindFactor( Title * temp, int j );

static long long int number = 1; //從1開始
static long long int number2 = 1 ;

int main() {

  int i = 0 ;	 //title的index
  int way = 0;//計算方法
  cout << "請選擇計算方式(1為迴圈2為遞迴或按其他鍵退出)" << endl;
  cin >> way ;
  int n = 0 ; //輸入之數字

  while( way == 1 || way == 2 ) {
    long long int in= 0;  //判斷輸入次數
    bool digit = false;   //判斷輸入是否為數字
    string str ;   //輸入之字串
    cout << "請輸入介於1至92的正整數" << endl;

 	while(digit == true|| in == 0){
      digit = false;
      cin >> str;

  	  for(int y = 0 ; y < str.length() ; y++ ){  // 看輸入之字串是否全為數字
        if(!isdigit(str[y])) digit = true;
  	  }
      if ( digit )cout << "請重新輸入介於1至92的正整數" << endl;//非數字

      else {               // 數字
        n = atoi(str.c_str());//將字串轉換成數字
        if(!digit&& n>=1 &&n <= 92)    digit = false;
        else {
          if (!digit&& n>=0) digit = true;// 數字不在侷限
          cout << "請重新輸入介於1至92的正整數" << endl;
        } // else
      }// else

      in++;
  	} // while

    if ( way == 1 ) {  // 迴圈版
      cout << "----------開始----------" << endl;
  	  Numbers( n );
  	}
  	else if ( way == 2 ){ //遞迴版
      cout << "----------開始----------" << endl;
      long long int times = 0;   // 算外圈數
      Numbers2( n, i,times);
      times--;
  	   cout << " ( 外圈數 : " << times << " ) "<< endl;
    }
    cout << "----------結束----------" << endl<< endl;

    number = 1;//初始化
    number2 = 1;//初始化
    i = 0;//初始化
    cout << "請選擇計算方式(1為迴圈2為遞迴或按其他鍵退出)" << endl;
    cin >> way ;

  } // while

  cout << "----------謝謝使用----------" << endl;
  return 0;

} // main()

void FindFactor( Title * temp, int j ){  //迴圈版找因數相差最小

  long long int basic = 1 ;   //找前後平方數
  long long int loopCount = 0 ; //內圈數
  long long int first = 0;
  long long int second = 0;

  while( temp->title >= basic*basic ) {

    basic++ ;  // 找到平方數

  }

  basic--;

  while ( basic > 0  ) {
    //找該費數的出所有因數 而兩因數相減最小存在於總因數的中間兩數
    //所以找出所有因數即可找到兩因數

    if ( temp->title%basic == 0 ) {
      first = basic ;
      second = temp->title/first ;
      basic = 0 ;
    }

    basic-- ;
    loopCount++ ;
  } // while

  if ( second < first ) { // 交換
	long long int min = first ;
    first = second ;
   	second = min ;
  }


  cout << " [ " << j+1 << " ] " << temp->title << " = " << first << " * "  << second  ;
  cout<<  "  ( 圈數: " << loopCount << " )" << endl  ;

}

void Numbers( int n ){
    Title * head = new Title ;
    Title * temp = head ;
    Title * front = head ; // 刪除用
	long long int number = 1 ; //從1開始
	temp->title = number ;
	long long int number2 = 1 ;
	int j = 0 ; //title的index

	while ( j <= n-1 && n <= 92 ) { //費氏
    	FindFactor(temp, j);
        //cout << temp->title<<endl;

        temp->next = new Title ;

        temp->next->title = temp->title +  number2 ;
		number = temp->next->title ;
		Title * walk = temp ;
	    number2 = walk->title ;

		temp = temp->next ;
		j++ ;
		 while(head!= temp){ //刪除前面占用記憶體資料
           front = head;
           head = head->next;
           delete front;
		 }

	} // while

	cout << " ( 外圈數 : " << j << " )" << endl;
}

void Numbers2( int n, int i, long long int &times  ){

    times ++ ;//外圈數

    long long int  count = 0 ;  // 內圈數
	static long long int basicc = 1 ;
    unsigned long long model = 1 ; // 放費氏

	if ( i < n && n <= 92  ){

		if ( times == 1 ) model= 1 ;
        else model = number2 + number ;

		while( model >= basicc*basicc ) basicc++ ; //找平方數
		basicc-- ;

		unsigned long long int ni = 1;

		FindFactor2( model, i, basicc,  count ) ;

		number2 = number ;
		number = model ;
		i++;  //換下一個


		Numbers2( n, i, times );

	}
	else return;

}
void FindFactor2( unsigned long long model, int i, long long int basicc, long long int count ){


	    count++ ; //數圈數的

		if ( count == 10000000 ) 	cout<< " [ " << i + 1 << " ] " << model << " = " <<  "  ( Inner recursion over 10000000 times )" << endl  ;
		else if(  model%basicc == 0 ) {

			cout << " [ " << i + 1 << " ] " << model << " = " << basicc << " * "  <<  model/basicc  ;
			cout<<  "  ( Inner loop : " << count << " )" << endl  ;
		     return  ;
		}// if
		else if (  model%basicc != 0 ) {

		    basicc-- ;
			FindFactor2( model, i, basicc, count ) ; //進入下一個層

		} // else if


} // FindFactor2

