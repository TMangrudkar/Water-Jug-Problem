// 60-Tilak Mangrudkar
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int x;
	int y;
};
int main()
{
	int a,b;
	int r,s,k;
	int flag=0;
	int found=0;
	int m,n,l=0,j;
	printf("Enter the capacity\n");
	scanf("%d%d",&a,&b);
	int p,q;
	printf("Enter the goal state\n");
	scanf("%d%d",&p,&q);
	int top=0;
	struct node arr[20];
	int i=0;
	arr[top].x=0;
	arr[top].y=0;
	struct node visited[20];
	printf("The path to obtain the goal state is\n");
	while(top!=-1)
	{
		
		m=arr[top].x;
		n=arr[top].y;
		visited[i].x=m;
		visited[i].y=n;
		i++;
		printf("%d	%d\n",m,n);
		top=top-1;
		if(m==p && n==q)
		{
			found=1;
			break;
		}		
		for(l=0;l<6;l++)
		{
			r=m;
			s=n;
			if(l==0)
			{
				r=0;
				s=s;
			}
			if(l==1)
			{
				r=r;
				s=0;
			}
			if(l==2)
			{
				if(r==0)
				{
					r=a;
					s=s;
				}
			}
			if(l==3)
			{
				if(s==0)
				{
					r=r;
					s=b;
				}
			}
			if(l==4)
			{
				r=r+s;
				s=s-s;
				if(r>a)
				{
					r=m+(a-m);
					s=n-(a-m);
				}	
			}
			if(l==5)
			{
				r=r-r;
				s=s+r;
				if(s>b)
				{
					r=m-(b-n);
					s=n+(b-n);
				}
			}
			for(j=0;j<i;j++)
			{
				if(r==visited[j].x && s==visited[j].y)
				{
					flag=1;
				}
			}		
			if(flag==0)
			{
				top++;
				arr[top].x=r;
				arr[top].y=s;	
			}
			flag=0;	
		}	
	}
	if(found==0)
	{
		printf("Goal State Cannot Be Obtained\n");
	}	
}
