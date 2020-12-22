#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct counts
{
    int b[10];
    char n;
    float p;
    float total;
};

struct stock
{
    int items[10];
    int items1[10];
}*s;

struct tokentime
{
    int token;
    int order;
    int ordered_hour;
    int ordered_minute;
    char ordered_time[80];
}*T;
double amount=0.0;
void main_menu(int *z,char n);
int billing(float s,int *z);
void print(int x,float total);
void delete(float s,int *z);
void add(int *z);
void stockentry();
void tokenandtime(int i,int *z,char date[14]);
int ordertime(int *z);
void order1(int i,int *z);
void main_order(int *z,char date[14],int i,int payment,char name[10], long int MNO,int billno);
int counting(int n);
int counting_(long int n);
int main()
{
    char date[14];
    printf("Enter todays date in DD-MM-YYYY\n");
    scanf("%s",date);
    stockentry();
    int i=0,flag=0,pin,rpin;
    while(1)
    {
        printf("Enter a four digit pin\n");
        while(1)
        {
        scanf("%d",&pin);
        int n=counting(pin);
        if(n==4)
            break;
        else
            printf("*****Please enter a valid pin*****\n");
        }
        printf("Re enter the pin\n");
        scanf("%d",&rpin);
        if(pin!=rpin)
            printf("Incorrect pin\n");
        else
            break;
    }
    system("clear");
    T=(struct tokentime*)malloc(150*(sizeof(struct tokentime)));
    do
    {
        struct counts s1;
        int *z,k,billno,payment;
        long int MNO;
        char name[10];
        z=&s1.b[0];
        int f;
        s1.total=0;
        s1.p=0;
        s1.b[0]=0;s1.b[1]=0;s1.b[2]=0;s1.b[3]=0;s1.b[4]=0;s1.b[5]=0;s1.b[6]=0;s1.b[7]=0;s1.b[8]=0;s1.b[9]=0;
	    printf("\t\t\t  *******************Welcome to K2K Bakers****************** \n");
	    printf("\t\t\t------------------------------------------------------------------\n");
	    printf("\nAt Your service");
	    printf("\nEnter your order\n");
	    main_menu(&s1.b[0],s1.n);
	    printf("Do you want to coform the order?\n");
	    do
	    {
	        printf("To add any thing enter 1,to delete any selected item enter 2,to conform your order enter 0\n");
	        scanf("%d",&k);
	        if(k==1)
	        add(z);
	        else if(k==2)
	        delete(s1.total,&s1.b[0]);
	        else if(k==0)
	        {}
	        else if(k==pin)
	        {  
	            flag=1;
	            break;
	        }
	        else
	            printf("*****Enter a vaild option*****\n");
	    }while(k!=0);
	    if(flag!=1)
	    {
	        if(*z==0&&*(z+1)==0&&*(z+2)==0&&*(z+3)==0&&*(z+4)==0&&*(z+5)==0&&*(z+6)==0&&*(z+7)==0&&*(z+8)==0&&*(z+9)==0)
	        {
	            printf("\n*****Please try to order something*****\n\n");
	        }
	        else
	        {
	            f=billing(s1.p,&s1.b[0]);
	            print(f,s1.total);
	            tokenandtime(i,&s1.b[0],date);
	            printf("Your token number: %d\n",T[i].token);
	            printf("Your order will be readyed in %d minutes\n",T[i].order);
	            printf("Enter the payment method\n1)Chash\n2)Card\n3)UPI\n");
	            while(1)
	            {
	            scanf("%d",&payment);
	            if(payment==1 || payment==2 || payment==3)
	            {
	                break;
	            }
	            else
	                printf("*****Enter a valid option*****\n");
	            }
                printf("Enter the six digit bill number\n");
                while(1)
                {
                scanf("%d",&billno);
                int l1=counting(billno);
                if(l1==6)
                    break;
                else
                    printf("*****Enter a valid bill number*****\n");
                }
                order1(T[i].token,&s1.b[0]);
                printf("Enter name\n");
                scanf("%s",name);
                printf("Enter mobile number\n");
                while(1)
                {
                scanf("%ld",&MNO);
                int length=counting_(MNO);
                if(length==10)
                    break;
                else
                    printf("*****Enter a valid phone number*****\n");
                }
                main_order(&s1.b[0],date,i,payment,name,MNO,billno);
                system("clear");
                i++;
	        }
	    }
    }while(flag!=1);
    FILE *fp;int j;
    fp=fopen(date,"a");
    for(j=0;j<10;j++)
    {
        s->items1[j]=s->items1[j]-s->items[j];
    }
    fprintf(fp,"\n");
    fprintf(fp,"\t\t****************************************\n");
    fprintf(fp,"Veg Burgers sold %d: Veg Burgers left %d = Rs %d\n",s->items1[0],s->items[0],s->items1[0]*40);
    fprintf(fp,"Non-Veg Burgers sold %d: Non-Veg Burgers left %d = Rs %d\n",s->items1[1],s->items[1],s->items1[1]*60);
    fprintf(fp,"Veg Pizzas sold %d: Veg Pizzas left %d = Rs %d\n",s->items1[2],s->items[2],s->items1[2]*70);
    fprintf(fp,"Non-Veg Pizzas sold %d: Non-Veg Pizzas left %d = Rs %d\n",s->items1[3],s->items[3],s->items1[3]*100);
    fprintf(fp,"Veg Puffs sold %d: Veg Puffs left %d = Rs %d\n",s->items1[4],s->items[4],s->items1[4]*30);
    fprintf(fp,"Egg Puffs sold %d: Egg Puffs left %d = Rs %d\n",s->items1[5],s->items[5],s->items1[5]*35);
    fprintf(fp,"Blue Berry Cakes sold %d: Blue Berry Cakes %d = Rs %d\n",s->items1[6],s->items[6],s->items1[6]*60);
    fprintf(fp,"Cherry Cakes sold %d: Cherry Cakes left %d = Rs %d\n",s->items1[7],s->items[7],s->items1[7]*75);
    fprintf(fp,"Cherry Pies sold %d: Cherry Pies left %d = Rs %d\n",s->items1[8],s->items[8],s->items1[8]*45);
    fprintf(fp,"Apple Pies sold %d: Apple Pies left %d = Rs %d\n",s->items1[9],s->items[9],s->items1[9]*55);
    fprintf(fp,"Total amount %f",amount);
    fclose(fp);
	 return 0;
}

