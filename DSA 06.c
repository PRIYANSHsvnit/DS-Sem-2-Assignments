#include<stdio.h>
struct bank
{
    int accnum;
    char name[30];
    float balance;
    char type[10];
};
int main()
{
    int n;
    printf("Numeber of Customers = \n");
    scanf("%d",&n);

    struct bank a[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter Name of Customer %d = \n",(i+1));
        scanf("%s",a[i].name);

        printf("Enter Acc. Number of Customer %d = \n",(i+1));
        scanf("%d",&a[i].accnum);

        printf("Enter Acc. Bank Balance of Customer %d = \n",(i+1));
        scanf("%f",&a[i].balance);

        printf("Enter Acc. type of Customer %d = \n",(i+1));
        scanf("%s",a[i].type);
    }

    int j;
    float l;

    user:

    printf("\nEnter the Customer Number = \n");
    scanf("%d",&j);

    int o;

    wapas:

    printf("Choose Option \n\n1.WITHDRAWL\n2.DEPOSIT\n3.SHOW\n4.SWITCH USER\n5.EXIT \n = \n\n");
    scanf("%d",&o);

    switch(o)
    {
        case 1 : 
        
        printf("Enter Amount = \n");
        scanf("%f",&l);

        if(l<a[j-1].balance)
        {
            a[j-1].balance = a[j-1].balance - l;
            printf("Current Acc. Bank Balance = %f\n",a[j-1].balance);
        }

        else
        {
            printf("Insufficient Balance\n");
        }
        goto wapas;
        break;

        case 2 : 
       
        printf("Enter Amount = \n");
        scanf("%f",&l);

        a[j-1].balance = a[j-1].balance + l;
        printf("Current Acc. Bank Balance = %f\n",a[j-1].balance);
        goto wapas;
        break;

        case 3 : 
        printf("Current Acc. Bank Balance = %f\n",a[j-1].balance);
        printf("Current Acc.Type = %s\n",a[j-1].type);

        goto wapas;
        break;

        case 4 :
        goto user;
        break;

        case 5 :
        break;

    }

}