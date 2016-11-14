#include <stdio.h>
#include "ADT_llist.h"

int main(){
    int i;
    LLIST* list;
    list = Llist_create(compare_int, print_int);
    
    int data1 = 100; 
    int data2 = 200;
    int data3 = 300;
    int data4 = 400;
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    
    if(!add_node_at(list,1,&data1))
        printf("list is empty: index %d is not allowd\n", 1);

     if(!add_node_at(list,0,&data1))
        printf("data insertion failed on empty list\n");
     else
         printf("data insertion ok on empty list: %d\n", data1);

     if(!add_node_at(list,list->count,&data2))
        printf("data insertion failed on rear\n");
     else
         printf("data insertion ok on rear node: %d\n",data2);

     printf("10 data insertion:\n");
     for(i=0; i<10; i++){
        if(!add_node_at(list, i, &data[i]))
            printf(" - add failed at %d\n", i);
        else
            printf(" - add ok at %d: %d\n", i, data[i]);
    }

    LLIST* list2 = copy_data(list);

    int count = list2->count;
    printf("copyed list2: ");
    for(i=0; i<count; i++)
        printf("%d ", *(int*)get_data_out(list2, i));
    printf("\n");

     if(!add_node_at(list,list->count,&data3))
        printf("data insertion failed on rear\n");
     else
         printf("data insertion ok on rear node: %d\n", data3);

     if(!add_node_at(list,0,&data4))
        printf("data insertion failed on front\n");
     else
         printf("data insertion ok on front: %d\n",data4);

    printf("Print All Iterative:\n");
    print_node(list,list->front);

    if(!del_node_at(list, 0))
        printf("data deletion failed on index 0\n");
    else
        printf("data deletion success on index 0\n");

    printf("Print All Iterative:\n");
    print_node(list,list->front);
       
    if(!del_node_at(list,list->count-1))
        printf("data deletion failed on rear\n");
    else
        printf("data deletion success on rear\n");

    if(!del_node_at(list,4))
        printf("data deletion failed on index 4\n");
    else
        printf("data deletion success on index 4\n");
    
    printf("current list size: %d\n", list->count);
    printf("Print All Iterative:\n");
    print_node(list,list->front);

    int found;
    int search = 200;
    int* searched_ptr;
    found = find_data(list, &search);
    searched_ptr = (int*)get_data_out(list, found);

    if(found != -1)
        printf("found %d at index %d\n",*searched_ptr,found);

    search = 5;
    found = find_data(list, &search);
    searched_ptr = (int*)get_data_out(list,found);

    if(found != -1)
        printf("found %d at index %d\n",*searched_ptr, found);

    return 0;
}
