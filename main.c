
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SPACE 5
int i,n;
struct student
{
    int dsmarks,dcmarks,pommarks,gtcmarks,mpbsmarks,total;
    char rollno[20],name[100][20],PRN[50];
    float percentage;
    struct student *next;
    struct student *left;
    struct student *right;
}*head=NULL;
//validation functions
char isROLLNOunique(struct student*head, char rollno);
void login();
//tree structure
struct student* totalTreeID();
struct student* sortedArrToBst(int*,int,int);
struct student* getNewTreeNode(int);
void sortArray(int*,int);
void draw_tree_hor2(struct student *tree,int depth,int *path,int right);
void draw_tree(struct student *tree);
void printtotalTree(struct student*);
void display();
//main functions
struct student *create(struct student *head);
void display (struct student *head);
struct student *sort (struct student *head);
void *search(struct student *head,char NAME[]);
struct student *insert(struct student *head);
struct student *del(struct student *head,char NAME[]);
struct student *modify(struct student *head,char NAME[]);
struct student *reverse(struct student *head);
//display functions
void headDisplay();
void mainDisplay();
void createDisplay();
void displayDislpay();
void info();
int n, j ;
int a[20] ;
char password[30]="ADMIN@123";
char pass[30];
char name[50];
int i,n;
char e;
void main ()
{
    char NAME[50];
    int ch ;
    struct student *head=NULL;
    headDisplay();
    login();
    while(1)
    {
        mainDisplay();
        printf("\t\t\t\t\t\t");
        scanf ("\t\t\t\t\t\t%d",&ch ) ;
        switch (ch)
        {
        case 1:
            system("COLOR F1") ;
            head =create(head);
            break;
        case 2 :
            system("COLOR F5") ;
            display(head);
            break;
        case 3 :
            system("COLOR F4") ;
            sort(head);
            display(head) ;
            break;
        case 4 :
            system("COLOR F3") ;
            headDisplay();
            printf("\t\t\t\t\tENTER NAME OF STUDENT TO SEARCH : ");
            scanf("%s",NAME);
            search (head,NAME) ;
            break ;
        case 5 :
            system("COLOR F2") ;
            head=insert(head);
            break;
        case 6 :
            system("COLOR F1") ;
            headDisplay();
            printf("\t\t\t\t\t\tENTER NAME OF STUDENT WHOSE RECORD SHOULD BE DELEATED : ");
            scanf("%s",NAME);
            head=del(head,NAME);
            break;
        case 7:
            system("COLOR FA") ;
            headDisplay();
            printf("\t\t\t\t\t\tENTER NAME OF STUDENT WHOSE RECORD SHOULD BE MODIFIED : ");
            scanf("%s",NAME);
            head=modify(head,NAME);
            break;
        case 8:
            system("COLOR FD") ;
            headDisplay();
            printf("\t\t\t\t\t\tSTUDENT RECORD IN REVERSE ORDER : \n");
            display(head);
            head=reverse(head);
            break;
        case 9:
            system("COLOR F2") ;
            printtotalTree(head);
            break;
        case 10:
            exit(0);
            break;
        default :
            printf("\t\t\t\t\t\tWRONG CHOICE!!");
            break;
        }
    }
}
struct student *create(struct student* head)
{
    int i,ch;
    struct student *p, *temp;
    headDisplay();
    createDisplay();
    scanf("\t\t\t\t\t\t%d",&ch);
    switch(ch)
    {
    case 1:
        system("COLOR F1") ;
        printf ("\t\t\t\t\t\tENTER HOW MANY RECORDS TO ENTER : ");
        scanf ("%d",&n) ;
        temp = head;
        for (i=0 ; i<n ; i++)
        {
            temp = (struct student*)malloc(sizeof(struct student));
            printf("\t\t\t___________________________________________________________________________\n");
            int error = 0;
         do{
              if(error)
                  printf("\tROLL NO ALREADY PRESENT ENTER ANOTHER ROLL NO!\n");
                  system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER STUDENT ROLL NO: ");
            scanf(" \t\t%s",&(temp->rollno));
                  error=1;
         }while(!isROLLNOunique(head,temp->rollno));


           while(1)
            {
                printf("\n\t\t\t\t\t\tENTER REGISTRATION NO : ") ;
                scanf ("%s",temp->PRN) ;
                if(strlen(temp->PRN)==15)
                    break;
                system("COLOR F4") ;
                printf("\t\t\t\t\t\tINVALID PRN NUMBER!!");
            }
            system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER NAME : ");
            scanf("%s",temp->name);

            printf("\n\t\t\t\t\t\tENTER DS MARKS : ");
            scanf("%d",&(temp->dsmarks));
            while((temp->dsmarks)>100)
            {
                system("COLOR F4") ;
                printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                scanf ("%d",&(temp->dsmarks)) ;
            }
            system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER DC MARKS : ");
            scanf("%d",&(temp->dcmarks));
            while((temp->dcmarks)>100)
            {
                system("COLOR F4") ;
                printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                scanf ("%d",&(temp->dcmarks)) ;
            }
            system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER POM MARKS : ");
            scanf("%d",&(temp->pommarks));
            while((temp->pommarks)>100)
            {
                system("COLOR F4") ;
                printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                scanf ("%d",&(temp->pommarks)) ;
            }
            system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER GTC MARKS : ");
            scanf("%d",&(temp->gtcmarks));
            while((temp->gtcmarks)>100)
            {
                system("COLOR F4") ;
                printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                scanf ("%d",&(temp->gtcmarks)) ;
            }
            system("COLOR F1") ;
            printf("\n\t\t\t\t\t\tENTER MPBS MARKS : ");
            scanf("%d",&(temp->mpbsmarks));
            while((temp->mpbsmarks)>100)
            {
                system("COLOR F4") ;
                printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                scanf ("%d",&(temp->mpbsmarks)) ;
            }
            if(head == NULL)
            {
                head = temp;
                temp->next = NULL;
            }
            else
            {
                p=head;
                while(p->next!=NULL)
                    p=p->next;
                p->next=temp;
                temp->next=NULL;
            }
        }
        return head;
        break;
    case 2:
        main();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("\t\t\t\t\tWRONG CHOICE");
        break;
    }
}
void display(struct student *head)
{
    int space;
    headDisplay();
    if(head == NULL)
        printf("\n\t\t\t\t\t\t NO DATA AVAILABLE !!!\n");
    printf("\n\t\t\t\t\t\tRoll no\t   \t PRN \t\tName\tDS\tDC\tPOM\tGTC\tMPBS\tTotal\tPercentage\n");
    printf("\n\t\t\t\t\t\t----------------------------------------------------------------------------------------\n");
    struct student *p=head;
    p = head;
    while(p!=NULL)
    {
        p->total=(p->dsmarks + p->dcmarks + p->pommarks + p->gtcmarks + p->mpbsmarks);
        p->percentage=(p->total)*100/500;
        printf("\n\t\t\t\t\t\t %s ",p->rollno);
        printf("\t%s",p->PRN);
        printf("\t%s",p->name);
        printf("\t%d",p->dsmarks);
        printf("\t%d",p->dcmarks);
        printf("\t%d",p->pommarks);
        printf("\t%d",p->gtcmarks);
        printf("\t%d",p->mpbsmarks);
        printf("\t%d",p->total);
        printf("\t%.2f\n",p->percentage);
        p=p->next;
    }
    printf("\n");
}
struct student *sort(struct student *head)
{
    struct student *p, *q, *temp;
    temp=(struct student*)malloc(sizeof(struct student)*6);
    for(p=head; p->next!=NULL; p=p->next)
    {
        p->total=(p->dsmarks + p->dcmarks + p->pommarks + p->gtcmarks + p->mpbsmarks);
        p->percentage=(p->total)*100/500;
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(p->total < q->total)
            {
                strcpy(temp->rollno,p->rollno);
                strcpy(p->rollno,q->rollno);
                strcpy(q->rollno,temp->rollno);
                strcpy(temp->PRN,p->PRN);
                strcpy(p->PRN,q->PRN);
                strcpy(q->PRN,temp->PRN);
                strcpy(temp->name,p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,temp->name);
                temp->dsmarks=p->dsmarks;
                p->dsmarks=q->dsmarks;
                q->dsmarks=temp->dsmarks;
                temp->dcmarks=p->dcmarks;
                p->dcmarks=q->dcmarks;
                q->dcmarks=temp->dcmarks;
                temp->pommarks=p->pommarks;
                p->pommarks=q->pommarks;
                q->pommarks=temp->pommarks;
                temp->gtcmarks=p->gtcmarks;
                p->gtcmarks=q->gtcmarks;
                q->gtcmarks=temp->gtcmarks;
                temp->mpbsmarks=p->mpbsmarks;
                p->mpbsmarks=q->mpbsmarks;
                q->mpbsmarks=temp->mpbsmarks;
                temp->total=p->total;
                p->total=q->total;
                q->total=temp->total;
                temp->percentage=p->percentage;
                p->percentage=q->percentage;
                q->percentage=temp->percentage;
            }
        }
    }
}

