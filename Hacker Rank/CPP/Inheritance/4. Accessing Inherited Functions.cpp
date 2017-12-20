#include<iostream>

using namespace std;

int callA=0;
int callB=0;
int callC=0;
class A
{
protected:

   void func(int  & a)
   {
      a=a*2;
      callA++;
   }
};

class B
{
protected:
   void func(int & a)
   {
      a=a*3;
      callB++;
   }
};

class C
{
protected:
   void func(int & a)
   {
      a=a*5;
      callC++;
   }
};

//custom code start

class D: private A,B,C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val=1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
             int i = 4;
             A aa;
             B bb;
             C cc;
             //A::func(i);
             while(new_val != 1){

             if(new_val %5 ==0){
                 C::func(val);
                 new_val = new_val / 5;


                 /*
                 for(i=0;i<new_val/5;i++){
                     C::func(val);
                 }
                 */
             }
             if(new_val%3 == 0){
                 B::func(val);
                 new_val = new_val / 3;


                 /*
                 for(i=0;i<new_val/3;i++){
                     B::func(val);
                 }*/

             }
             if(new_val%2 == 0){
                 A::func(val);
                 new_val = new_val / 2;
                 /*
                 for(i=0;i<new_val/2;i++){
                     A::func(val);
                 }
                 */

             }
             }
             /*
             aa.func(i);
             bb.func(i);
             cc.func(i);
             */
             //val = new_val;


		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

//custom code end

void D::check(int new_val)
{
       update_val(new_val);
       cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
}


int main()
{
   D d;
   int new_val;
   cin>>new_val;
   d.check(new_val);

}
