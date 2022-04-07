//1)what is the output and why 

int func(int x)
{
    if(x==0)
        return 0;
    else
    {
        printf("%d",x);
        func(x--);
    }
}
int main()
{
   int x=5;
   func(x);

    return 0;
}

//2)what is the output ( it will be the same on embedded target ?)

   int i,arr[5];
   for(i=0;i<=5;i++)
   {
	   arr[i]=3;
	   printf("%d",arr[i]);
   }
   
//3)what is the output 

char*str="ahmed";
str[2]='k';
printf("%s",str);

//4)what is the output 

char str[]="ahmed";
str[2]='k';
printf("%s",str);

//5)what is the output 

char*str1="ahmed";
char*str2=str1;
str1="mohamed";
printf("%s--%s",str1,str2);


//6)what is the output   (why this one works ?)

char str1[]="ahmed";
char *str2=str1;
str2[2]='k';
printf("%s--%s",str1,str2);
  
//7)what is the output 

int a=5,b;
b=a++ + ++a;
printf("%d,%d",a,b);

//8)what is the output 

int x, arr[5]={1,3,5,7,9};
int *p=arr;
x=*p++;
printf("%d,%d",x,*p);

//9)what is the output 

printf("%d,%d,%d,%d",sizeof(5),sizeof(500),sizeof('5'),sizeof("5"));

//10)what is the output 

printf("%d,%d,%d",sizeof(3.14),sizeof(3.14f),sizeof("3.14"));

//11)what is the output

int x=1,y=1,z=1,k;
k= ++x || ++y && ++z;
printf("%d,%d,%d,%d",x,y,z,k);

//12)what is the output

int x=1,y=1,z=1,k;
k= ++x && ++y || ++z;
printf("%d,%d,%d,%d",x,y,z,k);

//13)what is the output

unsigned int i,size=5;
   for (i=size;i>=0;i--)
   {
       printf("%d",i);
   }

//14)what is the output

unsigned int i,size=5;
   for (i=size;i>0;i--);
   {
       printf("%d",i);
   }
    
 //15)what is the output  
 
int arr[] = {2.3, 3.5, 4, 5};
int *p;
int *q;
q = arr;
for(int i = 0; i < 5; i++){
	printf("%d", *arr);
	++*q;
}

 //16)what is the output  
 
#define max(a,b)  a>b?a:b
int main()
{
    int i=10,j=9,k;
    k=max(i++,++j);
    printf("%d,,%d,,%d",i,j,k);
}
