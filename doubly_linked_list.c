#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_t* dll_create()
{
  struct doubly_linked_list_t *ptr = (struct doubly_linked_list_t*)calloc(1,sizeof(struct doubly_linked_list_t));
  return ptr;
}
int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
  if(dll==NULL)return 1;

  struct node_t *ptr = (struct node_t*)calloc(1,sizeof(struct node_t));

  if(ptr==NULL)
  {
    return 2;
  }

  ptr->data=value;

  ptr->prev=dll->tail;

  if(dll->tail!=NULL)
  {
    dll->tail->next=ptr;
  }

  dll->tail=ptr;

  if(dll->head==NULL)
  {
    dll->head=ptr;
  }
  return 0;
}
int dll_push_front(struct doubly_linked_list_t* dll, int value)
{
  if(dll==NULL)return 1;

  struct node_t *ptr = (struct node_t*)calloc(1,sizeof(struct node_t));

  if(ptr==NULL)return 2;

  ptr->data=value;

  ptr->next=dll->head;

  if(dll->head!=NULL)
  {
    dll->head->prev=ptr;
  }

  dll->head=ptr;
  if(dll->tail==NULL)
  {
    dll->tail=ptr;
  }
  return 0;
}
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL ||dll->head==NULL ||dll->tail==NULL )
  {
    if(err_code)
    {
    *err_code = 1;  
    } 
    return 1;
  }
  int wart= dll->head->data;
  struct node_t *ptr = dll->head;
   
    dll->head=ptr->next;

    if(dll->head!=NULL)
    {
      dll->head->prev=NULL;
    }

    if(ptr->next==NULL)
    {
      dll->tail=NULL;
    }

    free(ptr);

    if(err_code!=0)*err_code=0;

    return wart;
   

  }

int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL ||dll->head==NULL ||dll->tail==NULL )
  {
    if(err_code)
    {
    *err_code = 1;  
    } 
    return 1;
  }
  int wart= dll->tail->data;
  struct node_t *ptr = dll->tail;

  dll->tail=ptr->prev;

  if(dll->tail!=NULL)
  {
    dll->tail->next=NULL;
  }

  if(ptr->prev==NULL)
  {
    dll->head=NULL;
  }

  free(ptr);
  if(err_code!=0)*err_code=0;

    return wart;
}
int dll_back(const struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL ||dll->head==NULL ||dll->tail==NULL )
  {
    if(err_code)
    {
    *err_code = 1;  
    } 
    return 1;
  }
  if(err_code!=0)*err_code=0;
  return dll->tail->data;

}
int dll_front(const struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL ||dll->head==NULL ||dll->tail==NULL )
  {
    if(err_code)
    {
    *err_code = 1;  
    } 
    return 1;
  }
  if(err_code!=0)*err_code=0;
  return dll->head->data;
}
struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return NULL;
  }
    

  return dll->head;
}
struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return NULL;
  }
    

  return dll->tail;
}
int dll_size(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return -1;
  }

  struct node_t *ptr ;

  ptr=dll->tail;
  int i=0;
  while(ptr!=NULL)
  {
    i++;
    ptr=ptr->prev;
  }
  return i;
}
int dll_is_empty(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return -1;
  }
  return (dll->head!=NULL?0:1);
}
int dll_at(const struct doubly_linked_list_t* dll, unsigned int index,int *err_code)
{
  if(dll==NULL ||dll->head==NULL ||dll->tail==NULL )
  {
    if(err_code!=NULL)
    {
    *err_code = 1;  
    } 
    return -1;
  }

struct node_t *ptr;
  ptr=dll->head;
  unsigned int i=0;
  int val=0;

  while(i<index &&ptr!=NULL)
  {
    ptr=ptr->next;
    i++;
  }

  if(i!=index || ptr==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return -1;
  }

  if(err_code!=NULL)*err_code=0;
  val=ptr->data;
  return val;

}
int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
  if(dll==NULL)return 1;
  if(index > (unsigned int)dll_size(dll))return 1;
  if((int)index<0)return 1;

  int count=0;

  struct node_t *ptr;
  ptr=dll->head;

  while( (unsigned int)count<index-1&& ptr!=NULL  )
  {
    count++;
    ptr=ptr->next;
     
  }

 if((int)index==0)
  {
    return dll_push_front(dll,value);
  }
  if(ptr->next==NULL)
  {
    return dll_push_back(dll,value);
  }
 

  struct node_t *ptr_new=(struct node_t*)calloc(1,sizeof(struct node_t));

  if(ptr_new==NULL)
  {
    return 2;
  }

  ptr_new->data=value;
  ptr_new->prev=ptr;
  ptr_new->next=ptr->next;

  if(ptr->next!=NULL)
  {
    ptr->next->prev=ptr_new;
  }

  ptr->next=ptr_new;
  return 0;
}
int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
  if(!dll || !dll->head || !dll->tail || (int)index < 0 ||(int)index > dll_size(dll)-1)
  {
    if(err_code) *err_code = 1;
    return 1;
  }
  int count=0;
  int wart;
  struct node_t *ptr;
  ptr=dll->head;

 while((unsigned int)count<index&& ptr!=NULL)
  {
    count++;
    ptr=ptr->next;
     
  }


  if((int)index==0)
  {
    return dll_pop_front(dll,err_code);
  }
  if(ptr->next==NULL)
  {
    return dll_pop_back(dll,err_code);
  }
  

  wart=ptr->data;

 

 

   if(ptr->next!=NULL)
  {
    ptr->next->prev=ptr->prev;
  }
   if(ptr->prev!=NULL)
  {
    ptr->prev->next=ptr->next;
  }

    free(ptr);
  if(err_code!=NULL)
  {
    *err_code = 0;
  } 
  return wart;
}
void dll_clear(struct doubly_linked_list_t* dll)
{

  if(dll==NULL)return;
  if(dll->head==NULL)return;
  if(dll->tail==NULL)return;

  struct node_t *ptr;
  ptr = dll->head;

  while(ptr!=NULL)
  {
    dll->head=ptr->next;
    free(ptr);
    ptr=dll->head;
  }
  dll->tail=NULL;
}
void dll_display(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)return;
  if(dll->head==NULL)return;
  if(dll->tail==NULL)return;

  struct node_t *ptr;
  ptr = dll->head;

  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}
void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)return;
  if(dll->head==NULL)return;
  if(dll->tail==NULL)return;

  struct node_t *ptr;
  ptr = dll->tail;

  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->prev;
  }
}
