#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
void addingatend(void);
int length(void);
void display(void);
void delete1();
void addafter(void);
void addatstart(void);
void edit_items();
void inputNodeData();
void studentsinputdata();
void students_node_data();
void printstudenteData();
int searchbydata();
int searchbyname();
int searchbysurname();
int searchbyrno();
int saveListToFile(FILE * fptr);
int loadListFromFile();
// void delete(void);
struct student
{
   char first_name[20];
   char surname[20];
   char intake_year[4];
   char session[10];
   char program[10];
   int roll_no;
};

struct node
{
    struct student  data;
    struct node * link;
};
struct node *root =NULL;
int len=0;
int main()
{
    struct node *root1 =NULL;
    printf("\n what do you want to do \n");
    while (1)
    {
         int choose;
        printf("\n enter 1 for adding a node at the end");
        printf("\n enter 2 for length of a list");
        printf("\n enter 3 for displaying the list");
        printf("\n enter 4 for deleting a node from start,middle and beginning ");
        printf("\n enter 5 adding after a node");
        printf("\n enter 6 adding at start");
        printf("\n enter 7 editing items in database");
        printf("\n enter 8 Search the database for a certain item ");
        printf("\n enter 9 Save Data to Database ");
        printf("\n enter 10 Load Data to Database ");
        printf("\n enter 11 Exit ");
        printf("\n Enter your choice \n");
        scanf("%d",&choose);


        switch(choose)
        {
            case 1: addingatend();
            break;

            case 2: length();
            len = length();
            printf("\n The no. of nodes are %d \n",len);
            break;

            case 3: display();
            break;

            case 4: delete1();
            break;

            case 5: addafter();
            break;

            case 6: addatstart();
            break;

            case 7: edit_items();
            break;

            case 8:
            printf("\n Enter from 1 to 3 to enter information about student  \n");
            printf("\n first name  \n");
            printf("\n surname  \n");
            printf("\n  roll no  \n");
            int field_choice=0;
            scanf("%d",&field_choice);
             int idx=0;
             idx = searchbydata(field_choice);

            break;

            case 9:  /// Save list to file
                {
                FILE * fptr = NULL;
                if((fptr=fopen("StudentData.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(fptr);
                }
                break;

            case 10:
                {
                FILE * fptr = NULL;
                if((fptr=fopen("StudentData.dat", "rb")) == NULL)
                {
                    printf("\nCannot open file for loading Data!!\n\n");
                    exit(1);
                }
                loadListFromFile(fptr);
                fclose(fptr);
                }

            case 11:
                exit(0);
            return 0;


        }
    }

    }
  void addingatend()
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        inputNodeData(temp);
        temp->link = NULL;
        if(root == NULL)
        {
            root = temp;

            }
            else
            {
                struct node *p;
                  p=root;
            while( p->link != NULL)
            {
                p = p->link;
            }
            p->link=temp;

            }

    }

    int length()
    {
        int count =0;
        struct node *temp;
        temp = root;
        while (temp != NULL)
        {
          count++;
          temp=temp->link;

        }
        return count;
    }
void display()
    {
        struct node * temp ;
        temp =root;
        if (temp==NULL)
        {
            printf("\n list is empty \n");
        }
        else
        {
            while(temp !=NULL)
            {
                students_node_data(&temp->data);
                temp=temp->link;

            }
            printf("\n\n");
        }
    }

void delete1()
{
    struct node * temp;
    int loc;
    printf("\n Enter location to delete ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\n Not possible ");

    }
    if ( loc ==1)
    {
        temp= root;
        root = temp->link;
        free(temp);
    }
    else
    {
        struct node *p=root,*q;
        int i=1;
    while(i<(loc-1))
    {
        p = p->link;
        i++;
    }
    q=p->link;
    p->link=q->link;
    q->link = NULL;
    free(q);


    }

}


void addafter()
{
    int loc;
    struct node *temp,*p;
    printf("\n enter the location from where you want to enter a node ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\n Error");
    }
    else
    {
        int i=1;
        p = root;
        while (i<loc)
        {
            p=p->link;
            i++;
        }
        temp =(struct node*)malloc(sizeof(struct node));

       inputNodeData(temp);
        temp->link=NULL;
        temp->link= p->link;
        p->link=temp;

    }
}

void addatstart()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    inputNodeData(temp);
    temp->link=NULL;
    if(root == NULL)
        {
            root = temp;

        }
        else
        {
            temp->link=root;
            root=temp;
        }

}
void students_node_data(struct node * d)
{
    printstudenteData( &d ->data);
}

