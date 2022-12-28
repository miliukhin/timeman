#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct clothes{
	int id;
	char name[20];
	int size;
	int p1;
};
int getnum()//scan number of clothes
{
	int i;
	FILE *fp=fopen("in.txt","r");
	fscanf(fp,"%d",&i);
	fclose(fp);
	return i;
}
void cngnum(int i)//change number of clothes
{
	FILE *fp=fopen("in.txt","w");
	fprintf(fp,"%d",i);
	fclose(fp);
}
struct clothes *readstruc(struct clothes *c)//read arr structures from file
{
	FILE *fptr = fopen("bin.bin","rb");
	fread(c,sizeof(c[0])*getnum(), 1, fptr);
	fclose(fptr);
	return c;
};
void cngstructure(struct clothes *c)//write to file struct
{
	FILE *fptr = fopen("bin.bin","wb");
	fwrite(c,sizeof(c[0])*getnum(), 1, fptr);
	fclose(fptr);
};
void print(struct clothes *c)
{
	int i=getnum();
	//print structure
	for (int j=0;j<i;j++)
	{
	 printf("%d)ID=%d\tName=%s\tsize=%d\tprice=%d\n",j+1, c[j].id,c[j].name,c[j].size,c[j].p1);
	}
}
void add(struct clothes *c)
{
	int i=getnum();
	printf("%d\n",i);
	cngnum(++i);
	//adding new structure
	printf("Enter id:");
	scanf("%d",  &c[i-1].id);
	printf("Enter name: ");
	scanf("%s", c[i-1].name);
	printf("Enter size:");
	scanf("%d", &c[i-1].size);
	printf("Enter price: ");
	scanf("%d", &c[i-1].p1);
	cngstructure(c);
}
void del(struct clothes *c){
	int i=getnum();
	// choosing element
	int a;
	printf("Enter id:");
	scanf("%d", &a);
	for(int j=0;j<i;j++)
	{
		if(c[j].id==a)
		{
			printf("your cloth was found\n");
			for(int l=0;l<i-j;l++)
			{
				c[j+l]=c[j+l+1];
			}
			i--;
			cngnum(i);
			printf("Deleting done\n");
			break;
		}
	}
	cngstructure(c);
}
void sort(struct clothes *c, int n)
{
	printf("a to sort by id b to sort by price\n");
	char a[5];
	scanf("%s",&a);
	if(*a=='a'){
	for(int i=0;i<n;++i){
		int f=0;
		for(int j = 0;j < n-i-1; ++j){
		int dif;
		int c1 = c[j].id, c2 = c[j+1].id;
		if(c1==c2)continue;
		dif = c1 - c2;
		if(dif > 0)
			{
			 struct clothes p = c[j];
			 c[j] = c[j + 1];
			 c[j + 1] = p;
			 f++;
			}
		}
		if(f==0)break;
	}

	}
	if(*a=='b')
	{
		for(int i=0;i<n;++i){
		int f=0;
		for(int j = 0;j < n-i-1; ++j){
		int dif;
		int c1 = c[j].p1, c2 = c[j+1].p1;
		dif = c1 - c2;
		if(dif > 0)
			{
			 struct clothes p = c[j];
			 c[j] = c[j + 1];
			 c[j + 1] = p;
			 f++;
			}
		}
		if(f==0)break;
	}
	}
	cngstructure(c);
	print(c);
}
void find(struct clothes *c, int n)
{
	int siz;
	printf("Enter size:");
	scanf("%d",&siz);
	for(int i=0;i<n;i++)
	{
		if(c[i].size==siz)
		{
			printf("ID= %d\tName=%s\tsize=%d\tprice=%d\n", c[i].id,c[i].name,c[i].size,c[i].p1);
			break;
		}
	}

}
void change(struct clothes *c, int n)
{
	printf("a to change id b to change name");
	char a[5];
	int d;//id you are going to find
	int newid;
	char fn[20];//finding name
	char newname[20];
	scanf("%s",a);
	switch ( *a )
	{
	case 'a':

		scanf("%d",&d);
		for(int i=0;i<n;i++)
		{
			if(c[i].id == d)
			{
				printf("Your id found name %s\nEnter new id:",c[i].name);
				scanf("%d", &newid);
				c[i].id=newid;
			}
		}
	break;
	case 'b':
		scanf("%s",fn);
		for(int i=0;i<n;i++)
		{
			int flag=0;
			for(int j=0;j<strlen(c[i].name);j++)if(c[i].name[j] == fn[j])flag++;

			if(flag==strlen(c[i].name)){
			printf("Your name found id %d\nEnter new name:",c[i].id);
				scanf("%s", newname);
				strcpy(c[i].name,newname);
			}
		}
	}
	cngstructure(c);
}
int main(){
	int i=getnum();
	struct clothes c[i+10];
	readstruc(c);
	char q[5];
	printf("Enter a to append  c to change f to find p to show elements  s to sort element  d to delete element q to quit: \n");
	scanf("%s",q);
	switch ( q[0] ){
	case 'p':print(c); break;
	case 'a':add(c);break;
	case 'd':del(c);break;
	case 's':sort(c,i);break;
	case 'f':find(c,i);break;
	case 'c':change(c,i);break;
	case 'q':return 0;
	}
	main();
}

