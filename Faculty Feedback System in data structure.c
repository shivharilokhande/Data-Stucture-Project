#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag=0;
struct data{char  classs[30],t_course[30],t_name[30];
int s_no,aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am,an,sum,sn,dd,mm,yy,remark;
float per;};
int i;
struct node1{
int key;
struct data dat;
struct node1 *left;
struct node1 *right;};
typedef struct node{
char  classs[20],t_course[20],t_name[20];
int s_no,aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am,an,sum,dd,mm,yy;
float per;
struct node *next;}Node;
Node* insert_loc(Node*,Node*);
void create_queue();
void del_queue();
void display_queue(Node *front);
Node *rear=NULL;
Node *front=NULL;
Node *p,*head;
struct node1* createNode(struct data d){
struct node1* newNode =malloc(sizeof(struct node1));
newNode->dat = d;
newNode->left = NULL;
newNode->right= NULL;
return newNode;}
struct node1* insert(struct node1* node1, struct data d){
	if (node1 == NULL) return createNode(d);
if (d.sum < node1->dat.sum)
node1->left = insert(node1->left, d);
	else
node1->right = insert(node1->right, d);
return node1;}
void display(struct data d){
printf("\n\n%d\t\t%d/%d/%d\t%s\t\t%s\t\t\t\t%s\t\t\t%d\t\t\t%f",d.s_no,d.dd,d.mm,d.yy,d.classs,d.t_name,d.t_course,d.sum,d.per);
printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------");}
void treestruct(struct node1 *root,int space){
    if(root==NULL) return;
    space++;
    treestruct(root->right,space);
    printf("\n");
    for(i=0;i<space;i++)
        printf("\t");
    printf("%d\n",root->dat.sum);
    treestruct(root->left,space);}
void preorder(struct node1 *root){
    if(root==NULL) return;
    display(root->dat);
    preorder(root->left);
    preorder(root->right);}
void inorder(struct node1 *root){
    if(root==NULL) return;
        inorder(root->left);
    display(root->dat);
    inorder(root->right);}
void postorder(struct node1 *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    display(root->dat);}
struct data search(struct node1 *root, int d){
    struct data notf;
    struct node1 *root1 = root;
    notf.sn=0;
    for(root1 = root;root1!=NULL;root1 = root1->left){
if(root1->dat.s_no==d){
  printf("\nS_no\t\tDate\t\tClasss\t\tTeacher Name\t\tTeacher Course\t\tTotal\t\tPercentage");
printf("\n-------------------------------------------------------------------------------------------------------------");
                display(root1->dat);
                    return root1->dat;}}
for(root1 = root;root1!=NULL;root1 = root1->right){
      if(root1->dat.s_no==d){
                    display(root1->dat);
                    return root1->dat;}}
printf("\n Not Found \n");
    return notf;}
void update (struct node1 *root, int d){

    int loop17=0,dd,mm,yy;
     int loop18=0,loop19=0,loop20=0,loop22=0,loop21=0,loop23=0,loop24=0,loop25=0,loop26=0,loop27=0,loop28=0,loop29=0,loop30=0,loop31=0,loop32=0,loop33=0,loop34=0;
    struct data temp;
    temp = search(root,d);
    struct data dia;
    if(temp.sn!=0){
        loop17=0;
        while(loop17==0){
        dia.dd=0; dia.mm=0; dia.yy=0;
        printf("\n enter the date(DD/MM/YY ):-");
        scanf("%d/%d/%d",&(dia.dd),&(dia.mm),&(dia.yy));
        if(dia.dd<=31 && dia.mm<=12 && dia.yy>2010 && dia.yy<=2019){
        loop17=1;}
        else{
        printf("please enter valid date");
        loop17=0;}}
        printf("\n Enter Class:");
        scanf("%s",dia.classs);
printf("\n Enter Serial number:");
        scanf("%d",&dia.s_no);
        printf("\n Enter Teacher name:");
        scanf("%s",dia.t_name);
        printf("\n Enter Teacher Course:");
        scanf("%s",dia.t_course);
           printf("---------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("----------------------------------------------------------------------------------------------------------\n");
loop18=0;
while(loop18==0){
printf("\n Q1:Whether the lectures were well prepared organized and course material is well structured?\n");
         scanf("\n %d",&(dia.aa));
         if(dia.aa>=0&&dia.aa<=5)         {
             loop18=1;}
         else{

            loop18=0;
             printf("invalid remark");}}
loop19=0;
 while(loop19==0){
              printf("\nQ2: Was the blackboard writing clear and organized??\n");
              scanf("%d",&(dia.ab));
              if(dia.ab>=0&&dia.ab<=5){
             loop19=1;}
         else{
               printf("invalid remark");
            loop19=0;}}
loop20=0;
while(loop20==0){
              printf("\n Q3:Did the faculty provide you new knowledge and has command over the subject???\n");
              scanf("%d",&(dia.ac));
              if(dia.ac>=0&&dia.ac<=5){
             loop20=1;}
         else{
               printf("invalid remark");
            loop20=0;}}
loop21=0;
while(loop21==0){
              printf("\n Q4:Was the teacher able to deliver lectures with good communication skills?\n");
              scanf("%d",&(dia.ad));
              if(dia.ad>=0&&dia.ad<=5){
             loop21=1;}
         else{
               printf("invalid remark");
            loop21=0;}}
loop22=0;
while(loop22==0)  {
              printf("\n Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?\n");
              scanf("%d",&(dia.ae));
              if(dia.ae>=0&&dia.ae<=5){
             loop22=1;}
         else{
               printf("invalid remark");
            loop22=0;}}
loop23=0;
               while(loop23==0){
              printf("\n Q6:Whether teacher maintain overall discipline in the class?\n");
              scanf("%d",&(dia.af));
              if(dia.af>=0&&dia.af<=5){
             loop23=1;}
         else{
               printf("invalid remark");
            loop23=0;}}
loop24=0;
               while(loop24==0){
              printf("\n Q7:Whether teacher highlighted emphasized the usefulness importance of subject?\n");
              scanf("%d",&(dia.ag));
              if(dia.ag>=0&&dia.ag<=5){
             loop24=1;}
         else{
               printf("invalid remark");
            loop24=0;}}
loop25=0;
               while(loop25==0){
              printf("\n Q8:Whether teacher uses PPTs /LRs for effective teaching ?\n");
              scanf("%d",&(dia.ah));
              if(dia.ah>=0&&dia.ah<=5){
             loop25=1;}
         else{
               printf("invalid remark");
            loop25=0;}}
loop26=0;
               while(loop26==0){
              printf("\n Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?\n");
              scanf("%d",&(dia.ai));
              if(dia.ai>=0&&dia.ai<=5){
             loop26=1;}
         else{
               printf("invalid remark");
            loop26=0;}}
loop27=0;
               while(loop27==0){
              printf("\n Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?\n");
              scanf("%d",&(dia.aj));
              if(dia.aj>=0&&dia.aj<=5){
             loop27=1;}
         else{
               printf("invalid remark");
            loop27=0;}}
loop28=0;
               while(loop28==0){
              printf("\n Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?\n");
              scanf("%d",&(dia.ak));
              if(dia.ak>=0&&dia.ak<=5){
             loop28=1;}
         else{
               printf("invalid remark");
            loop28=0;}}
loop29=0;
               while(loop29==0){
              printf("\n Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??\n");
              scanf("%d",&(dia.al));
              if(dia.al>=0&&dia.al<=5){
             loop29=1;}
         else{
               printf("invalid remark");
            loop29=0;}}
loop30=0;
               while(loop30==0){
              printf("\n Q13:TAE and CAE marks were displayed regularly?\n");
              scanf("%d",&(dia.am));
              if(dia.am>=0&&dia.am<=5){
             loop30=1;}
         else{
               printf("invalid remark");
            loop30=0;}}
loop31=0;
               while(loop31==0){
              printf("\n Q14:What is your overall impression about the teacher?\n");
              scanf("%d",&(dia.an));
              if(dia.an>=0&&dia.an<=5){
             loop31=1;}
         else{
               printf("invalid remark");
            loop31=0;}}
loop32=0;
               while(loop32==0){
              dia.sum=(dia.aa+dia.ab+dia.ac+dia.ad+dia.ae+dia.af+dia.ag+dia.ah+dia.ai+dia.aj+dia.ak+dia.al+dia.am+dia.an);
              if(dia.sum>=14&&dia.sum<=70){
             loop32=1;}
         else{
               printf("invalid total");
            loop32=0;}}
loop33=0;
               while(loop33==0){
              dia.per=(dia.sum)*100/70;
              if(dia.per>=20&&dia.per<=100){
             loop33=1;}
         else{
               printf("invalid percentage");
            loop33=0;}}
                 root->dat = dia;}}
struct node1 * minValueNode(struct node1* node1){
	struct node1* current = node1;
while (current->left != NULL)
		current = current->left;
return current;}
struct node1* deleteNode(struct node1* root, int key){
	if (root == NULL) return root;
if (key < root->dat.s_no)
		root->left = deleteNode(root->left, key);
	else if (key > root->dat.s_no)
		root->right = deleteNode(root->right, key);
		else{
		if (root->left == NULL){
			struct node1 *temp = root->right;
			free(root);
			return temp;}
		else if (root->right == NULL){
			struct node1 *temp = root->left;
			free(root);
			return temp;}
struct node1* temp = minValueNode(root->right);
root->dat.s_no = temp->dat.s_no;
root->right = deleteNode(root->right, temp->dat.s_no);}
return root;}
void create_queue(int n){
     Node *temp,*p;
     int i,loop=0,loop1=0;
     for(i=0;i<n;i++){
      if (rear==NULL){
        rear=(Node*)malloc(sizeof(Node)*100);
   printf("\n\t\t\t\t\t\tEnter S_NO:");
scanf("%d",&(rear->s_no));
    printf("\n\t\t\t\t\t\t Enter CLASS:");
    scanf("%s",(rear->classs));
    printf("\n\t\t\t\t\t\t Enter Teacher_name:");
    scanf("%s",(rear->t_name));
    printf("\n\t\t\t\t\t\t Enter Teacher_course :");
    scanf("%s",(rear->t_course));
    loop=0;
    while(loop==0){
        rear->dd=0,rear->mm=0,rear->yy=0;
        printf("\n\t\t\t\t\t\tEnter Date:");
    scanf("%d%d%d",(rear->dd),(rear->mm),(rear->yy));
         if(rear->dd<=31 && rear->mm<=12 && rear->yy>2010 && rear->yy<=2019){
                             loop=1;}
                            else{
                            printf("please enter valid date");
                               loop=0;}}
    printf("\n\n----------------------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("-----------------------------------------------------------------------------------------------------------------------");
printf("\n\n");
loop1=0;
while(loop1=0){
printf("Q1:Whether the lectures were well prepared organized and course material is well structured?=");
         scanf(" %d",&(rear->aa));
         if(rear->aa>=0&&rear->aa<=5){
             loop1=1;}
         else{
                printf("invalid");
         loop1=0;}}
printf("Q2: Was the blackboard writing clear and organized??=");
              scanf("%d",&(rear->ab));
printf("Q3:Did the faculty provide you new knowledge and has command over the subject???=");
              scanf("%d",&(rear->ac));
printf("Q4:Was the teacher able to deliver lectures with good communication skills?=");
              scanf("%d",&(rear->ad));
printf("Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?=");
              scanf("%d",&(rear->ae));
printf("Q6:Whether teacher maintain overall discipline in the class?=");
              scanf("%d",&(rear->af));
printf("Q7:Whether teacher highlighted emphasized the usefulness importance of subject?=");
              scanf("%d",&(rear->ag));
printf("Q8:Whether teacher uses PPTs /LRs for effective teaching ?=");
              scanf("%d",&(rear->ah));
printf("Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?=");
              scanf("%d",&(rear->ai));
printf("Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?=");
              scanf("%d",&(rear->aj));
printf("Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?=");
              scanf("%d",&(rear->ak));
printf("Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??=");
              scanf("%d",&(rear->al));
printf("Q13:TAE and CAE marks were displayed regularly?=");
              scanf("%d",&(rear->am));
printf("Q14:What is your overall impression about the teacher?=");
              scanf("%d",&(rear->an));
              rear->sum=(rear->aa+rear->ab+rear->ac+rear->ad+rear->ae+rear->af+rear->ag+rear->ah+rear->ai+rear->aj+rear->ak+rear->al+rear->am+rear->an);
rear->per=(rear->sum)*100/70;
printf("____________________________________________________________________________________________________________________\n");
        rear->next=rear;
        front=rear;}
    else{
        temp=(Node*)malloc(sizeof(Node));
printf("\n\t\t\t\t\t\tEnter S_NO:");
scanf("%d",&(temp->s_no));
    printf("\n\t\t\t\t\t\tEnter Class :");
    scanf("%s",(temp->classs));
    printf("\n\t\t\t\t\t\tEnter Teacher name :");
    scanf("%s",(temp->t_name));
    printf("\n\t\t\t\t\t\tEnter Teacher course:");
    scanf("%s",(temp->t_course));
printf("\n\t\t\t\t\t\tEnter Date :");
    scanf("%d%d%d",(temp->dd),(temp->mm),(temp->yy));
printf("\n\n----------------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("-------------------------------------------------------------------------------------------------------------");
printf("\n\n");
              printf("Q1:Whether the lectures were well prepared organized and course material is well structured?=");
              scanf("%d",&(temp->aa));
              printf("Q2: Was the blackboard writing clear and organized??=");
              scanf("%d",&(temp->ab));
              printf("Q3:Did the faculty provide you new knowledge and has command over the subject???=");
              scanf("%d",&(temp->ac));
              printf("Q4:Was the teacher able to deliver lectures with good communication skills?=");
              scanf("%d",&(temp->ad));
              printf("Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?=");
              scanf("%d",&(temp->ae));
              printf("Q6:Whether teacher maintain overall discipline in the class?=");
              scanf("%d",&(temp->af));
              printf("Q7:Whether teacher highlighted emphasized the usefulness importance of subject?=");
              scanf("%d",&(temp->ag));
              printf("Q8:Whether teacher uses PPTs /LRs for effective teaching ?=");
              scanf("%d",&(temp->ah));
              printf("Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?=");
              scanf("%d",&(temp->ai));
              printf("Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?=");
              scanf("%d",&(temp->aj));
              printf("Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?=");
              scanf("%d",&(temp->ak));
              printf("Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??=");
              scanf("%d",&(temp->al));
              printf("Q13:TAE and CAE marks were displayed regularly?=");
              scanf("%d",&(temp->am));
              printf("Q14:What is your overall impression about the teacher?=");
              scanf("%d",&(temp->an));
              temp->sum=(temp->aa+temp->ab+temp->ac+temp->ad+temp->ae+temp->af+temp->ag+temp->ah+temp->ai+temp->aj+temp->ak+temp->al+temp->am+temp->an);
              temp->per=(temp->sum)*100/70;
printf("________________________________________________________________________________________________________\n");
              rear->next=temp;
             temp->next=NULL;
             rear=temp;    }}}
void display_queue(Node *front){
    Node *p;
    int sum=0;
    int j=0;
if(front==NULL)    {
        printf("\n\t\t\t\t\t\t*Queue Underflow*\n");}
    else{
        p=front;
while(p!=NULL){
 printf("\n\t DATE:\t\t\t\t\t\t\t    CLASSS:     \n");
printf("          %d%d%d",(p->dd),(p->mm),(p->yy));
  printf("                                                        %s",p->classs);
                           printf("\n");
printf("\nS_No:\t\tName of the Theory course:\t\tName of the Teacher\t\ttotal\t\tpercentage:      ");
printf("\n %d",p->s_no);
 printf("                         %s",p->t_course);
 printf("                                   %s",p->t_name);
printf("                         %d",p->sum);
printf("            %f",p->per);
printf("\n-------------------------------------------------------------------------------------------------------");
p=p->next;}}}
Node* insert_loc(Node *front,Node *rear){
Node *p,*q;
int i;
printf("Enter New :::");
p=(Node*)malloc(sizeof(Node));
printf("\nEnter  s_no:");
               scanf("%d",&p->s_no);
                printf("\nEnter classs :");
    scanf("%s",(p->classs));
    printf("\nEnter teacher name :");
    scanf("%s",(p->t_name));
    printf("\nEnter teacher course:");
    scanf("%s",(p->t_course));
    printf("\n enter date :");
                scanf("%d%d%d",(p->dd),(p->mm),(p->yy));
printf("---------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("----------------------------------------------------------------------------------------------------------\n");
printf("\n Q1:Whether the lectures were well prepared organized and course material is well structured?\n");
         scanf("\n %d",&(p->aa));
              printf("\nQ2: Was the blackboard writing clear and organized??\n");
              scanf("%d",&(p->ab));
              printf("\n Q3:Did the faculty provide you new knowledge and has command over the subject???\n");
              scanf("%d",&(p->ac));
              printf("\n Q4:Was the teacher able to deliver lectures with good communication skills?\n");
              scanf("%d",&(p->ad));
              printf("\n Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?\n");
              scanf("%d",&(p->ae));
              printf("\n Q6:Whether teacher maintain overall discipline in the class?\n");
              scanf("%d",&(p->af));
              printf("\n Q7:Whether teacher highlighted emphasized the usefulness importance of subject?\n");
              scanf("%d",&(p->ag));
              printf("\n Q8:Whether teacher uses PPTs /LRs for effective teaching ?\n");
              scanf("%d",&(p->ah));
              printf("\n Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?\n");
              scanf("%d",&(p->ai));
              printf("\n Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?\n");
              scanf("%d",&(p->aj));
              printf("\n Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?\n");
              scanf("%d",&(p->ak));
              printf("\n Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??\n");
              scanf("%d",&(p->al));
              printf("\n Q13:TAE and CAE marks were displayed regularly?\n");
              scanf("%d",&(p->am));
              printf("\n Q14:What is your overall impression about the teacher?\n");
              scanf("%d",&(p->an));
              p->sum=(p->aa+p->ab+p->ac+p->ad+p->ae+p->af+p->ag+p->ah+p->ai+p->aj+p->ak+p->al+p->am+p->an);
              p->per=(p->sum)*100/70;
    p->next=NULL;
p->next=rear->next;
rear->next=p;
return(front);}
void del_queue(){
    Node *temp;
    if(front==NULL){
        printf("\n*Queue Underflow*\n");}
    else{
    temp = front;
    front=front->next;
    printf("\n\nData At Front::\n\n");
     printf("\n S_NO   CLASSS     TEACHER_NAME    TEACHER_COURSE     DATE   TOTAL  PERCENTAGE");
    printf("\n-------------------------------------------------------------------------------------------------------------------");
printf("\n  %d",temp->s_no);
printf("         %s",temp->classs);
printf("           %s",temp->t_name);
printf("              %s",temp->t_course);
printf("               %d%d%d\n",(temp->dd),(temp->mm),(temp->yy));
printf("\n Q1:Whether the lectures were well prepared organized and course material is well structured?=%d\n",temp->aa);
printf("\n Q2:Was the blackboard writing clear and organized?=%d\n",temp->ab);
printf("\n Q3:Did the faculty provide you new knowledge and has command over the subject????=%d\n",temp->ac);
printf("\n Q4:Was the teacher able to deliver lectures with good communication skills?=%d\n",temp->ad);
printf("\n Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)??=%d\n",temp->ae);
printf("\n Q6:Whether teacher maintain overall discipline in the class?=%d\n",temp->af);
printf("\n Q7:Whether teacher highlighted emphasized the usefulness importance of subject?=%d\n",temp->ag);
printf("\n Q8:Whether teacher uses PPTs /LRs for effective teaching ?=%d\n",temp->ah);
printf("\n Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?=%d\n",temp->ai);
printf("\n Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?=%d\n",temp->aj);
printf("\n Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach));?=%d\n",temp->ak);
printf("\n Q12:CAE question paper was discussed in the class after exam and answer sheets where shown?=%d\n",temp->al);
printf("\n Q13:TAE and CAE marks were displayed regularly?=%d\n",temp->am);
printf("\n Q14:What is your overall impression about the teacher?=%d\n",temp->an);
         free(temp);}}
int main(){
    int ch, sea,n,loop=0,loop1=0,loop2=0,loop3=0,loop4=0,loop5=0,loop6=0,loop7=0,loop8=0,loop9=0,loop10=0,loop11=0,loop12=0,loop13=0,loop14=0,loop15=0,loop16=0,loop17=0,dd,mm,yy;
    int loop18=0,loop19=0,loop20=0,loop22=0,loop21=0,loop23=0,loop24=0,loop25=0,loop26=0,loop27=0,loop28=0,loop29=0,loop30=0,loop31=0,loop32=0,loop33=0,loop34=0;
    struct data dia;
     printf("\t\t\t\t@@@@@@@@@@@@   FACULTY FEEDBACK FORM   @@@@@@@@@@@\n");
int user_n,user_n1,pass_wd,pass_wd1;
    user_n = 7476;
    pass_wd = 0000;
    do{
    printf("\n\n\t\t\t\t\t\t   Username::");
    scanf("%d",&user_n1);
    printf("\n\t\t\t\t\t\t   Password::");
    scanf("%d",&pass_wd1);
    if(user_n1!=user_n || pass_wd1!=pass_wd){
        printf("\n\n\t\t\t\t*****YOU ENTERED WRONG PASSWORD*****\n");
        printf("\n\n\t\t\t\t___________________________________________________________________________________\n\n");}
}while(user_n1!=user_n || pass_wd1!=pass_wd);
do{    printf("\n1.create \n2.insert \n3.search \n4. update\n5. delete \n6. display Preorder\n7. display Inorder\n8. display Postorder\n9. Tree Format\n10.create Queue\n11.display queue\n12.insert queue\n13.delete queues\n14. Exit");
    printf("\nSelect your choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
         while(loop==0){
                        printf("\n enter the date(DD/MM/YY ):-");
                        scanf("%d/%d/%d",&(dia.dd),&(dia.mm),&(dia.yy));
                        if(dia.dd<=31 && dia.mm<=12 && dia.yy>2010 && dia.yy<=2019){
                             loop=1;}
                            else{
                            printf("please enter valid date");
                               loop=0;}}
            printf("\n Enter Class:");
        scanf("%s",dia.classs);
printf("\n Enter Serial number:");
        scanf("%d",&dia.s_no);
                printf("\n Enter Teacher name:");
        scanf("%s",dia.t_name);
printf("\n Enter Teacher Course:");
        scanf("%s",dia.t_course);
                   printf("---------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("----------------------------------------------------------------------------------------------------------\n");
while(loop1==0){
printf("\n Q1:Whether the lectures were well prepared organized and course material is well structured?\n");
         scanf("\n %d",&(dia.aa));
         if(dia.aa>=0&&dia.aa<=5)         {
             loop1=1;}
         else{
               printf("invalid remark");
            loop1=0;}}
 while(loop2==0){
              printf("\nQ2: Was the blackboard writing clear and organized??\n");
              scanf("%d",&(dia.ab));
              if(dia.ab>=0&&dia.ab<=5){
             loop2=1;}
         else{
               printf("invalid remark");
            loop2=0;}}
               while(loop3==0){
              printf("\n Q3:Did the faculty provide you new knowledge and has command over the subject???\n");
              scanf("%d",&(dia.ac));
              if(dia.ac>=0&&dia.ac<=5){
             loop3=1;}
         else{
               printf("invalid remark");
            loop3=0;}}
               while(loop4==0){
              printf("\n Q4:Was the teacher able to deliver lectures with good communication skills?\n");
              scanf("%d",&(dia.ad));
              if(dia.ad>=0&&dia.ad<=5){
             loop4=1;}
         else{
               printf("invalid remark");
            loop4=0;}}
               while(loop5==0){
              printf("\n Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?\n");
              scanf("%d",&(dia.ae));
              if(dia.ae>=0&&dia.ae<=5){
             loop5=1;}
         else{
               printf("invalid remark");
            loop5=0;}}
               while(loop6==0){
              printf("\n Q6:Whether teacher maintain overall discipline in the class?\n");
              scanf("%d",&(dia.af));
              if(dia.af>=0&&dia.af<=5){
             loop6=1;}
         else{
               printf("invalid remark");
            loop6=0;}}
               while(loop7==0){
              printf("\n Q7:Whether teacher highlighted emphasized the usefulness importance of subject?\n");
              scanf("%d",&(dia.ag));
              if(dia.ag>=0&&dia.ag<=5){
             loop7=1;}
         else{
               printf("invalid remark");
            loop7=0;}}
               while(loop8==0){
              printf("\n Q8:Whether teacher uses PPTs /LRs for effective teaching ?\n");
              scanf("%d",&(dia.ah));
              if(dia.ah>=0&&dia.ah<=5){
             loop8=1;}
         else{
               printf("invalid remark");
            loop8=0;}}
               while(loop9==0){
              printf("\n Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?\n");
              scanf("%d",&(dia.ai));
              if(dia.ai>=0&&dia.ai<=5){
             loop9=1;}else{
               printf("invalid remark");
            loop9=0;}}
               while(loop10==0){
              printf("\n Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?\n");
              scanf("%d",&(dia.aj));
              if(dia.aj>=0&&dia.aj<=5){
             loop10=1;}
             else{
               printf("invalid remark");
            loop10=0;}}
               while(loop11==0){
              printf("\n Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?\n");
              scanf("%d",&(dia.ak));
              if(dia.ak>=0&&dia.ak<=5){
             loop11=1;}
         else{
               printf("invalid remark");
            loop11=0;}}
               while(loop12==0){
              printf("\n Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??\n");
              scanf("%d",&(dia.al));
              if(dia.al>=0&&dia.al<=5){
             loop12=1;}
         else{
               printf("invalid remark");
            loop12=0;}}
               while(loop13==0){
    printf("\n Q13:TAE and CAE marks were displayed regularly?\n");
              scanf("%d",&(dia.am));
              if(dia.am>=0&&dia.am<=5){
             loop13=1;}
         else{
               printf("invalid remark");
            loop13=0;}}
               while(loop14==0){
              printf("\n Q14:What is your overall impression about the teacher?\n");
              scanf("%d",&(dia.an));
              if(dia.an>=0&&dia.an<=5){
             loop14=1;}
         else{
               printf("invalid remark");
            loop14=0;}}
               while(loop15==0){
              dia.sum=(dia.aa+dia.ab+dia.ac+dia.ad+dia.ae+dia.af+dia.ag+dia.ah+dia.ai+dia.aj+dia.ak+dia.al+dia.am+dia.an);
              if(dia.sum>=14&&dia.sum<=70){
             loop15=1;}
         else{
               printf("invalid remark");
            loop15=0;}}
               while(loop16==0){
              dia.per=(dia.sum)*100/70;
              if(dia.per>=20&&dia.per<=100){
             loop16=1;}
         else{
               printf("invalid remark");
            loop16=0;}}
struct node1 *root = createNode(dia);
        break;
    case 2:
        loop17=0;
        while(loop17==0){
                            dia.dd=0; dia.mm=0; dia.yy=0;
                        printf("\n enter the date(DD/MM/YY ):-");
                        scanf("%d/%d/%d",&(dia.dd),&(dia.mm),&(dia.yy));
                        if(dia.dd<=31 && dia.mm<=12 && dia.yy>2010 && dia.yy<=2019){
                             loop17=1;}
                            else{
                            printf("please enter valid date");
                               loop17=0;}}
        printf("\n Enter Class:");
        scanf("%s",dia.classs);
printf("\n Enter Serial number:");
        scanf("%d",&dia.s_no);
        printf("\n Enter Teacher name:");
        scanf("%s",dia.t_name);
        printf("\n Enter Teacher Course:");
        scanf("%s",dia.t_course);
           printf("---------------------------------------------REMARKS-----------------------------------------------------\n\n");
printf("0.NOT SATISFACTORY\t1.SATISFACTORY\t\t2.GOOD\t\t3.VERY GOOD\t4.EXCELLENT\t\t5.OUTSTANDING\n\n");
printf("----------------------------------------------------------------------------------------------------------\n");
loop18 =0;
while(loop18==0){
printf("\n Q1:Whether the lectures were well prepared organized and course material is well structured?\n");
         scanf("\n %d",&(dia.aa));
         if(dia.aa>=0&&dia.aa<=5)         {
             loop18=1;}
         else{
               printf("invalid remark");
            loop18=0;}}
loop19=0;
 while(loop19==0){
              printf("\nQ2: Was the blackboard writing clear and organized??\n");
              scanf("%d",&(dia.ab));
              if(dia.ab>=0&&dia.ab<=5){
             loop19=1;}
         else{
               printf("invalid remark");
            loop19=0;}}
loop20=0;
while(loop20==0){
              printf("\n Q3:Did the faculty provide you new knowledge and has command over the subject???\n");
              scanf("%d",&(dia.ac));
              if(dia.ac>=0&&dia.ac<=5){
             loop20=1;}
         else{
               printf("invalid remark");
            loop20=0;}}
loop21=0;
while(loop21==0){
              printf("\n Q4:Was the teacher able to deliver lectures with good communication skills?\n");
              scanf("%d",&(dia.ad));
              if(dia.ad>=0&&dia.ad<=5){
             loop21=1;}
         else{
               printf("invalid remark");
            loop21=0;}}
loop22=0;
while(loop22==0)  {
              printf("\n Q5:Whether teacher utilize the allocated time effectively(punctuality &regularity,etc)?\n");
              scanf("%d",&(dia.ae));
              if(dia.ae>=0&&dia.ae<=5){
             loop22=1;}
         else{
               printf("invalid remark");
            loop22=0;}}
loop23=0;
               while(loop23==0){
              printf("\n Q6:Whether teacher maintain overall discipline in the class?\n");
              scanf("%d",&(dia.af));
              if(dia.af>=0&&dia.af<=5){
             loop23=1;}
         else{
               printf("invalid remark");
            loop23=0;}}
loop24=0;
               while(loop24==0){
              printf("\n Q7:Whether teacher highlighted emphasized the usefulness importance of subject?\n");
              scanf("%d",&(dia.ag));
              if(dia.ag>=0&&dia.ag<=5){
             loop24=1;}
         else{
               printf("invalid remark");
            loop24=0;}}
loop25=0;
               while(loop25==0){
              printf("\n Q8:Whether teacher uses PPTs /LRs for effective teaching ?\n");
              scanf("%d",&(dia.ah));
              if(dia.ah>=0&&dia.ah<=5){
             loop25=1;}
         else{
               printf("invalid remark");
            loop25=0;}}
loop26=0;
               while(loop26==0){
              printf("\n Q9:Whether teacher motivated and encourage to learn the subject and created interest in it?\n");
              scanf("%d",&(dia.ai));
              if(dia.ai>=0&&dia.ai<=5){
             loop26=1;}
         else{
               printf("invalid remark");
            loop26=0;}}
loop27=0;
               while(loop27==0){
              printf("\n Q10:Whether the teacher was always accessible to the student for courseling guidance and solving queries outside the classroom?\n");
              scanf("%d",&(dia.aj));
              if(dia.aj>=0&&dia.aj<=5){
             loop27=1;}
         else{
               printf("invalid remark");
            loop27=0;}}
loop28=0;
               while(loop28==0){
              printf("\n Q11:The TAE parameters and test's where challenging (with new and novel problem solving approach)?\n");
              scanf("%d",&(dia.ak));
              if(dia.ak>=0&&dia.ak<=5){
             loop28=1;}
         else{
               printf("invalid remark");
            loop28=0;}}
loop29=0;
               while(loop29==0){
              printf("\n Q12:CAE question paper was discussed in the class after exam and answer sheets where shown??\n");
              scanf("%d",&(dia.al));
              if(dia.al>=0&&dia.al<=5){
             loop29=1;}
         else{
               printf("invalid remark");
            loop29=0;}}
loop30=0;
               while(loop30==0){
              printf("\n Q13:TAE and CAE marks were displayed regularly?\n");
              scanf("%d",&(dia.am));
              if(dia.am>=0&&dia.am<=5){
             loop30=1;}
         else{
               printf("invalid remark");
            loop30=0;}}
loop31=0;
               while(loop31==0){
              printf("\n Q14:What is your overall impression about the teacher?\n");
              scanf("%d",&(dia.an));
              if(dia.an>=0&&dia.an<=5){
             loop31=1;}
         else{
               printf("invalid remark");
            loop31=0;}}
loop32=0;
               while(loop32==0){
              dia.sum=(dia.aa+dia.ab+dia.ac+dia.ad+dia.ae+dia.af+dia.ag+dia.ah+dia.ai+dia.aj+dia.ak+dia.al+dia.am+dia.an);
              if(dia.sum>=14&&dia.sum<=70){
             loop32=1;}
         else{
               printf("invalid total");
            loop32=0;}}
loop33=0;
               while(loop33==0){
              dia.per=(dia.sum)*100/70;
              if(dia.per>=20&&dia.per<=100){
             loop33=1;}
         else{
               printf("invalid percentage");
            loop33=0;}}
insert(root,dia);
        break;
    case 3:
        printf("Enter serial number to be search: ");
        scanf("%d",&sea);
        search(root,sea);
        break;
    case 4:
        printf("Enter serial number to be modify: ");
        scanf("%d",&sea);
update(root,sea);
        break;
    case 5:
        printf("Enter the serial number to Delete:");
        scanf("%d",&sea);
        root = deleteNode(root,sea);
        break;
    case 6:
   printf("\nS_no\t\tDate\t\tClasss\t\tTeacher Name\t\tTeacher Course\t\tTotal\t\tPercentage");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
         preorder(root);
        break;
        case 7:
    printf("\nS_no\t\tDate\t\tClasss\t\tTeacher Name\t\tTeacher Course\t\tTotal\t\tPercentage");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------");
         inorder(root);
        break;
    case 8:
     printf("\nS_no\t\tDate\t\tClasss\t\tTeacher Name\t\tTeacher Course\t\tTotal\t\tPercentage");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
            postorder(root);
        break;
    case 9:


         treestruct(root,0);
        break;
    case 10:
         printf("enter no.of faculties u want:");
        scanf("%d",&n);
        create_queue(n);
        break;
    case 11:
         display_queue(front);
        break;
    case 12:
         front= insert_loc(front,rear);
        rear=rear->next;
        n=n+1;
        break;
    case 13:
         del_queue();
        n=n-1;
        break;
         case 14:
        exit(0);
    }
    }while(ch<15 && ch>0);
    return 0;}
