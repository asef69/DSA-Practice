#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
    int cur;
} ArrayList;

void init(ArrayList* list)
{
    list->capacity=2;
    list->size=0;
    list->cur=0;
    list->data=(int *)malloc(sizeof(int)*list->capacity);
}
void resize(ArrayList* list,int new_cap)
{
    int *new_data=(int *)malloc(sizeof(int)*new_cap);
    for(int i=0; i<list->size; i++)
    {
        new_data[i]=list->data[i];
    }
    free(list->data);
    list->data=new_data;
    list->capacity=new_cap;
}
void ensure_capacity(ArrayList*list)
{
    if(list->size>=list->capacity)
    {
        resize(list,list->capacity*2);
    }
}
void shrink(ArrayList*list)
{
    if(list->size<list->capacity/4 && list->capacity>2)
    {
        resize(list,list->capacity/2);
    }
}
void insert_front(ArrayList*list,int value)
{
    ensure_capacity(list);
    for(int i=list->size; i>0; i--)
    {
        list->data[i]=list->data[i-1];
    }
    list->data[0]=value;
    list->size++;
}
void insert_middle(ArrayList*list,int value)
{
    ensure_capacity(list);
    for(int i=list->size; i>list->cur; i--)
    {
        list->data[i]=list->data[i-1];
    }
    list->data[list->cur++]=value;
    list->size++;
}
void remove_front(ArrayList*list)
{
    if(list->size==0) return;
    for(int i=0; i<list->size; i++)
    {
        list->data[i]=list->data[i+1];
    }
    list->size--;
    shrink(list);
}
void remove_middle(ArrayList*list)
{
    if(list->size==0 || list->cur==0) return;
    for(int i=list->cur-1; i<list->size-1; i++)
    {
        list->data[i]=list->data[i+1];
    }
    list->cur--;
    list->size--;
    shrink(list);
}
void append(ArrayList*list,int value)
{
    ensure_capacity(list);
    list->data[list->size++]=value;
    list->cur=list->size;
}
void remove_back(ArrayList*list)
{
    if(list->size==0) return;
    list->size--;
    shrink(list);
}
int get_value(ArrayList*list,int index)
{
    if(index>=0 && index<list->size) return list->data[index];
    return -1;
}
void set_value(ArrayList*list,int index,int value)
{
    if(index>=0 && index<list->size) list->data[index]=value;
}
void print(ArrayList*list)
{
    printf("< ");
    for(int i=0; i<list->size; i++)
    {
        if(i==list->cur) printf("| ");
        printf("%d ",list->data[i]);
    }
    if(list->cur==list->size) printf("| ");
    if(list->size==0) printf(". ");
    printf(">\n");
}
void free_list(ArrayList*list)
{
    free(list->data);
}
int main()
{
    ArrayList list;
    init(&list);

    append(&list, 10);
    insert_front(&list, 5);
    insert_middle(&list, 7);
    print(&list);

    remove_front(&list);
    remove_middle(&list);
    append(&list, 20);
    remove_back(&list);
    set_value(&list, 0, 99);
    printf("Value at index 0: %d\n", get_value(&list, 0));
    print(&list);

    free_list(&list);
    return 0;
}
