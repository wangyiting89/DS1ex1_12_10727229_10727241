// 10727229 ������ ��T�G�A
// 10727241 �����@ ��T�G�A


#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cctype>
#include<string>


using namespace std ;


struct Title {
    unsigned long long title ;     //�s�O��

	Title * first ;
	Title * last ;

	Title * next ;
} ;

void FindFactor2( unsigned long long model, int i, long long int times,long long int count );
void Numbers2( int n, int i, long long int &times  );
void Numbers( int n );
void FindFactor( Title * temp, int j );

static long long int number = 1; //�q1�}�l
static long long int number2 = 1 ;

int main() {

  int i = 0 ;	 //title��index
  int way = 0;//�p���k
  cout << "�п�ܭp��覡(1���j��2�����j�Ϋ���L��h�X)" << endl;
  cin >> way ;
  int n = 0 ; //��J���Ʀr

  while( way == 1 || way == 2 ) {
    long long int in= 0;  //�P�_��J����
    bool digit = false;   //�P�_��J�O�_���Ʀr
    string str ;   //��J���r��
    cout << "�п�J����1��92�������" << endl;

 	while(digit == true|| in == 0){
      digit = false;
      cin >> str;

  	  for(int y = 0 ; y < str.length() ; y++ ){  // �ݿ�J���r��O�_�����Ʀr
        if(!isdigit(str[y])) digit = true;
  	  }
      if ( digit )cout << "�Э��s��J����1��92�������" << endl;//�D�Ʀr

      else {               // �Ʀr
        n = atoi(str.c_str());//�N�r���ഫ���Ʀr
        if(!digit&& n>=1 &&n <= 92)    digit = false;
        else {
          if (!digit&& n>=0) digit = true;// �Ʀr���b�]��
          cout << "�Э��s��J����1��92�������" << endl;
        } // else
      }// else

      in++;
  	} // while

    if ( way == 1 ) {  // �j�骩
      cout << "----------�}�l----------" << endl;
  	  Numbers( n );
  	}
  	else if ( way == 2 ){ //���j��
      cout << "----------�}�l----------" << endl;
      long long int times = 0;   // ��~���
      Numbers2( n, i,times);
      times--;
  	   cout << " ( �~��� : " << times << " ) "<< endl;
    }
    cout << "----------����----------" << endl<< endl;

    number = 1;//��l��
    number2 = 1;//��l��
    i = 0;//��l��
    cout << "�п�ܭp��覡(1���j��2�����j�Ϋ���L��h�X)" << endl;
    cin >> way ;

  } // while

  cout << "----------���¨ϥ�----------" << endl;
  return 0;

} // main()

void FindFactor( Title * temp, int j ){  //�j�骩��]�Ƭۮt�̤p

  long long int basic = 1 ;   //��e�ᥭ���
  long long int loopCount = 0 ; //�����
  long long int first = 0;
  long long int second = 0;

  while( temp->title >= basic*basic ) {

    basic++ ;  // ��쥭���

  }

  basic--;

  while ( basic > 0  ) {
    //��ӶO�ƪ��X�Ҧ��]�� �Ө�]�Ƭ۴�̤p�s�b���`�]�ƪ��������
    //�ҥH��X�Ҧ��]�ƧY�i����]��

    if ( temp->title%basic == 0 ) {
      first = basic ;
      second = temp->title/first ;
      basic = 0 ;
    }

    basic-- ;
    loopCount++ ;
  } // while

  if ( second < first ) { // �洫
	long long int min = first ;
    first = second ;
   	second = min ;
  }


  cout << " [ " << j+1 << " ] " << temp->title << " = " << first << " * "  << second  ;
  cout<<  "  ( ���: " << loopCount << " )" << endl  ;

}

void Numbers( int n ){
    Title * head = new Title ;
    Title * temp = head ;
    Title * front = head ; // �R����
	long long int number = 1 ; //�q1�}�l
	temp->title = number ;
	long long int number2 = 1 ;
	int j = 0 ; //title��index

	while ( j <= n-1 && n <= 92 ) { //�O��
    	FindFactor(temp, j);
        //cout << temp->title<<endl;

        temp->next = new Title ;

        temp->next->title = temp->title +  number2 ;
		number = temp->next->title ;
		Title * walk = temp ;
	    number2 = walk->title ;

		temp = temp->next ;
		j++ ;
		 while(head!= temp){ //�R���e���e�ΰO������
           front = head;
           head = head->next;
           delete front;
		 }

	} // while

	cout << " ( �~��� : " << j << " )" << endl;
}

void Numbers2( int n, int i, long long int &times  ){

    times ++ ;//�~���

    long long int  count = 0 ;  // �����
	static long long int basicc = 1 ;
    unsigned long long model = 1 ; // ��O��

	if ( i < n && n <= 92  ){

		if ( times == 1 ) model= 1 ;
        else model = number2 + number ;

		while( model >= basicc*basicc ) basicc++ ; //�䥭���
		basicc-- ;

		unsigned long long int ni = 1;

		FindFactor2( model, i, basicc,  count ) ;

		number2 = number ;
		number = model ;
		i++;  //���U�@��


		Numbers2( n, i, times );

	}
	else return;

}
void FindFactor2( unsigned long long model, int i, long long int basicc, long long int count ){


	    count++ ; //�ư�ƪ�

		if ( count == 10000000 ) 	cout<< " [ " << i + 1 << " ] " << model << " = " <<  "  ( Inner recursion over 10000000 times )" << endl  ;
		else if(  model%basicc == 0 ) {

			cout << " [ " << i + 1 << " ] " << model << " = " << basicc << " * "  <<  model/basicc  ;
			cout<<  "  ( Inner loop : " << count << " )" << endl  ;
		     return  ;
		}// if
		else if (  model%basicc != 0 ) {

		    basicc-- ;
			FindFactor2( model, i, basicc, count ) ; //�i�J�U�@�Ӽh

		} // else if


} // FindFactor2

