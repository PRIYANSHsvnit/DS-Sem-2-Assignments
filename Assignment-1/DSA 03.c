#include<stdio.h>
#include<string.h>

int main()
{
 int n;
 
 printf("Enter N\n");
 scanf("%d",&n);
    
   struct students
 {
   char name[30];
   int rn;
   float marks;
 }a[n];
 
 int i;
 
 for(i=0;i<n;i++)
 {
   getchar();

   printf("Enter Name \n");
   fgets(a[i].name,30,stdin);

   int len = strlen(a[i].name);

   if (len > 0 && a[i].name[len - 1] == '\n') 
   {
    a[i].name[len - 1] = '\0';
   }
     
   printf("Enter Roll Number \n");
   scanf("%d",&a[i].rn);
     
   printf("Enter Marks \n");
   scanf("%f",&a[i].marks);

 }
 
 for(i=0;i<n;i++)
 {
   printf("\nStudent Name = %s , Roll Number = %d , Marks = %f \n",a[i].name,a[i].rn,a[i].marks);
 }
 
 return 0;
 
} 