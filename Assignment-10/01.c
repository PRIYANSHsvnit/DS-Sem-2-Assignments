#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data
{
    char name[100];
    int rn;
    char dept[100];
}student;

void bubblesort(student students[], int scount) 
{
    for (int i = 0; i < scount - 1; i++) 
    {
        for (int j = 0; j < scount - i - 1; j++) 
        {
            if (strcmp(students[j].name, students[j + 1].name) > 0 || (strcmp(students[j].name, students[j + 1].name) == 0 && students[j].rn > students[j + 1].rn)) 
            {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void binarysearch(student students[], int scount, char *searchs) 
{
    int low = 0, high = scount - 1;
    int found = 0;
    
    while (low <= high) 
    {
        int mid = (low + high)/2 ;
        
        if (strcmp(students[mid].name, searchs) == 0) 
        {
            int i = mid;

            while (i >= 0 && strcmp(students[i].name, searchs) == 0) 
            {
                printf("Name = %s , RollNumber = %d , Department = %s \n", students[i].name, students[i].rn, students[i].dept);
                i--;
            }
            
            i = mid + 1;

            while (i < scount && strcmp(students[i].name, searchs) == 0) 
            {
                printf("Name = %s , RollNumber = %d , Department = %s \n", students[i].name, students[i].rn, students[i].dept);
                i++;
            }
            
            found = 1;
            break;
        }

        else if (strcmp(students[mid].name, searchs) < 0) 
        {
            low = mid + 1;
        } 

        else 
        {
            high = mid - 1;
        }
    }
    
    if (!found) 
    {
        printf("No records found for the student name = %s\n", searchs);
    }
}

int main()
{
    student students[100];
    int scount = 0;

    FILE *file = fopen("C:/Users/Shree/Downloads/Text.txt","r");

    while (fscanf(file, " %99[^,], %d, %99[^\n]", students[scount].name, &students[scount].rn, students[scount].dept) != EOF) 
    {
        scount ++;
    }

    fclose(file);

    int choice;

    wapas:

    printf("Enter Choice... \n");
    printf("\nPress 1 for Bubble Sort\n");
    printf("Press 2 for Binary Search\n");
    printf("Press 3 for Quit\n\n");

    scanf("%d",&choice);
    getchar();

    switch(choice)
    {
        case 1 : 
        bubblesort(students,scount);
        printf("Sorted Students on basis of their name and roll number...\n");
        for(int i=0;i<scount;i++)
        {
            printf("Name = %s , RollNumber = %d , Department = %s\n",students[i].name,students[i].rn,students[i].dept);
        }

        goto wapas;
        break;

        case 2 :
        printf("Enter the student name to search in record book = \n");
        char searchs[100];
        fgets(searchs,100,stdin);
        searchs[strcspn(searchs, "\n")] = 0;

        bubblesort(students,scount);
        binarysearch(students,scount,searchs);

        goto wapas;
        break;

        case 3 :
        printf("Exitting the program ... \n");
        break;

        default :
        printf("Invalid Statement !!!\n");
        break;
    }
}