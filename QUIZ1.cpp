#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int x;//global variables
int y;
int n;
int v=0;
int array1 [1000];
int array2 [1000];
char p;
static int maxjug,minjug;

void show(int a, int b);
int setdisvalue();

int recursivedisplay(int e, int u)//display array values using recurrsion
{  int l=e;
 static int h=u;
	if(l!=u)
	{
	cout<<">";
	cout<<"("<<array1[l]<<","<<array2[l]<<")";	
	return recursivedisplay(l+1,h);//recursive
	}
	
}

void show(int a, int b)//display 
{  int w=a;
   int e =b;
  
  
if(maxjug==5 && minjug==3)//for the given example actions are include here 
{

if (w==0 && e==0)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tstart with empty jug"<<endl;;
	array1[v]=w;
    array2[v]=e;
    v++;
}
if ((a==3 && b==0)||(a==3 && b==3))
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tFill A"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
if (a==0 && b==3)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tpouring water from A to B untill A is empty"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
if (a==3 && b==1)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tFill jug  A"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}

if (a==0 && b==4)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tpouring water from A to B untill A is empty"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
if (a==0 && b==1)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tpouring water from A to B untill A is empty"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
if (a==1 && b==0)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tEmpty B"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
if (a==1 && b==5)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tpouring water from A to B untill B is full"<<endl;
    array1[v]=w;
    array2[v]=e;
    v++;
}
}
else//for other examples
{  
if (e==n && w>=0)
{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\tpouring water untill final value comes "<<endl;
	array1[v]=w;
    array2[v]=e;
    v++;
}
	else
	{
	cout << setw(12) <<w << setw(12) <<e<<setw(12)<<"\t\t Action not pre-defined"<<endl;
	array1[v]=w;
    array2[v]=e;
    v++;
    }
}
 


}

int setdisvalue()
{ int f=v;
/*for(int i=0; i<v;i++)
{   cout<<">";
	cout<<"("<<array1[i]<<","<<array2[i]<<")";
}
*/

return recursivedisplay(0,f);
	

}

int gcd(int n,int m) //this function is used to get the greatest common divisor of both jug capacities
{ 
	if(m<=n && n%m == 0)
		return m;//recursive
	if(n < m)
		return gcd(m,n);//recursive
	else
		return gcd(m,n%m);//recrsive
}


int cal(int n,int f,int g)
{
int x_quintity = f, y_quintity = g;
int t;

show(x_quintity, y_quintity);//intial states od the jugs displays

if(x_quintity!=n && y_quintity!=n)
{ 
	if(x_quintity==0) //if A jug is empty is make full
	{x_quintity = x;
	return cal(n,x_quintity,y_quintity);//recursive
	}
	
	if(y_quintity==y)//if B jug is full it make empty
	{
    y_quintity = 0;
    return cal(n,x_quintity,y_quintity);//recursive
	}
	
	else
	{
	int r=y-y_quintity;
   int e=x_quintity;
   
   if (r< e)
   return cal(n,x_quintity-r,y_quintity+r);//recursive
   
   else
   return cal(n,x_quintity-e,y_quintity+e);//recursive
		
	}
	
}

}

void getdata() //get the user input data
{
  int i=0, j=0;
  int arr[10000];
  char temp;
  do {
      scanf("%d%c", &arr[i], &temp);
      i++;
      
  } while(temp != '\n' & i!=3);//only first three aray value are selected
   
 if(arr[0]>=0 && arr[1]>=0 && arr[2]>=0 && arr[0]<=40000 && arr[1]<=40000 && arr[2]<=40000) 
{ 
n=arr[2];
x=arr[0];
y=arr[1];	
maxjug=y;
minjug=x;
}

if(arr[0]<0 || arr[1]<0 || arr[2]<0 || arr[0]>40000 || arr[1]>40000 || arr[2]>40000)
{ cout<<" your current given inputs cannot be accepted.please enter the correct values again."<<endl;
  cout<<"enter here:";
  int i=0, j=0;
  int arr[10000];
  char temp;
  do {
      scanf("%d%c", &arr[i], &temp);//use c input type get usr inputs
      i++;
      
     } while(temp != '\n' & i!=3);
  
n=arr[2];
x=arr[0];
y=arr[1];	
maxjug=y;
minjug=x;
}

}


int main()
{
cout<<"--------------------------Insructions for two water jug puzzle programme---------------------------------------"<<endl;
cout<<" Enter values in one line separated by spaces-(firstvalue <space> secondvalue <space> thirdvalue)"<<endl;
cout<<"               *) First value-Enter the capacity of the first(small) jug."<<endl;
cout<<"               *) Second value -Enter the capacity of the second(large) jug."<<endl;
cout<<"               *) Third value -Enter the liters of water required out of the two jugs."<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
cout<<" #)Important!!!!-values should not be lager than 40000."<<endl;
cout<<" #)Actions on table can display only for the  Example value(3 5 4)."<<endl;
cout<<" #)If you didn't enter the correct values for small large jugs the answer may be differ. "<<endl;
cout<<"   so always enter correct values."<<endl;
cout<<"##################################################################################################"<<endl;
cout<<"Enter your values here:";
getdata();
int k=gcd(x,y);
if(n<x || n<y)
{ if(n%k==0)//if operation can done gcd value should be a factor of n
  {  
    cout<<endl;
    cout<<"-----------------------Table.Explanation of the output----------------------------"<<endl;
    cout << setw(20) <<"Jugs"<< setw(30) <<"Action"<<endl;
    cout << setw(7) <<"A ("<<minjug<<"Liters)"<<setw(7) <<"B("<<maxjug<<"Liters)"<<endl;
    cal(n,0,0);
    cout<<endl<<endl;
    cout<<"Output:";
    setdisvalue();
  }
  else
  cout<<"This operation is currently not possible...\n";  
 }
else
  cout<<"This operation is currently not possible....\n"; 
}
