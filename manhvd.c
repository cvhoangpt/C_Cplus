#include <stdio.h>
#include <conio.h>

//Color list
void colourandStyles(FILE *f,int a)
{
	if(a==1){
		fprintf(f,"[fillcolour=red, style=filled];");
	}
	else if(a==2){
		fprintf(f,"[fillcolour=green, style=filled];");
	}
	else if(a==3){
		fprintf(f,"[fillcolour=blue; style=filled];");
	}
	else if(a==4){
		fprintf(f,"[fillcolour=pink, style=filled];");
	}
	else if(a==5){
		fprintf(f,"[fillcolour=yellow, style=filled];");
	}
	else if(a==6){
		fprintf(f,"[fillcolour=violet, style=filled];");
	}
	else if(a==6){
		fprintf(f,"[fillcolour=violet, style=filled];");
	}
	else if(a==7){
		fprintf(f,"[fillcolour=white, style=filled];");
	}
	else{
		fprintf(f,"[fillcolour=silver, style=filled];");
	}
		fprintf(f,"\n");
}

//Read file data
//read file from data
void readfileData(FILE *fileIn,int top,int edge,int **a)
{
	for(int i=0;i<edge;i++)
	{
		fscanf(fileIn,"%d %d",&a[0][i],&a[1][i]);
	}
}

//ArrayOut
void arrayOut(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}

//
char interConnected(int **A,int n) 
{
	char*check = new char [n];
	char success;
	int count=0;
	for(int i = 0; i<n; i++)			//Kh?i t?o m?i d?nh chua du?c dánh d?u
		check[i] = 0;
	check[0] = 1;			//Ðánh d?u d?nh d?u
	count++;				//Ð?m s? d?nh dã dánh d?u là 1
	do 
	{	
		success =1;		//Gi? s? không còn kh? nang loang
		for(int i = 0; i<n; i++)
			if(check[i]==1) 
			{
				for(int j = 0; j<n; j++)
					if (check[j] == 0 && A[i][j] > 0) 
					{
						check[j] = 1;
						success = 0;	//Th?c t? còn kh? nang loang
						count++;
						if(count == n) return 1;
					}
			}
	}
	while (success == 0);	//L?p l?i cho d?n khi không còn kh? nang loang
	return 0;
}

//Delete one element in detail position
void deleteNumber(int a[],int &n,int pos)
{
	for(int i=pos;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}

//Swap 2 elements
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

//Array sorting (quickSort)
void quickSort(int *a,int L,int R)
{
	int i=L,j=R;
	int x=a[(L+R)/2]; 
	do
	{
		while(a[i]>x) i++;      
		while(a[j]<x) j--;        
		if(i<=j)
		{                      
			swap(a[i],a[j]);  
			i++; j--;             
		}
	}
	while(i<=j);                         
	if(L<j) quickSort(a,L,j);
	if(i<R) quickSort(a,i,R);
}

//Funtion that print some different elements of array desending
void handlingArr(int *a,int &n)
{
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]==a[i])
			{
				deleteNumber(a,n,j);
				i--;
			}
		}
	}
}

//Check x, y that together in 2 dimen-arr
int checkColumn(int **a,int top,int edge,int x,int y){
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<edge;j++)
		{
			if(a[0][j]==x&&a[1][j]==y)
			{
				return 1;
			}
			if(a[0][j]==y&&a[1][j]==x)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int top,edge;
	
	FILE *fileIn=fopen("E:\\dothi123.txt","r");
	fscanf(fileIn,"%d",&top);
	fscanf(fileIn,"%d",&edge);
	
	int **a=new int*[2];// initialization
	for(int i=0;i<2;i++) a[i]=new int[edge];
	
	readfileData(fileIn,top,edge,a);
	
	//create matrix
	int **Matrix=new int*[top];
	for(int i=0;i<top;i++) Matrix[i]=new int[top];

	for(int i=1;i<=top;i++)
	{
		for(int j=1;j<=top;j++)
		{
			if(checkColumn(a,top,edge,i,j))
			{
				Matrix[i-1][j-1]=1;
			}
			else Matrix[i-1][j-1]=0;
		}
	}

	//array c contains vertices
	int indexc=0;
	int *c=new int[indexc];
	
	for(int i=1;i<=top;i++)
	{
		int count=0;
		for(int j=0;j<2;j++)
			for(int k=0;k<edge;k++)
			{
				if(i==a[j][k]) count++;
			}
		c[indexc++]=count;
	}

	//create a 2-dimensional array with lines 1 as vertices, line 2 containing the corresponding frequencies of vertices
	int **b=new int*[2];
	for(int i=0;i<2;i++)
	{
		b[i]=new int [top];
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<top;j++)
		{
			b[0][j]=i+1;
			b[1][j]=c[i++];
		}
	}

	//array d saves the different elements of the array c in a non-incremental order
	int indexd=0;
	int *d=new int[indexd];
	
	for(int i=0;i<top;i++)
	{
		d[indexd++]=b[1][i];
	}
	
	handlingArr(d,indexd);

	//greedy algorithm
	int idx=0;
	int *topOrder=new int[idx];
	for(int i=0;i<indexd;i++)
	{
		for(int j=0;j<top;j++)
		{
			if(b[1][j]==d[i])
			{
				topOrder[idx++]=b[0][j];
			}
		}
	}

	int *color=new int[top];
	int *check=new int[top];
	
	color[topOrder[0]]=1;
	for(int i=1;i<idx;i++)
	{
		for(int k=0;k<top;k++) check[k]=1;
		for(int j=0;j<=i-1;j++) if(Matrix[topOrder[i]-1][topOrder[j]-1]==1) check[color[topOrder[j]]]=0;
			
	}
	for(int m=1;;m++) if(check[m]==1)
		{
			color[topOrder[i]]=m;																	
			break;
		}
	
	//In ra file .dot
	FILE *fileOut=fopen("dothitomau1.dot","w");
	fprintf(fileOut,"graph dothi\n{\n");
	for(int i=0;i<top;i++)
	{
		fprintf(fileOut,"\t%d ",topOrder[i]);
		ColourAndStyles(fileOut,color[topOrder[i]]);
		if(i==top-1) break;
	}

	for(int j=0;j<edge;j++)
	{
		fprintf(fileOut,"\t%d -- %d",a[0][j],a[1][j]);
		fprintf(fileOut,"\n");
	}
	fprintf(fileOut,"}");

	//Close file
	fclose(fileIn);
	fclose(fileOut);
	getch();
	return 0;
}
