#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{
 int a[100],size,search,choice,loc; /*array and variable declaration*/
 int linear_search(int [],int,int); /*funtion declaration*/
 int binary_search(int [],int,int);
 int recursive_binary_search(int [],int,int,int);
 void getdata(int[],int);
 void putdata(int[],int);
 clrscr();
 printf("Enter the array size : \n");
 scanf("%d",&size);   /*store the size of array*/
 getdata(a,size);     /*function call*/
 printf("Enter the element you want to be search : ");
 scanf("%d",&search);
 while(1)
 {
  printf("1.Linear search \n2.Binary search \n3.Recursive Binary Search\n4.Exit\n");
  printf("Enter the choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	 loc=linear_search(a,size,search);
	 break;
   case 2:
	loc=binary_search(a,size,search);
	break;
   case 3:
	loc=recursive_binary_search(a,0,size-1,search);
	break;
   case 4:
	exit(0);
	break;
   default:
	printf("Error");
	exit(1);
  }
  if(loc>=0)
   printf("%dth is the location in an array",loc);
  else
   printf("Location not found");
  getch();
 }
}
void getdata(int a[],int size)    /*function defination*/
{
 int i;
 printf("Enter the element of an array : \n");
 for(i=0;i<size;i++)
 {
  scanf("%d",&a[i]);
 }
}
int linear_search(int a[],int size,int search)     /*function defination*/
{
 int i;
 for(i=0;i<size;i++)
 {
  if(a[i]==search)
  return i+1;
 }
 return -1;
}
int binary_search(int a[],int size,int search)   /*function defination*/
{
 int beg,end,mid;
 beg=0;
 end=size-1;
 while(beg<=end)
 {
  mid=(beg+end)/2;
  if(a[mid]==search)
  return mid+1;
  else if(a[mid]>search)
  end=mid-1;
  else
  beg=mid+1;
 }
 return -1;
}
int recursive_binary_search(int a[],int beg,int end,int search)
{
 int mid;
 if(beg<=end)
 {
  mid=(beg+end)/2;
  if(a[mid]==search)
  return mid+1;
  else if(a[mid]>search)
  return recursive_binary_search(a,beg,mid-1,search);
  else
  return recursive_binary_search(a,mid+1,end,search);
 }
 return -1;
}