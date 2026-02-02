#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, const char * argv[]) 
{
    NodePtr head = NULL,temp,last;
    int i;
    for(i=1;i<argc;i+=2)
    {
        temp=(NodePtr)malloc(sizeof(STD));
        temp->id=atoi(argv[i]); 
        strcpy(temp->name,argv[i+1]);
            
        temp->next=NULL;

        if(head==NULL) 
        {
            head=temp; 
        }else 
        {
            last->next=temp; 
        }
        last=temp; 
    }

    temp = head;
    while(temp!=NULL) 
    {
        printf("%d %s\n",temp->id,temp->name);
        temp=temp->next;
    }

    while(head!=NULL) 
    {
        temp = head;
        head = head->next;
        free(temp); 
    }
    
    return 0;
}