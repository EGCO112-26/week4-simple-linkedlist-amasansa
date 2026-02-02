//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    
    /*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node d;
    d.value=11;
    b.next=&d;
    d.next=NULL;
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value ); //what value for 11
    
    /*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    printf("Insert in front\n");
    struct node e;
    e.value=2;
    e.next=&a;
    head=&e;
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5
    printf("%d\n", head ->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->value ); //what value for 11

    printf("Insert in middle\n");
    struct node f;
    f.value=7;
    f.next=&b;
    a.next=&f;
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5
    printf("%d\n", head ->next->next->value ); //what value for 7
    printf("%d\n", head ->next->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->next->value ); //what value for 11

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //Exercise III Use loop to print everything
    int i,n=5;
    for(i=0;i<n;i++){
        printf("%-3d", tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    //Exercise IV change to while loop!! (you can use NULL to help)
    tmp=head; //ชี้ตัวแรก
    while(tmp!=NULL){
        printf("%-3d", tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    
    /*Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
     */
    printf("Create by malloc\n");
    NodePtr temp;
    head=(NodePtr)malloc(sizeof(struct node));
    temp=head;

    n=10;
    for(i=0;i<n;i++)
    {
        temp->value=7+(i*2);
        // if(i==n-1) {
        //     temp->next = NULL; // ตัวสุดท้ายให้เป็น NULL
        // }else{
            temp->next=(NodePtr)malloc(sizeof(struct node));
            temp=temp->next;
        // }
    }
    temp->value=7+(i*2);
    temp->next = NULL;

    temp=head; //ชี้ตัวแรก
    while(temp!=NULL){
        printf("%-3d", temp->value);
        temp=temp->next;
    }
    printf("\n");

    /*Exercise VI Free all node !!
         //use a loop to help     
    */
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}