int counting(int n)
{
     int count = 0;
    while (n != 0) {
        n /= 10;     
        ++count;
    }
    return count;
}
int counting_(long int n)
{
     int count = 0;
    while (n != 0) {
        n /= 10;     
        ++count;
    }
    return count;
}

void stockentry()
{
    int n;
    s=(struct stock*)malloc(sizeof(struct stock));
    printf("\t\tAvailable stock to be entered\n");
    printf("\tEnter number of veg burgers\n");
    while(1)
    {
     printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[0]=n;
    s->items1[0]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of non-veg burgers\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[1]=n;
    s->items1[1]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of veg pizzas\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[2]=n;
    s->items1[2]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of non-veg pizzas\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[3]=n;
    s->items1[3]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of veg puffs\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[4]=n;
    s->items1[4]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of egg puffs\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[5]=n;
    s->items1[5]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of Blue Berry cakes\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[6]=n;
    s->items1[6]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of Cherry cakes\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[7]=n;
    s->items1[7]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of Cherry pies\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[8]=n;
    s->items1[8]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
    printf("\tEnter number of Apple pies\n");
    while(1)
    { printf("\t");
    scanf("%d",&n);
    if(n>=0)
    {s->items[9]=n;
    s->items1[9]=n;
    break;
    }
    else
        printf("*****Enter a valid input*****\n");
    }
}

void order1(int i,int *z)
{
    FILE *fp;int n;
    fp=fopen("Order.txt","a");
    n=i;
    fprintf(fp,"Token number %d\n\n",n);
    if(*z!=0)
        fprintf(fp,"Veg Burger %d\n",*z);
    if(*(z+1)!=0)
        fprintf(fp,"Non-Veg Burger %d\n",*(z+1));
    if(*(z+2)!=0)
        fprintf(fp,"Veg Pizzas %d\n",*(z+2));
    if(*(z+3)!=0)
        fprintf(fp,"Non-Veg Pizzas %d\n",*(z+3));
    if(*(z+4)!=0)
        fprintf(fp,"Veg Puffs %d\n",*(z+4));
    if(*(z+5)!=0)
        fprintf(fp,"Egg Puffs %d\n",*(z+5));
    if(*(z+6)!=0)
        fprintf(fp,"Blue Berry cakes %d\n",*(z+6));
    if(*(z+7)!=0)
        fprintf(fp,"Cherry cakes %d\n",*(z+7));
    if(*(z+8)!=0)
        fprintf(fp,"Cherry pies %d\n",*(z+8));
    if(*(z+9)!=0)
        fprintf(fp,"Apple pies %d\n",*(z+9));
    fprintf(fp,"-----------------------------------------------\n");
    fclose(fp);
}

void main_order(int *z,char date[14],int i,int payment,char name[10], long int MNO,int billno)
{
    FILE *fp;
    float total=0;
    fp=fopen(date,"a");
    fprintf(fp,"Token number %d\n\n",T[i].token);
    fprintf(fp,"Bill number:%d\n",billno);
    fprintf(fp,"Name:%s\n",name);
    fprintf(fp,"Mobile:%ld\n",MNO);
    fprintf(fp,"Time: %s\n\n",T[i].ordered_time);
    fprintf(fp,"||Order||\n");
    if(*z!=0)
    {    
        fprintf(fp,"Veg Burger %d=%d\n",*z,*z *40);
        total=total+(*z *40);
    }
    if(*(z+1)!=0)
    {
        fprintf(fp,"Non-Veg Burger %d=%d\n",*(z+1),*(z+1) *60);
        total=total+(*(z+1) *60);
    }
    if(*(z+2)!=0)
    {    
        fprintf(fp,"Veg Pizzas %d=%d\n",*(z+2),*(z+2) *70);
        total=total+(*(z+2) *70);
    }
    if(*(z+3)!=0)
    {
        fprintf(fp,"Non-Veg Pizzas %d=%d\n",*(z+3),*(z+3) *100);
        total=total+(*(z+3) *100);
    }
    if(*(z+4)!=0)
    {
        fprintf(fp,"Veg Puffs %d=%d\n",*(z+4),*(z+4) *30);
        total=total+(*(z+4) *30);
    }
    if(*(z+5)!=0)
    {
        fprintf(fp,"Egg Puffs %d=%d\n",*(z+5),*(z+5) *35);
        total=total+(*(z+5) *35);
    }
    if(*(z+6)!=0)
    {
        fprintf(fp,"Blue Berry cakes %d=%d\n",*(z+6),*(z+6) *60);
        total=total+(*(z+6) *60);
    }
    if(*(z+7)!=0)
    {
        fprintf(fp,"Cherry cakes %d=%d\n",*(z+7),*(z+7) *75);
        total=total+(*(z+7) *75);
    }
    if(*(z+8)!=0)
    {
        fprintf(fp,"Cherry pies %d=%d\n",*(z+8),*(z+8) *45);
        total=total+(*(z+8) *45);
    }
    if(*(z+9)!=0)
    {
        fprintf(fp,"Apple pies %d=%d\n",*(z+9),*(z+9) *55);
        total=total+(*(z+9) *55);
    }
    total=total+((6.0*total)/100);
    amount=amount+total;
    fprintf(fp,"Total amount=%f\n\n",total);
    if(payment==1)
        fprintf(fp,"Payment in cash\n");
    if(payment==2)
        fprintf(fp,"Payment in card\n");
    if(payment==3)
        fprintf(fp,"Payment in UPI\n");
    fprintf(fp,"-----------------------------------------------------------------------------------\n");
    fclose(fp);
}

void tokenandtime(int i,int *z,char date[14])
{
    time_t now;
    struct tm *t;
    //t=(struct tm*)malloc(sizeof(struct tm));
    time(&now);
    t=localtime(&now);
    strftime(T[i].ordered_time,80,"%I:%M%p",t);
    //printf("\n**%s**\n",T[i].ordered_time);
    int k,j;
    if(i==0)
    {
        T[0].token=1;
        T[0].ordered_hour=t->tm_hour;
        T[0].ordered_minute=t->tm_min;
        k=ordertime(z);
        T[0].order=k;
    }
    else
    {
        T[i].token=T[i-1].token+1;
        T[i].ordered_hour=t->tm_hour;
        T[i].ordered_minute=t->tm_min;
        k=ordertime(z);
        if(T[i-1].ordered_minute>T[i].ordered_minute)
        { T[i].ordered_minute+=60;
           --T[i].ordered_hour;
        }
        j=T[i-1].order-(60*(T[i].ordered_hour-T[i-1].ordered_hour))+(T[i].ordered_minute-T[i-1].ordered_minute);
        T[i].order=k+j;
    }
}

int ordertime(int *z)
{
    int sum=0;
    if(*z!=0)
    {
        if(*z<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*z,r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+1)!=0)
    {
        if(*(z+1)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+1),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+2)!=0)
    {
        if(*(z+2)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+2),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+3)!=0)
    {
        if(*(z+3)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+3),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+4)!=0)
    {
        if(*(z+4)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+4),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+5)!=0)
    {
        if(*(z+5)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+5),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+6)!=0)
    {
        if(*(z+6)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+6),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+7)!=0)
    {
        if(*(z+7)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+7),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+8)!=0)
    {
        if(*(z+8)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+8),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    if(*(z+9)!=0)
    {
        if(*(z+9)<=4)
        {
            sum=sum+1;
        }
        else
        {
            int n=*(z+9),r;
            r=n/4;
            sum=sum+((n/4));
            if(r!=0)
                sum++;
        }
    }
    return sum;
}