void printstudenteData(struct student * stds)
{
    printf("\nfirst name:\t %s\n", stds->first_name);
    printf(" surname:\t %s\n", stds->surname);
    printf(" intake year:\t %s\n", stds->intake_year);
    printf(" session:\t %s\n", stds->session);
    printf(" program:\t %s\n", stds->program);
    printf(" roll.no:\t %d\n", stds->roll_no);
}
void inputNodeData(struct node * d)
{
   studentsinputdata(& d->data);
}
void studentsinputdata(struct student *stds)
{
    printf("\nEnter the first name of the student: ");
   scanf("%s", &(stds->first_name));

    printf("\nEnter the surname of the student: ");
    scanf("%s", &(stds-> surname));

    printf("\nEnter the intake year of the student: ");
   scanf("%s", &(stds->intake_year));

    printf("\nEnter the session of the student: ");
    scanf("%s", &(stds->session));

    printf("\nEnter the program of the student: ");
   scanf("%s", &(stds->program));

    printf("\nEnter the roll.no of the student: ");
    scanf("%d", &(stds->roll_no));




    printf("\nRecord entered !\n");
}

void edit_items()
{
    int loc;
    printf("\n Enter location to edit ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\n Not possible ");

    }
    else{

    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));

    inputNodeData(temp);


        struct node *p=root,*q;
        int i=1;
    while(i<(loc-1))
    {
        p = p->link;
        i++;
    }
    q=p->link;
    p->link=temp;
    temp->link=q->link;
    q=temp;
    }

}

int searchbydata(int field_num)
{   int idx = -1;
    switch(field_num)
    {
        case 1:
            printf("\nEnter a first name to search: ");
            char searchName[50];
            scanf("%s",&searchName);
            idx = searchbyname(searchName);

            if(idx == -1)
                printf("\nName searched for is not found!!\n\n");
            else
                printf("\nThe name exists at index %d\n", idx,"\n");

            return (idx);
        break;
        case 2:
            printf("\nEnter a surname to search: ");
            char searchsurName[50];
            scanf("%s",&searchsurName);
            idx = searchbyname(searchsurName);

            if(idx == -1)
                printf("\nName searched for is not found!!\n\n");
            else
                printf("\nThe name exists at index %d \n", idx,"\n");

            return (idx);
        break;
        case 3:
            printf("\nEnter a roll number to search: ");
            int searchrno=0;
            scanf("%d",&searchrno);
            idx = searchbyrno(searchrno);

            if(idx == -1)
                printf("\nName searched for is not found!!\n\n");
            else
                printf("\nThe name exists at index %d \n", idx,"\n");

            return (idx);
        break;
        default:
            return (0);
    }
}

int searchbyname(char *name)
{
    struct node * temp = root;
    int index = 0;

    while((strcmp(temp->data.first_name,name) != 0) && ((temp->link) != NULL))
    {
        temp = temp->link;

        index ++;
    }
    if((temp->link == NULL) && (strcmp(temp->data.first_name,name) != 0))
        return(-1);

    return (index); /// name found at index
}
int searchbysurname(char *name)
{
    struct node * temp = root;
    int index = 0;

    while((strcmp(temp->data.surname,name) != 0) && ((temp->link) != NULL))
    {
        temp = temp->link;

        index ++;
    }
    if((temp->link == NULL) && (strcmp(temp->data.surname,name) != 0))
        return(-1);

    return (index);
}
int searchbyrno(int name)
{
    struct node * temp = root;
    int index = 0;

    while((temp->data.roll_no!= name) && (temp->link != NULL))
    {
        temp = temp->link;

        index ++;
    }
    if((temp->link == NULL) && (temp->data.roll_no!= name))
        return(-1);

    return (index); /// name found at index
}
int saveListToFile(FILE * fptr)
{
    struct node * temp = root;
    if(root == NULL)
        return(-1);

    while(temp != NULL)
    {
        fwrite(&(temp->data), sizeof(struct student), 1,  fptr);
        temp = temp->link;
    }
     printf("\n  Saving into database is done  \n");
    return(0);
}
int loadListFromFile( FILE * fptr)
{
    struct student  new_record;

    struct node * temp = root;

    while(fread(& new_record, sizeof(struct student), 1, fptr) )  /// read data from the file.
    {

        struct node * new_node = (struct node *) malloc(sizeof(struct node));

        new_node->data = new_record;


        if(root == NULL)
        {
            root = new_node;
            new_node->link = NULL;

            temp = root;
        }
        else
        {
            temp->link = new_node;
            new_node->link = NULL;
            temp = temp->link;
        }

    }
     printf("\n Loading from database is done  \n");
    main();
}



