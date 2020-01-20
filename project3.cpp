    #include<stdio.h>
    #include<stdlib.h>

    struct node
	{
        int data;
        struct node *next;
    };
    struct node *head;

    void Add(int veri){ 
        if(head==NULL)
		{
            head=(struct node *)malloc(sizeof(struct node )); 
            head->data=veri;
            head->next=NULL;
        }
        else
		{
            struct node *temp=head;
            struct node *temp1=(struct node *)malloc(sizeof(struct node ));
            temp1->data=veri;
            temp1->next=NULL;
            while(temp->next!=NULL)
                temp=temp->next;
                temp->next=temp1;
        }
    }
    
    void Print(){
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }


    void Delete(int key){ 
        if(head->data==key)
        {
            struct node *temp=head;
            head=head->next;
            free(temp);
        }
        else
        {
            struct node *temp=head;
            struct node *temp2;//silece?im dü?ümün adresi.
            while(temp->next->data!=key)
            {
                temp=temp->next;
            }
            temp2=temp->next;
            temp->next=temp2->next;
            free(temp2);
        }
	}
  
	int func1(int x){
	    int a= 10*x^100 + 5*x^14 + 1;
		return (a);
	}
	
	int func2(int x){
	    int a= 3*x^1990 + 2*x^1492 + 5;
		return (a);
	}
	
	//create the operations in the solutions.
	void addFunc(){
		struct node *temp=head;
		int deger=0;
		while(temp!=NULL)
        {
        	deger+=temp->data;
            temp=temp->next;
        }
        printf("%d\n",deger);
        return ;
	}
	
	void impactFunc(){
		struct node *temp=head;
		int deger=0;
		while(temp!=NULL)
        {
        	deger*=temp->data;
            temp=temp->next;
        }
        printf("%d\n",deger);
        return ;
	}  
main(){
	int x,y,a,b,z,selection1,selection2;
	int flag=0;
	while(flag==0){
		printf("\n1-Add\n2-Delete\n3-Multiplication\n4-Impact\n");
		scanf("%d",&selection1);
		
		if(selection1==1){
			printf("choose function 1 or 2?\n");
	        scanf("%d",&selection2);
    	    if(selection2==1){
    	        printf("for function1, x=?\n");
            	scanf("%d",&x);
    	        int f=func1(x);
    	        Add(f);
	        }
	        else if(selection2==2){
	            printf("for function2, x=?\n");
            	scanf("%d",&x);
            	int g=func2(x);
            	Add(g);
            } 
			Print();
		}
         
        else if(selection1==2){
	        printf("which data?\n1-func1?\n2func2?\nx?\n");
            scanf("%d %d %d",&a,&b);
            if(a==1){
                z=func1(b);
            }
            else{
		        z=func2(b);
	        }
            Delete(z);
            Print();        	
		}
   
        else if(selection1==3){
        	addFunc();
		} 
	
	    else if(selection1==4){
	    	impactFunc();
		}
		
		else{
			flag=1;
		}
    }
    return 0 ;
}
