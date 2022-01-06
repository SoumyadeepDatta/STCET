// Soumyadeep Datta, Roll 26
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>

#define MEM_SIZ 750


int id_val = 0; // keeps track of id of a process
int addr = 0;   // only used in init() to initialize start addresses 


// node of the linked list
struct node
{
    char type;
    int id;
    int startaddr;
    int size;
    struct node* next;
};

// global node variables
struct node *head,*temp=NULL,*newnode=NULL;

// initialize the memory layout
void init(){
    // head (1st)
    head = (struct node*)malloc(sizeof(struct node));
    head->type = 'P';
    head->id = id_val++;
    head->startaddr = addr;
    head->size = 50;
    addr = head->startaddr + head->size;
    head->next = NULL;
    
    temp = head;
    // 2nd
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->type = 'H';
    newnode->id = id_val++;
    newnode->startaddr = addr;
    newnode->size = 75;
    addr = newnode->startaddr + newnode->size;
    newnode->next=NULL;
    temp->next = newnode;
    temp = newnode;
    // 3rd
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->type = 'P';
    newnode->id = id_val++;
    newnode->startaddr = addr;
    newnode->size = 150;
    addr = newnode->startaddr + newnode->size;
    newnode->next=NULL;
    temp->next = newnode;
    temp = newnode;
    // 4th
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->type = 'H';
    newnode->id = id_val++;
    newnode->startaddr = addr;
    newnode->size = 175;
    addr = newnode->startaddr + newnode->size;
    newnode->next=NULL;
    temp->next = newnode;
    temp = newnode;
    // 5th
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->type = 'P';
    newnode->id = id_val++;
    newnode->startaddr = addr;
    newnode->size = 300;
    addr = newnode->startaddr + newnode->size;
    newnode->next=NULL;
    temp->next = newnode;
    temp = newnode;
    if (addr == MEM_SIZ)
    {
        printf("%dK initialized successfully\n",MEM_SIZ);
    }
    

}

//  number of times snapshot is showed (starts from 1)
int s = 0;

void display(struct node* n){
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("                                           SNAPSHOT %d                                              \n",++s);
    printf("----------------------------------------------------------------------------------------------------\n");
    struct node *t = n;
    // display type of the node
    printf("TYPE\t");
    while (t)
    {
        printf("%c\t",t->type);
        t = t->next;
    }
    printf("\n");
    // display id of the node
    printf("ID\t");
    t = n;
    while (t)
    {
        printf("%d\t",t->id);
        t = t->next;
    }
    printf("\n");
    // display start address of the node
    printf("SADDR\t");
    t = n;
    while (t)
    {
        printf("%d\t",t->startaddr);
        t = t->next;
    }
    printf("\n");
    // display size of the node
    printf("SIZE\t");
    t = n;
    while (t)
    {
        printf("%d\t",t->size);
        t = t->next;
    }
    printf("\n");
}

void first_fit(struct node* t, int val){
    temp = t;
    while (t)
    {
        if ((t->type == 'P' && t->next == NULL) || (t->type == 'H' && t->next == NULL && t->size < val))
        {
            printf("Holes aren't large enough to fit %dK process. So no change is made.\n",val);
            return;
        }
        
        if(t->type == 'H'){
            if (t->size >= val)
            {
                if (t == head)
                {
                    // add before head
                    newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->type = 'P';
                    newnode->id = id_val++;
                    newnode->startaddr = t->startaddr;
                    newnode->size = val;
                    t->startaddr = newnode->startaddr + newnode->size;
                    t->size -= newnode->size;
                    if (t->size == 0)
                    {
                        // no need to keep that node if size of the hole is 0
                        newnode->next = t->next;
                        head = newnode;
                        free(t);
                        return;
                    }
                    else{
                        newnode->next = t;
                        head = newnode;
                        return;
                    }
                }
                else
                {
                    newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->type = 'P';
                    newnode->id = id_val++;
                    newnode->startaddr = t->startaddr;
                    newnode->size = val;
                    t->startaddr = newnode->startaddr + newnode->size;
                    t->size -= newnode->size;
                    if (t->size == 0)
                    {
                        // no need of that hole if size of the hole is 0
                        temp->next = newnode;
                        temp = newnode;
                        temp->next = t->next;
                        free(t);
                        return;
                    }
                    else{
                        temp->next = newnode;
                        temp = newnode;
                        temp->next = t;
                        return;
                    }
                }
                
            }
            
            
        }
        temp = t;
        t = t->next;
    }
    
}

