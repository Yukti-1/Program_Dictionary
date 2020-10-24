#include<stdio.h>
#include<stdlib.h>
// GENERIC QUEUE IMPLEMENTATION
typedef struct node
{
   void* data;
   struct node* next;
}node;

node* newnode()
{
  node* temp=(node*)malloc(sizeof(node));
  temp->next=NULL;
  return temp;
}

typedef struct queue
{
   node* front,*rear;
   int datasize;

}queue;



queue* create_generic_queue()
{
queue* temp=(queue*)malloc(sizeof(queue));
temp->front=NULL;
temp->rear=NULL;
return temp;
}

void enqueue_gen(void* data,queue* Q)
{
    node* temp=newnode();
    temp->data=malloc(Q->datasize);
    /// copies value from the location of data to temp->data
    memcpy(temp->data,data,Q->datasize);
    if(Q->front==NULL) //if queue is empty
    {
        Q->front=temp;
    }
    else
    {
        Q->rear->next=temp;
    }
    Q->rear=temp;
    printf("Enqueue operation done\n");

}

void* dequeue_gen(queue* Q)
{
    if(Q->front==NULL)
    {
        printf("Queue is Empty SO Dequeue Unsuccessful!\n");
    }
    else
    {
        node* temp=Q->front;
        Q->front=Q->front->next;
        void* data=temp->data;

        free(temp);
        if(Q->front==NULL)
        {
            Q->rear=NULL;
        }
        printf("Element dequeued successfully!!: ");
        return data;

    }
}

int is_gen_queue_empty(queue* Q)
{
    if (Q->front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void free_gen_queue(queue* Q)
{
    node* temp=Q->front;
    node* p;
    while(temp!=NULL)
    {
        p=temp;
        free(p);
        temp=temp->next;
    }
}
int main()
{
   queue* Q=create_generic_queue();
   // IMPLEMENTING AN INTEGER QUEUE USING GENERIC QUEUE
   Q->datasize=sizeof(int);


   while(1)
   {

       int* value;
       int val;
       int option,count=0;
       int k=0;
       void* pointer;
       node* t=newnode();
       printf("Enter a number for the following operations:\n1 - to enqueue\n2- to dequeue\n3 - to check is empty\n4 -number of elements in queue\n5 - to print queue\n");
       scanf("%d",&option);

       switch(option)
       {
           case 1:
             printf("Enter the value to be enqueued\n");
             scanf("%d",&val);
             value=&val;
             enqueue_gen((void*)value,Q);
             break;

          case 2:
          pointer=dequeue_gen(Q);
          printf("Element dequeued is : %d\n",*((int*)pointer));
          break;

          case 3:
          value=is_gen_queue_empty(Q);
          if (value==1)
          {
              printf("Queue is empty\n");
          }
          else
          {
              printf("Queue is not empty\n");
          }

          case 4:

          t=Q->front;
          count=0;
          printf("No. of elements in queue are as follows: ");
          while(t!=NULL)
          {
              count++;
              t=t->next;
          }
          printf("%d\n",count);
          break;

          case 5:
          t=Q->front;
          printf("The elements of queue are as follows:\n");
          while(t!=NULL)
          {
              printf("%d -> ",*((int*)t->data));
              t=t->next;
          }
          printf("\n");
          break;

          default:
          printf("Invalid option\n");
          break;
     }

   }
}