void main_menu(int *z,char n)
{
    int m,a;
    printf("\nEnter the chatacter or number assigned to the item to select it\n");
	do
	{
		printf("\n[A]-Burgers\n[B]-Pizzas\n[C]-Puffs\n[D]-Cakes\n[F]-Pies\n[E]-Exit\n");
		scanf(" %c",&n);
		if(n=='A' || n=='a')
		{
			do
			{
				if(s->items[0]!=0)
				    printf("[1]-Veg Burger/Rs 40/(%d peice(s) Available)\n",s->items[0]);
				else
				    printf("[1]-Veg Burger(Not Available)\n");
				if(s->items[1]!=0)
				    printf("[2]-Non-Veg Burger/Rs 60/(%d peice(s) Available)\n",s->items[1]);
				else
				    printf("[2]-Non-Veg Burger(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);		
					if(m==1)
					{
					    if(s->items[0]!=0)
						{
						    printf("Enter number of Veg Burger(s)\n");
						    scanf("%d",&a);
						    if(a<=s->items[0] && a>0)
						    {
						        *z+=a;
						        s->items[0]-=a;
						    }
						    else if(a>s->items[0])
						        printf("You have entered more than available\n");
						    else
						        printf("*****Enter a valid input*****\n");
						}
						else
						    printf("Veg Burgers are not available\n");
					}
					else if(m==2)
					{
					    if(s->items[1]!=0)
						{
						    printf("Enter number of Non-Veg Burger(s)\n");
						    scanf("%d",&a);
						    if(a<=s->items[1] && a>0)
						    {
						        *(z+1)+=a;
						        s->items[1]-=a;
						    }
						    else if(a>s->items[1])
					            printf("You have entered more than available\n");
					        else
					            printf("*****Enter a valid input*****\n");
						}
						else
					        printf("Non-Veg Burgers are not available\n");
					}
					else if(m==0)
					{}
					else
					    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='B' || n=='b')
		{
			do
			{
				if(s->items[2]!=0)
				    printf("[1]-Veg Pizza/Rs 70/(%d peice(s) Available)\n",s->items[2]);
				else
				    printf("[1]-Veg Pizza(Not Available)\n");
				if(s->items[3]!=0)
				    printf("[2]-Non-Veg Pizza/Rs 100/(%d peice(s) Available)\n",s->items[3]);
				else
				    printf("[2]-Non-Veg Pizza(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(s->items[2]!=0)
				    {
				        printf("Enter number of Veg Pizza(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[2] && a>0)
					    {
					        *(z+2)+=a;
					        s->items[2]-=a;
					    }
					    else if(a>s->items[2])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Veg Pizzas are not available\n");
				}
				else if(m==2)
				{
					 if(s->items[3]!=0)
				    {
				        printf("Enter number of Non-Veg Pizza(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[3] && a>0)
					    {
					        *(z+3)+=a;
					        s->items[3]-=a;
					    }
					    else if(a>s->items[3])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Non-Veg Pizzas are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='C'|| n=='c')
		{
			do
			{
			    if(s->items[4]!=0)
				    printf("[1]-Veg Puff/Rs 30/(%d peice(s) Available)\n",s->items[4]);
				else
				    printf("[1]-Veg Puff(Not Available)\n");
				if(s->items[5]!=0)
				    printf("[2]-Egg Puff/Rs 35/(%d peice(s) Available)\n",s->items[5]);
				else
				    printf("[2]-Egg Puff(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[4]!=0)
				    {
				        printf("Enter number of Veg Puff(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[4] && a>0)
					    {
					        *(z+4)+=a;
					        s->items[4]-=a;
					    }
					    else if(a>s->items[4])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Veg Puffs are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[5]!=0)
				    {
				        printf("Enter number of Egg Puff(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[5] && a>0)
					    {
					        *(z+5)+=a;
					        s->items[5]-=a;
					    }
					    else if(a>s->items[5])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Egg Puffs are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='D'|| n=='d')
		{
			do
			{
				if(s->items[6]!=0)
				    printf("[1]-Blue berry cake/Rs 60/(%d peice(s) Available)\n",s->items[6]);
				else
				    printf("[1]-Blue berry cake(Not Available)\n");
				if(s->items[7]!=0)
				    printf("[2]-Cherry cake/Rs 75/(%d peice(s) Available)\n",s->items[7]);
				else
				    printf("[2]-Cherry cake(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[6]!=0)
				    {
				        printf("Enter number of Blue berry cake(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[6] && a>0)
					    {
					        *(z+6)+=a;
					        s->items[6]-=a;
					    }
					    else if(a>s->items[6])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Blue berry cakes are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[7]!=0)
				    {
				        printf("Enter number of Cherry cake(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[7] && a>0)
					    {
					        *(z+7)+=a;
					        s->items[7]-=a;
					    }
					    else if(a>s->items[7])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Cherry cake(s) are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='F'|| n=='f')
		{
			do
			{
				if(s->items[8]!=0)
				    printf("[1]-Cherry Pie/Rs 45/(%d peice(s) Available)\n",s->items[8]);
				else
				    printf("[1]-Cherry Pie(Not Available)\n");
				if(s->items[9]!=0)
				    printf("[2]-Apple Pie/Rs 55/(%d peice(s) Available)\n",s->items[9]);
				else
				    printf("[2]-Apple Pie(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[8]!=0)
				    {
				        printf("Enter number of Cherry Pie(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[8] && a>0)
					    {
					        *(z+8)+=a;
					        s->items[8]-=a;
					    }
					    else if(a>s->items[8])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Cherry Pies are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[9]!=0)
				    {
				        printf("Enter number of Apple Pie(s)\n");
					    scanf("%d",&a);
					    if(a<=s->items[9] && a>0)
					    {
					        *(z+9)+=a;
					        s->items[9]-=a;
					    }
					    else if(a>s->items[9])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Apple Pies are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='e')
		    break;
		else if(n=='E')
		{}
		else
		    printf("*****Enter a valid input*****\n");
	}while(n!='E');
}

int billing(float q,int *z)
{
	if(*z!=0)
	{printf("Veg Burger(s) %d=%d\n",*z,*z *40);
		q=q+(*z *40);
	}
	if(*(z+1)!=0)
	{printf("Non-Veg Burgers %d=%d\n",*(z+1),*(z+1) *60);
		q=q+(*(z+1) *60);
	}
	if(*(z+2)!=0)
	{printf("Veg Pizza %d=%d\n",*(z+2),*(z+2) *70);
		q=q+(*(z+2) *70);
	}
	if(*(z+3)!=0)
	{printf("Non-Veg Pizza %d=%d\n",*(z+3),*(z+3) *100);
		q=q+(*(z+3) *100);
	}
	if(*(z+4)!=0)
	{printf("Veg Puff %d=%d\n",*(z+4),*(z+4) *30);
		q=q+(*(z+4) *30);
	}
	if(*(z+5)!=0)
	{printf("Egg Puff %d=%d\n",*(z+5),*(z+5) *35);
	q=q+(*(z+5) *35);
	}
	if(*(z+6)!=0)
	{printf("Blue Berry cake %d=%d\n",*(z+6),*(z+6) *60);
	q=q+(*(z+6) *60);
	}
	if(*(z+7)!=0)
	{printf("Cherry cake %d=%d\n",*(z+7),*(z+7) *75);
	q=q+(*(z+7) *75);
	}
	if(*(z+8)!=0)
	{printf("Cherry pie %d=%d\n",*(z+8),*(z+8) *45);
	q=q+(*(z+8) *45);
	}
	if(*(z+9)!=0)
	{printf("Apple Pie %d=%d\n",*(z+9),*(z+9) *55);
	q=q+(*(z+9) *55);
	}
	return q;
}

void print(int x,float total)
{
	printf("\t YOUR BILL\n");
	printf("Total=%d\n",x);
	printf("GST 5%%=%f\n",(float)(5*x)/100);
	printf("Service Tax 1%%=%f\n",(float)(x)/100);
	total=(float)x+((float)(6*x)/100);
	printf("Grand total=%f\n",total);
	printf("\n\n");
}

void add(int *z)
{
    char n;int a,m;
   printf("\nEnter the chatacter or number assigned to the item to select it\n");
	do
	{
		printf("\n[A]-Burgers\n[B]-Pizzas\n[C]-Puffs\n[D]-Cakes\n[F]-Pies\n[E]-Exit\n");
		scanf(" %c",&n);
		if(n=='A' || n=='a')
		{
			do
			{
				if(s->items[0]!=0)
				    printf("[1]-Veg Burger/Rs 40/(%d peices Available)\n",s->items[0]);
				else
				    printf("[1]-Veg Burger(Not Available)\n");
				if(s->items[1]!=0)
				    printf("[2]-Non-Veg Burger/Rs 60/(%d peices Available)\n",s->items[1]);
				else
				    printf("[2]-Non-Veg Burger(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);		
					if(m==1)
					{
					    if(s->items[0]!=0)
						{
						    printf("Enter number of Veg Burgers\n");
						    scanf("%d",&a);
						    if(a<=s->items[0] && a>0)
						    {
						        *z+=a;
						        s->items[0]-=a;
						    }
						    else if(a>s->items[0])
						        printf("You have entered more than available\n");
						    else
						        printf("*****Enter a valid input*****\n");
						}
						else
						    printf("Veg Burgers are not available\n");
					}
					else if(m==2)
					{
					    if(s->items[1]!=0)
						{
						    printf("Enter number of Non-Veg Burgers\n");
						    scanf("%d",&a);
						    if(a<=s->items[1] && a>0)
						    {
						        *(z+1)+=a;
						        s->items[1]-=a;
						    }
						    else if(a>s->items[1])
					            printf("You have entered more than available\n");
					        else
					            printf("*****Enter a valid input*****\n");
						}
						else
					        printf("Non-Veg Burgers are not available\n");
					}
					else if(m==0)
				    {}
					else
					    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='B' || n=='b')
		{
			do
			{
				if(s->items[2]!=0)
				    printf("[1]-Veg Pizza/Rs 70/(%d peices Available)\n",s->items[2]);
				else
				    printf("[1]-Veg Pizza(Not Available)\n");
				if(s->items[3]!=0)
				    printf("[2]-Non-Veg Pizza/Rs 100/(%d peices Available)\n",s->items[3]);
				else
				    printf("[2]-Non-Veg Pizza(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(s->items[2]!=0)
				    {
				        printf("Enter number of Veg Pizzas\n");
					    scanf("%d",&a);
					    if(a<=s->items[2] && a>0)
					    {
					        *(z+2)+=a;
					        s->items[2]-=a;
					    }
					    else if(a>s->items[2])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Veg Pizza are not available\n");
				}
				else if(m==2)
				{
					 if(s->items[3]!=0)
				    {
				        printf("Enter number of Non-Veg Pizzas\n");
					    scanf("%d",&a);
					    if(a<=s->items[3] && a>0)
					    {
					        *(z+3)+=a;
					        s->items[3]-=a;
					    }
					    else if(a>s->items[3])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Non-Veg Pizza are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='C' || n=='c')
		{
			do
			{
			    if(s->items[4]!=0)
				    printf("[1]-Veg Puff/Rs 30/(%d peices Available)\n",s->items[4]);
				else
				    printf("[1]-Veg Puff(Not Available)\n");
				if(s->items[5]!=0)
				    printf("[2]-Egg Puff/Rs 35/(%d peices Available)\n",s->items[5]);
				else
				    printf("[2]-Egg Puff(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[4]!=0)
				    {
				        printf("Enter number of Veg Puff\n");
					    scanf("%d",&a);
					    if(a<=s->items[4] && a>0)
					    {
					        *(z+4)+=a;
					        s->items[4]-=a;
					    }
					    else if(a>s->items[4])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Veg Puff are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[5]!=0)
				    {
				        printf("Enter number of Egg Puff\n");
					    scanf("%d",&a);
					    if(a<=s->items[5] && a>0)
					    {
					        *(z+5)+=a;
					        s->items[5]-=a;
					    }
					    else if(a>s->items[5])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Egg Puff are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='D' || n=='d')
		{
			do
			{
				if(s->items[6]!=0)
				    printf("[1]-Blue berry cake/Rs 60/(%d peices Available)\n",s->items[6]);
				else
				    printf("[1]-Blue berry cake(Not Available)\n");
				if(s->items[7]!=0)
				    printf("[2]-Cherry cake/Rs 75/(%d peices Available)\n",s->items[7]);
				else
				    printf("[2]-Cherry cake(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[6]!=0)
				    {
				        printf("Enter number of Blue berry cakes\n");
					    scanf("%d",&a);
					    if(a<=s->items[6] && a>0)
					    {
					        *(z+6)+=a;
					        s->items[6]-=a;
					    }
					    else if(a>s->items[6])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Blue berry cake are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[7]!=0)
				    {
				        printf("Enter number of Cherry cake\n");
					    scanf("%d",&a);
					    if(a<=s->items[7] && a>0)
					    {
					        *(z+7)+=a;
					        s->items[7]-=a;
					    }
					    else if(a>s->items[7])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Cherry cake are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='F' || n=='f')
		{
			do
			{
				if(s->items[8]!=0)
				    printf("[1]-Cherry Pie/Rs 45/(%d peices Available)\n",s->items[8]);
				else
				    printf("[1]-Cherry Pie(Not Available)\n");
				if(s->items[9]!=0)
				    printf("[2]-Apple Pie/Rs 55/(%d peices Available)\n",s->items[9]);
				else
				    printf("[2]-Apple Pie(Not Available)\n");
				printf("[0]-EXIT\n");
				scanf("%d",&m);
				if(m==1)
				{
					if(s->items[8]!=0)
				    {
				        printf("Enter number of Cherry Pie\n");
					    scanf("%d",&a);
					    if(a<=s->items[8] && a>0)
					    {
					        *(z+8)+=a;
					        s->items[8]-=a;
					    }
					    else if(a>s->items[8])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Cherry Pie are not available\n");
				}
				else if(m==2)
				{
				    if(s->items[9]!=0)
				    {
				        printf("Enter number of Apple Pie\n");
					    scanf("%d",&a);
					    if(a<=s->items[9] && a>0)
					    {
					        *(z+9)+=a;
					        s->items[9]-=a;
					    }
					    else if(a>s->items[9])
					        printf("You have entered more than available\n");
					    else
					        printf("*****Enter a valid input*****\n");
				    }
				    else
				        printf("Apple Pie are not available\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='e')
		    break;
		else if(n=='E')
		{}
		else 
		    printf("*****Enter a valid input*****\n");
	}while(n!='E');
}

void delete(float q,int *z)
{
    printf("Your's selected list\n");
    billing(q,z);
    char n;int a,m;
    printf("\nEnter the chatacter or number assigned to the item to deselect it\n");
	do
	{
		printf("\n[A]-Burger\n[B]-Pizza\n[C]-Puff\n[D]-Cake\n[F]-Pie\n[E]-Exit\n");
		scanf(" %c",&n);
		if(n=='A'|| n=='a')
		{
			do
			{
				printf("1-Veg Burger/Rs 40/\n2-Non-Veg Burger/Rs 60/\n0-exit\n");
				scanf("%d",&m);		
					if(m==1)
					{
					    if(*z!=0)
						{
						    printf("Enter number of Veg Burgers to be removed\n");
						    scanf("%d",&a);
						    if(a<=*z && a>0)
						    {
						        *z-=a;
						        s->items[0]+=a;
						    }
						    else
						        printf("Invalid\n");
					    }
						else
						    printf("This item is not in your list\n");
					}
					else if(m==2)
					{
					    if(*(z+1)!=0)
						{
						    printf("Enter number of Non-Veg Burgers to be removed\n");
						    scanf("%d",&a);
						    if(a<=*(z+1) && a>0)
						    {
						        *(z+1)-=a;
						        s->items[1]+=a;
						    }
						    else
						        printf("Invalid\n");
						}
						else
						    printf("This item is not in your list\n");
					}
					else if(m==0)
				    {}
					else
					    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='B' || n=='b')
		{
			do
			{
				printf("1-Veg Pizza/Rs 70/\n2-Non-Veg Pizza/Rs 100/\n0-Exit\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(*(z+2)!=0)
					{printf("Enter number of Veg Pizzas to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+2) && a>0)
					{
					    *(z+2)-=a;
					    s->items[2]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==2)
				{
				    if(*(z+3)!=0)
					{printf("Enter number of Non-Veg Pizzas to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+3) && a>0)
					{
					    *(z+3)-=a;
					    s->items[3]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='C' || n=='c')
		{
			do
			{
				printf("1-Veg Puff/Rs 30/\n2-Egg Puff/Rs 35/\n0-Exit\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(*(z+4)!=0)
					{printf("Enter number of Veg Puffs to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+4) && a>0)
					{
					    *(z+4)-=a;
					    s->items[4]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==2)
				{
				    if(*(z+5)!=0)
					{printf("Enter number of Egg Puffs to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+5) && a>0)
					{
					    *(z+5)-=a;
					    s->items[5]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='D' || n=='d')
		{
			do
			{
				printf("1-Blue Berry Cakes/Rs 60/\n2-Cherry Cakes/Rs 75/\n0-Exit\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(*(z+6)!=0)
					{printf("Enter number of Blue Berry Cakes to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+6) && a>0)
					{
					    *(z+6)-=a;
					    s->items[6]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==2)
				{
				    if(*(z+7)!=0)
					{printf("Enter number of Cherry Cakes to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+7) && a>0)
					{
					    *(z+7)-=a;
					    s->items[7]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='F'|| n=='f')
		{
			do
			{
				printf("1-Cherry Pie/Rs 45/\n2-Apple Pie/Rs 55/\n4-Exit\n");
				scanf("%d",&m);
				if(m==1)
				{
				    if(*(z+8)!=0)
					{printf("Enter number of Cherry Pies to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+8) && a>0)
					{
					    *(z+8)-=a;
					    s->items[8]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==2)
				{
				    if(*(z+9)!=0)
					{printf("Enter number of Apple Pies to be removed\n");
					scanf("%d",&a);
					if(a<=*(z+9) && a>0)
					{
					    *(z+9)-=a;
					    s->items[9]+=a;
					}
					else
					printf("Invalid\n");
					}
					else
					printf("This item is not in your list\n");
				}
				else if(m==0)
				{}
				else
				    printf("*****Enter a valid input*****\n");
			}while(m!=0);
		}
		else if(n=='e')
		    break;
		else if(n=='E')
		{}
		else
		    printf("*****Enter a valid input*****\n");
	}while(n!='E');
}