void best_fit(struct node* t, int val){
    int min = MEM_SIZ + 1;
    struct node * bf_node = NULL, *prev = NULL;    // best fit node (best fit hole)
    temp = t;
    while (t)
    {
        
        //  find a hole which is of least size in the entire memory
        if(t->type == 'H'){
            if (t->size >= val)
            {
                if (t->size <= min)
                {
                    min = t->size;
                    bf_node = t;
                    prev = temp;
                }
                
            }
        }

        //  here temp holds the previous node of t, each time t iterates
        temp = t;
        t = t->next;
    }

    // after iterating through the entire memory...
    if (min != MEM_SIZ + 1) 
    {
        if (bf_node == head)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->id = id_val++;
            newnode->type = 'P';
            newnode->startaddr = head->startaddr;
            newnode->size = val;
            head->startaddr = newnode->startaddr + newnode->size;
            head->size -= newnode->size;
            if (head->size == 0)
            {
                newnode->next = head->next;
                temp = head;
                head = newnode;
                free(temp);
                return;
            }
            else
            {
                newnode->next = head;
                head = newnode;
                return;
            }
            
            
        }
        else
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->id = id_val++;
            newnode->type = 'P';
            newnode->startaddr = bf_node->startaddr; 
            newnode->size = val;
            bf_node->startaddr = newnode->startaddr + newnode->size;
            bf_node->size -= newnode->size;
            if (bf_node->size == 0)
            {
                prev->next = newnode;
                newnode->next = bf_node->next;
                free(bf_node);
                return;
            }
            else
            {
                prev->next = newnode;
                newnode->next = bf_node;
                return;
            }
            
            
        }
            
            
    }
    // if min hasn't changed from (MEM_SIZ + 1) then it means there are no adequate hole to fit the process
    else
    {
        printf("Holes aren't large enough to fit %dK process. So no change is made.\n",val);
        return;
    }
    
}

void worst_fit(struct node* t, int val){
    int max = -1;   
    struct node * wf_node = NULL, *prev = NULL;    // worst fit node (worst fit hole)
    temp = t;
    while (t)
    {
        
        
        if(t->type == 'H'){
            if (t->size >= val)
            {
                if (t->size >= max)
                {
                    max = t->size;
                    wf_node = t;
                    prev = temp;
                }
                
            }
        }

        
        temp = t;
        t = t->next;
    }

    // after iterating through the entire memory...
    if (max != - 1)
    {
        if (wf_node == head)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->id = id_val++;
            newnode->type = 'P';
            newnode->startaddr = head->startaddr;
            newnode->size = val;
            head->startaddr = newnode->startaddr + newnode->size;
            head->size -= newnode->size;
            if (head->size == 0)
            {
                newnode->next = head->next;
                temp = head;
                head = newnode;
                free(temp);
                return;
            }
            else
            {
                newnode->next = head;
                head = newnode;
                return;
            }
            
            
        }
        else
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->id = id_val++;
            newnode->type = 'P';
            newnode->startaddr = wf_node->startaddr; 
            newnode->size = val;
            wf_node->startaddr = newnode->startaddr + newnode->size;
            wf_node->size -= newnode->size;
            if (wf_node->size == 0)
            {
                prev->next = newnode;
                newnode->next = wf_node->next;
                free(wf_node);
                return;
            }
            else
            {
                prev->next = newnode;
                newnode->next = wf_node;
                return;
            }
            
            
        }
            
            
    }
    else
    {
        printf("Holes aren't large enough to fit %dK process. So no change is made.\n",val);
        return;
    }
    
}

void reset(struct node * t){
    printf("Resetting");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(500000);

    id_val = 0;
    addr = 0;
    struct node *prev;
    while (t)
    {
        prev = t;
        t = t->next;
        free(prev);
    }
    init();
}

int main(int argc, char const *argv[])
{
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("                                     MEMORY ALLOCATION ALGORITHM                                    \n");
    printf("----------------------------------------------------------------------------------------------------\n");
    
    printf("Initializing");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(500000);
    
    init();
    
    int c,size;
    while (1)
    {
        printf("----------------------------------------------------------------------------------------------------\n");
        printf("1. DISPLAY\t\t2. FIRST FIT\t\t3. BEST FIT\n4. WORST FIT\t\t5. RESET\t\t0. EXIT\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("                                           FIRST FIT                                                \n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Enter size of the process : ");
            scanf("%d", &size);
            first_fit(head, size);
            display(head);
            break;
        case 3:
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("                                           BEST FIT                                                 \n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Enter size of the process : ");
            scanf("%d", &size);
            best_fit(head, size);
            display(head);
            break;
        case 4:
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("                                          WORST FIT                                                 \n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Enter size of the process : ");
            scanf("%d", &size);
            worst_fit(head, size);
            display(head);
            break;
        case 5:
            reset(head);
            break;
        case 0:
            printf("Quitting");
            usleep(300000);
            printf(".");
            usleep(300000);
            printf(".");
            usleep(300000);
            printf(".");
            usleep(300000);
            exit(0);
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    }
    
    return 0;
}