void *search(struct student *head,char NAME[])
{
    int space1,space2;
    struct student *p;
    int flag=0;
    if(strcmp(head->name,NAME)==0)
    {
        printf("\t\t\t\t\t\t\tRECORD FOUND\n\n");
        printf("\t\t\t\tRoll no\t   \t PRN \t\tName\tDS\tDC\tPOM\tGTC\tMPBS\tTotal\tPercentage\n");
        printf("\t\t\t\t------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t");
        head->total=(head->dsmarks + head->dcmarks + head->pommarks + head->gtcmarks + head->mpbsmarks);
        head->percentage=(head->total)*100/500;
        printf("%s\t    ",head->rollno);
        space1=10-strlen(head->PRN);
        printf("%s",head->PRN);
        while(space1>0)
        {
            printf(" ");
            space1--;
        }
        printf("\t%s",head->name);
        printf("\t%d",head->dsmarks);
        printf("\t%d",head->dcmarks);
        printf("\t%d",head->pommarks);
        printf("\t%d",head->gtcmarks);
        printf("\t%d",head->mpbsmarks);
        printf("\t%d",head->total);
        printf("\t%.2f\n",head->percentage);
        printf("\n");
        flag++;
    }
    p=head;
    while(p->next!=NULL)
    {
        if(strcmp(p->next->name,NAME)==0)
        {
            printf("\n\t\t\t\t\t\tRECORD FOUND!!\n");
            printf("\t\t\t\tRoll no\t   \t PRN \t\tName\tDS\tDC\tPOM\tGTC\tMPBS\tTotal\tPercentage\n");
            printf("\t\t\t\t------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t");
            head->total=(head->dsmarks + head->dcmarks + head->pommarks + head->gtcmarks + head->mpbsmarks);
            head->percentage=(head->total)*100/500;
            printf(" %s\t    ",p->next->rollno);
            space2=10-strlen(p->next->PRN);
            printf("%s",p->next->PRN);
            while(space2>0)
            {
                printf(" ");
                space2--;
            }
            printf("\t%s",p->next->name);
            printf("\t%d",p->next->dsmarks);
            printf("\t%d",p->next->dcmarks);
            printf("\t%d",p->next->pommarks);
            printf("\t%d",p->next->gtcmarks);
            printf("\t%d",p->next->mpbsmarks);
            printf("\t%d",p->next->total);
            printf("\t%.2f\n",p->next->percentage);
            printf("\n");
        }
        p=p->next;
        flag++;
    }
    if(flag==0)
        printf("\n\t\t\t\t\t\tRECORD DOES NOT EXIST!!!\n\n");

}
struct student *insert(struct student *head)
{
    int i,pos;
    struct student *p,*temp;
    temp=(struct student*)malloc(sizeof(struct student)*1);
    headDisplay();
    printf("\n\t\t\t\t\tENTER POSITION WHERE RECORD SHOULD BE ADDED : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER ROLL NO: ");
        scanf("%s",temp->rollno);
        while(1)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tENTER REGISTRATION NO : ") ;
            scanf ("%s",temp->PRN) ;
            if(strlen(temp->PRN)==15)
                break;
            printf("\t\t\t\t\t\tINVALID PRN NUMBER!!");
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER NAME: ");
        scanf("%s",(temp->name));
        printf("\n\t\t\t\t\t\tENTER DS MARKS : ");
        scanf("%d",&(temp->dsmarks));
        while((temp->dsmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->dsmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER DC MARKS : ");
        scanf("%d",&(temp->dcmarks));
        while((temp->dcmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->dcmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER POM MARKS : ");
        scanf("%d",&(temp->pommarks));
        while((temp->pommarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->pommarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER GTC MARKS : ");
        scanf("%d",&(temp->gtcmarks));
        while((temp->gtcmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->gtcmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER MPBS MARKS : ");
        scanf("%d",&(temp->mpbsmarks));
        while((temp->mpbsmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->mpbsmarks)) ;
        }
        printf("\n\t\t\t\t\t\t");
        temp->next=head;
        head=temp;
        return head;
    }
    p=head;
    for(i=1; i<pos-1 && p!=NULL; i++)
        p=p->next;
    if(p==NULL)
        printf("\n\t\t\t\t\t\t*NO RECORD EXIST*\n\n");
    else
    {
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER ROLL NO: ");
        scanf("%s",temp->rollno);

        while(1)
        {
            printf("\n\t\t\t\t\t\tENTER REGISTRATION NO : ") ;
            scanf ("%s",temp->PRN) ;
            if(strlen(temp->PRN)==10)
                break;
            system("COLOR F4") ;
            printf("\t\t\t\t\t\tINVALID PRN NUMBER!!");
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER NAME: ");
        scanf("%s",(temp->name));
        printf("\n\t\t\t\t\t\tENTER DS MARKS : ");
        scanf("%d",&(temp->dsmarks));
        while((temp->dsmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->dsmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER DC MARKS : ");
        scanf("%d",&(temp->dcmarks));
        while((temp->dcmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->dcmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER POM MARKS : ");
        scanf("%d",&(temp->pommarks));
        while((temp->pommarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->pommarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER GTC MARKS : ");
        scanf("%d",&(temp->gtcmarks));
        while((temp->gtcmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->gtcmarks)) ;
        }
        system("COLOR F2") ;
        printf("\n\t\t\t\t\t\tENTER MPBS MARKS : ");
        scanf("%d",&(temp->mpbsmarks));
        while((temp->mpbsmarks)>100)
        {
            system("COLOR F4") ;
            printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
            printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
            scanf ("%d",&(temp->mpbsmarks)) ;
        }
        printf("\n");
        temp->next=p->next;
        p->next=temp;
    }
    return head;
}
struct student *del(struct  student *head,char NAME[])
{
    struct student *temp,*p;

    if(strcmp(head->name,NAME)==0)
    {
        temp=head;
        head=temp->next;
        free(temp);
        printf("\n\t\t\t\t\tDATA SUCCESSFULLY DELETED\n");
        return head;
    }
    p=head;
    while(p->next!=NULL)
    {
        if(strcmp(p->next->name,NAME)==0)
        {
            temp=p->next;
            p->next=temp->next;
            free(temp);
            system("COLOR F4") ;
            printf("\n\t\t\t\t\tDATA SUCCESSFULLY DELETED\n");
            return head;
        }
        p=p->next;
    }
}
struct student *reverse(struct student *head)
{
    struct student *rev = NULL;
    struct student *temp = head;
    struct student *temp1;

    while(temp!=NULL)
    {
        if (rev == NULL)
        {
            rev = temp;
            temp = temp->next;
            rev->next = NULL;
            continue;
        }
        temp1 = temp;
        temp = temp->next;
        temp1->next = rev;
        rev = temp1;
    }
    return rev;
}
struct student *modify(struct student *head,char NAME[])
{
    struct student *p;
    int choice,space3,space4;
    char ans1,ans2;
    int flag=0,chs=0;
    int FLAG = 0;
    int FLAG1 = 0;
    if(strcmp(head->name,NAME)==0)
    {
        printf("\t\t\t\t\t\t\tRECORD FOUND\n\n");
        printf("\t\t\t\t\t\tRoll no\t   \t PRN \t\tName\tDS\tDC\tPOM\tGTC\tMPBS\tTotal\tPercentage\n");
        printf("\t\t\t\t\t\t----------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t");
        head->total=(head->dsmarks + head->dcmarks + head->pommarks + head->gtcmarks + head->mpbsmarks);
        head->percentage=(head->total)*100/500;
        printf(" %s\t    ",head->rollno);
        space3=10-strlen(head->PRN);
        printf("%s",head->PRN);
        while(space3>0)
        {
            printf(" ");
            space3--;
        }
        printf("\t%s",head->name);
        printf("\t%d",head->dsmarks);
        printf("\t%d",head->dcmarks);
        printf("\t%d",head->pommarks);
        printf("\t%d",head->gtcmarks);
        printf("\t%d",head->mpbsmarks);
        printf("\t%d",head->total);
        printf("\t%.2f\n",head->percentage);
        printf("\n");
        do
        {
            printf("\n\t\t\t\t\t\t1.MODIFY ROLL NO");
            printf("\n\t\t\t\t\t\t2.MODIFY REGISTRATION NO");
            printf("\n\t\t\t\t\t\t3.MODIFY NAME");
            printf("\n\t\t\t\t\t\t4.MODIFY DS MARKS");
            printf("\n\t\t\t\t\t\t5.MODIFY DC MARKS");
            printf("\n\t\t\t\t\t\t6.MODIFY POM MARKS");
            printf("\n\t\t\t\t\t\t7.MODIFY GTC MARKS");
            printf("\n\t\t\t\t\t\t8.MODIFY MPBS MARKS\n");
            printf("\t\t\t\t\t\t");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                system("COLOR FA") ;
                printf("\n\t\t\t\t\t\tENTER ROLL NO: ");
                scanf("%s",head->rollno);
                break;
            case 2:
                while(1)
                {
                    system("COLOR FA") ;
                    printf("\n\t\t\t\t\t\tENTER REGISTRATION NO : ") ;
                    scanf ("%s",head->PRN) ;
                    if(strlen(head->PRN)==15)
                        break;
                    system("COLOR F4") ;
                    printf("\t\t\t\t\t\tINVALID PRN NUMBER!!");
                }
                break;
            case 3:
                system("COLOR FA") ;
                printf("\t\t\t\t\t\ENTER NEW NAME :\n");
                scanf("%s",(head->name));
                break;
            case 4:
                system("COLOR FA") ;
                printf("\n\t\t\t\t\t\tENTER NEW DS MARKS : ");
                scanf("%d",&(head->dsmarks));
                while((head->dsmarks)>100)
                {
                    system("COLOR F4") ;
                    printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                    printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                    scanf ("%d",&(head->dsmarks)) ;
                }
                break;
            case 5:
                system("COLOR FA") ;
                printf("\n\t\t\t\t\t\tENTER NEW DC MARKS : ");
                scanf("%d",&(head->dcmarks));
                while((head->dcmarks)>100)
                {
                    system("COLOR F4") ;
                    printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                    printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                    scanf ("%d",&(head->dcmarks)) ;
                }
                break;
            case 6:
                system("COLOR FA") ;
                printf("\t\t\t\t\t\tENTER NEW POM MARKS : \n");
                scanf("%d",&(head->pommarks));
                while((head->pommarks)>100)
                {
                    system("COLOR F4") ;
                    printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                    printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                    scanf ("%d",&(head->pommarks)) ;
                }
                break;
            case 7:
                system("COLOR FA") ;
                printf("\t\t\t\t\t\tENTER NEW GTC MARKS : \n");
                scanf("%d",&(head->gtcmarks));
                while((head->gtcmarks)>100)
                {
                    system("COLOR F4") ;
                    printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                    printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                    scanf ("%d",&(head->gtcmarks)) ;
                }
                break;
            case 8:
                system("COLOR FA") ;
                printf("\t\t\t\t\t\tENTER NEW MPBS MARKS : \n");
                scanf("%d",&(head->mpbsmarks));
                while((head->mpbsmarks)>100)
                {
                    system("COLOR F4") ;
                    printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                    printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                    scanf ("%d",&(head->mpbsmarks)) ;
                }
                break;
            default :
                printf("\t\t\t\t\t\tPlease enter correct choice to proceed \n");
                break;

            }
            printf("\t\t\t\t\t\tPRESS 1 TO CONTINUE MODIFY:");
            printf("\n\t\t\t\t ELSE PRESS 0 TO GO BACK: ");
            scanf("%d",&chs);
        }
        while(chs==1);

        flag++;
        return head;
    }
    p=head;
    while(p->next!=NULL)
    {
        if(strcmp(p->next->name,NAME)==0)
        {
            printf("\t\t\t\t\t\t\tRECORD FOUND\n\n");
            printf("\t\t\t\t\t\tRoll no\t   \t PRN \t\tName\tDS\tDC\tPOM\tGTC\tMPBS\tTotal\tPercentage\n");
            printf("\t\t\t\t\t\t----------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t");
            p->next->total=(p->next->dsmarks + p->next->dcmarks + p->next->pommarks + p->next->gtcmarks + p->next->mpbsmarks);
            p->next->percentage=(p->next->total)*100/500;
            printf(" %s\t    ",p->next->rollno);
            space3=10-strlen(p->next->PRN);
            printf("%s",p->next->PRN);
            while(space4>0)
            {

                printf(" ");
                space4--;
            }
            printf("\t%s",p->next->name);
            printf("\t%d",p->next->dsmarks);
            printf("\t%d",p->next->dcmarks);
            printf("\t%d",p->next->pommarks);
            printf("\t%d",p->next->gtcmarks);
            printf("\t%d",p->next->mpbsmarks);
            printf("\t%d",p->next->total);
            printf("\t%.2f\n",p->next->percentage);
            printf("\n");
            do
            {
                printf("\n\t\t\t\t\t\t1.MODIFY ROLL NO");
                printf("\n\t\t\t\t\t\t2.MODIFY REGISTRATION NO");
                printf("\n\t\t\t\t\t\t3.MODIFY NAME");
                printf("\n\t\t\t\t\t\t4.MODIFY DS MARKS");
                printf("\n\t\t\t\t\t\t5.MODIFY DC MARKS");
                printf("\n\t\t\t\t\t\t6.MODIFY POM MARKS");
                printf("\n\t\t\t\t\t\t7.MODIFY GTC MARKS");
                printf("\n\t\t\t\t\t\t8.MODIFY MPBS MARKS\n");
                scanf("\n\t\t\t\t%d",&choice);
                switch (choice)
                {
                case 1:

                    system("COLOR FA") ;
                    printf("\n\t\t\t\t\t\tENTER ROLL NO: ");
                    scanf("%s",p->next->rollno);
                    break;
                case 2:
                    while(1)
                    {
                        system("COLOR FA") ;
                        printf("\n\t\t\t\t\t\tENTER REGISTRATION NO : ") ;
                        scanf ("%s",p->next->PRN) ;
                        if(strlen(p->next->PRN)==15)
                            break;
                        system("COLOR F4") ;
                        printf("\t\t\t\t\t\tINVALID PRN NUMBER!!");
                    }
                    break;
                case 3:
                    system("COLOR FA") ;
                    printf("\t\t\t\t\t ENTER NEW NAME :\n");
                    scanf("%s",(p->next->name));
                    break;
                case 4:
                    system("COLOR FA") ;
                    printf("\n\t\t\t\t\t\tENTER NEW DS MARKS : ");
                    scanf("%d",&(p->next->dsmarks));
                    while((p->next->dsmarks)>100)
                    {
                        system("COLOR F4") ;
                        printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                        printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                        scanf ("%d",&(p->next->dsmarks)) ;
                    }
                    break;
                case 5:
                    system("COLOR FA") ;
                    printf("\n\t\t\t\t\t\tENTER NEW DC MARKS : ");
                    scanf("%d",&(p->next->dcmarks));
                    while((p->next->dcmarks)>100)
                    {
                        system("COLOR F4") ;
                        printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                        printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                        scanf ("%d",&(p->next->dcmarks)) ;
                    }
                    break;
                case 6:
                    system("COLOR FA") ;
                    printf("\t\t\t\t\t\tENTER NEW POM MARKS : \n");
                    scanf("%d",&(p->next->pommarks));
                    while((p->next->pommarks)>100)
                    {
                        system("COLOR F4") ;
                        printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                        printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                        scanf ("%d",&(p->next->pommarks)) ;
                    }
                    break;
                case 7:
                    system("COLOR FA") ;
                    printf("\t\t\t\t\t\tENTER NEW GTC MARKS : \n");
                    scanf("%d",&(p->next->gtcmarks));
                    while((p->next->gtcmarks)>100)
                    {
                        system("COLOR F4") ;
                        printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                        printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                        scanf ("%d",&(p->next->gtcmarks)) ;
                    }
                    break;
                case 8:
                    system("COLOR FA") ;
                    printf("\t\t\t\t\t\tENTER NEW MPBS MARKS : \n");
                    scanf("%d",&(p->next->mpbsmarks));
                    while((p->next->mpbsmarks)>100)
                    {
                        system("COLOR F4") ;
                        printf("\n\t\t\t\t\t\tINPUT MUST BE LESS THAN 100\n");
                        printf("\n\t\t\t\t\t\tPLEASE RE ENTER : ") ;
                        scanf ("%d",&(p->next->mpbsmarks)) ;
                    }
                    break;
                default :
                    printf("\t\t\t\t Please enter correct choice to proceed \n");
                    break;
                }
                printf("\t\t\t\t PRESS 1 TO CONTINUE MODIFICATION: ");
                printf("\n\t\t\t\t ELSE PRESS 0 TO GO BACK: ");
                scanf("%d",&chs);
            }
            while(chs==1);
        }
        p=p->next;
        flag++;
        return head;
    }
    if(flag==0)
        printf("\n\n\t\t\t\t\t\tNOT FOUND!!\n\n");
}
struct student* getTreeID(struct student *head,int n)
{
    int array[n];
    int point=0;
    struct student* temp=head;
    while(temp!=NULL)
    {
        array[point++]=temp->total;
        temp=temp->next;
    }
    sortArray(array,n);
    return sortedArrToBst(array, 0, n-1);
}
struct student* sortedArrToBst(int A[], int head, int end)
{
    if(head > end)
        return NULL;
    int mid = (head+end)/2;
    struct student* root = getNewTreeNode(A[mid]);
    root->left = sortedArrToBst(A, head, mid-1);
    root->right = sortedArrToBst(A, mid+1, end);
    return root;
}
struct student*  getNewTreeNode (int x)
{
    struct student*  temp = (struct student*)malloc(sizeof(struct student));
    temp->total = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void sortArray(int A[], int n)
{
    int flag = 0;
    int temp;
    int i,j;

    for ( i = 0; i < n; ++i)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; ++j)
        {
            if (A[j] > A[j+1])
            {
                flag = 1;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        if (!flag)
            break;
    }
}
void draw_tree_hor2(struct student *tree, int depth, int *path, int right)
{
    int i,j;
    if (tree == NULL)
        return;
    depth++;

    draw_tree_hor2(tree->right, depth, path, 1);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(tree->left)
        path[depth-1] = 1;

    printf("\n");

    for(i=0; i<depth-1; i++)
    {
        if(i == depth-2)
            printf("+");
        else if(path[i])
            printf("|");
        else
            printf(" ");

        for(j=1; j<SPACE; j++)
            if(i < depth-2)
                printf(" ");
            else
                printf("-");
    }

    printf("%d\n", tree->total);
    for(i=0; i<depth; i++)
    {
        if(path[i])
            printf("|");
        else
            printf(" ");

        for( j=1; j<SPACE; j++)
            printf(" ");
    }
    draw_tree_hor2(tree->left, depth, path, 0);
}
void draw_tree(struct student *tree)
{
    char path[255] = {};
    draw_tree_hor2(tree, 0, path, 0);
}
void printtotalTree(struct student* head)
{
    headDisplay();
    printf("\n\n\t\t\tTREE ACCORDING TOTAL MARKS\n");
    printf("\n\n\n");
    struct student *root=getTreeID(head,n);
    if(root)
    {
        draw_tree(root);
        printf("\n\n\n");
    }
    else
    {
        printf("\t\t\t\t\t\tNO DATA AVAILABLE\n");
    }
}
char isROLLNOunique(struct student* head, char rollno)
{
    struct student* temp = head;
    while(temp!=NULL)
    {
        if(temp->rollno == rollno)
            return 0;
        temp = temp->next;
    }
    return 1;
}
void login()
{
    system("COLOR F1") ;
    printf("\n\t\t\t\t\t\tENTER PASSWARD:");
    i=0;
    while(e!=13)
    {
        e=getch();
        pass[i]=e;
        i++;
        printf("*");
    }
    pass[i-1]='\0';
    if(strcmp(password,pass)==0)
    {
        headDisplay();
        printf("\n\t\t\t\t\t\tWELCOME TO GHRCEM STUDENT REPORT CARD MANAGEMENT SYSTEM");
    }
    else
    {
        system("COLOR F4") ;
        printf("\n\n\t\t\t\t\t\tYOU ENTERED WRONG PASSWARD");
        exit (0);
    }
}
void headDisplay()
{
    system("cls");
    printf ("\n\n\n");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t\t\t\t$$$$                                                     $$$$\n");
    printf("\t\t\t\t\t\t$$$$         STUDENT REPORT CARD MANAGEMENT SYSTEM       $$$$\n");
    printf("\t\t\t\t\t\t$$$$                                                     $$$$\n");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
}
void mainDisplay()
{
    printf("\n\t\t\t\t_________________________________________________________________________________________________\n");
    printf("\t\t\t\t.................................................................................................\n\n");
    printf("\t\t\t\t\t\t\t\t \t1.CREATE\n");
    printf("\t\t\t\t\t\t\t\t \t2.DISPLAY\n");
    printf("\t\t\t\t\t\t\t\t \t3.SORT\n");
    printf("\t\t\t\t\t\t\t\t \t4.SEARCH\n");
    printf("\t\t\t\t\t\t\t\t \t5.INSERT\n");
    printf("\t\t\t\t\t\t\t\t \t6.DELETE\n");
    printf("\t\t\t\t\t\t\t\t \t7.MODIFY\n");
    printf("\t\t\t\t\t\t\t\t \t8.REVERSE\n");
    printf("\t\t\t\t\t\t\t\t \t9.PRINT TOTAL TREE\n");
    printf("\t\t\t\t\t\t\t\t\t10.EXIT\n");
}
void createDisplay()
{
    printf("\n\t\t\t\t\t\t\t\t\t1.ADD NEW RECORD\n");
    printf("\t\t\t\t\t\t\t\t\t2.GO BACK\n");
    printf("\t\t\t\t\t\t\t\t\t3.EXIT\n");
}
