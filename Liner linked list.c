#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
void append();
void display();
int length(struct node*);
void Add_At_Begin();
void Add_At_position();
void delete();
void short_assending();
void short_dessinding();
struct node* root=NULL;
int main()
{
	int ch;
	while(1)
	{
		printf("\nLiner link list operation\n");
		printf("Press 1 for append\n");
		printf("Press 2 for display\n");
		printf("Press 3 for length\n");
		printf("Press 4 for Add_At_Begin\n");
		printf("Press 5 for  Add_At_position\n");
		printf("Press 6 for  delete\n");
		printf("press 7 for shorting assending\n");
		printf("press 8 for shorting dessinding\n");
		printf("Press 0 for  exit\n");
		printf("\nEnter your choise:");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				append();
				break;
			case 2:
				display();
				break;
			case 3:
				length(root);
			    break;
			case 4:
				 Add_At_Begin();
				 break;
			case 5:
				Add_At_position();
				break;
			case 6:
			  delete();
				break;
			case 7:
				short_assending();
				break;
			case 8:
				short_dessinding();
				break;
	    	case 0:
				exit (0);
			default :
				printf("Please enter a valid input\n"); 
			     	
		}
	}
	return 0;
}
void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
	struct node* p=root;
	while(p->link!=NULL)
    	{
		p=p->link;
    	}	
    	p->link=temp;
	}
}
void display()
{
  	struct node* p=root;
	if(root==NULL)
	{
		printf("List is empty\n");
	}	
	else
	{
		while(p!=NULL)
		{
			printf("%d\t",p->data);
	    	p=p->link;
		}
	}
}
int length(struct node* p)
{
  int count = 0;
   while(p!=NULL)
      {
       	count++;
       	p=p->link;
      }
    printf("%d",count);
	return count;   
}
 void Add_At_Begin()
 {
 	struct node* temp;
 	temp=(struct node*)malloc(sizeof(struct node*));
 	printf("Enter the data:");
 	scanf("%d",&temp->data);
 	temp->link=NULL;
 	if(root==NULL)
 	{
 	 root=temp;	
	}
	else
	{
		temp->link=root;
		root=temp;       
	}
 }
 void Add_At_position()
{
	struct node* p=root,*temp;
	int pos,len,i=1;
	printf("Enter the position: ");
	scanf("%d",&pos);
	len=length(root);
	if(pos>len)
	{
		printf ("Invalid position\n");
		printf("Currently you having %d nodes\n",len);
	}
	else
	{
	  while(i<pos-1)
	  {
	  	p=p->link;
	  	i++;
	  }
    temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data:");
 	scanf("%d",&temp->data);
 	temp->link=NULL;
 	temp->link=p->link;
 	p->link=temp;
	}
}
void delete()
{
	struct node* temp;
	int pos,len;
	printf("Enter the position to delet the node: ");
	scanf("%d",&pos);
	len=length(root);
	if(pos>len)
	{
		printf ("Invalid position\n");
		printf("Currently you having %d nodes\n",len);
	}
	else if(pos==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else if(pos==len)
	{
		struct node* temp=root,*p;
		while(p->link!=NULL)
		{
			p = temp;
			temp = p->link;
		}
		p->link=NULL;
		free(temp);
	}
	else
	{
		int i=1; 
		struct node* p=root,*q=NULL,* r=NULL;
		while(i<pos)
		{
			q=p;
			p=p->link;
			i++;
		}
	    r=p->link;
		p->link=NULL;
		q->link=r;
		free(p);
	}
}
void short_assending()
{
	struct node* p,*q;
	int swap;
	
	for(p=root;p->link!=NULL;p=p->link)
	{
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(p->data>q->data)
			{
				swap=p->data;
				p->data=q->data;
				q->data=swap;
			}
		}
	}
}
void short_dessinding()
{
	struct node* p,*q;
	int swap;
	
	for(p=root;p->link!=NULL;p=p->link)
	{
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(p->data<q->data)
			{
				swap=p->data;
				p->data=q->data;
				q->data=swap;
			}
		}
	}
}












