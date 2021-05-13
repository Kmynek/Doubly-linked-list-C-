#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
 struct doubly_linked_list_t * ptr;
  int dec=0;
  int input=0;
  int check=0;
  int index=0;
  int wart=0;
  int err_code;
   
  ptr=dll_create();

 if(ptr==NULL)
 {
   return 8+!printf("Failed to allocate memory");
 }

 for(;;)
 {
   printf("Co tam misiu?: ");
   check=scanf("%d",&dec);

   if(check!=1)
   {
     dll_clear(ptr);
     free(ptr);
     return 1+!printf("Incorrect input");
   }

   switch(dec)
   {
     case 0:
      dll_clear(ptr);
      free(ptr);
      return 0;

     case 1: ///////////////////////////////////////////////////////////////////////
      printf("Podaj: ");
      check=scanf("%d",&input);
      if(check!=1)
      {
        dll_clear(ptr);
        free(ptr);
        return 1+!printf("Incorrect input");
      }
      check=dll_push_back(ptr, input);
      if(check==2)
      {
        dll_clear(ptr);
        free(ptr);
        return 8+!printf("Failed to allocate memory");
      }
      break;

     case 2: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("%d\n",dll_pop_back(ptr,NULL));
     break;

     case 3: ///////////////////////////////////////////////////////////////////////
     printf("Podaj: ");
     check=scanf("%d",&input);
     if(check!=1)
     {
      dll_clear(ptr);
      free(ptr);
      return 1+!printf("Incorrect input");
     }
     check=dll_push_front(ptr, input);
     if(check==2)
     {
       dll_clear(ptr);
       free(ptr);
       return 8+!printf("Failed to allocate memory");
     }
     break;

     case 4: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("%d\n",dll_pop_front(ptr,NULL));
     break;

     case 5: ///////////////////////////////////////////////////////////////////////
     printf("Podaj: ");
     check=scanf("%d",&input);
     if(check!=1)
     {
      dll_clear(ptr);
      free(ptr);
      return 1+!printf("Incorrect input");
     }

     printf("Podaj index: ");
     check=scanf("%d",&index);
     if(check!=1)
     {
      dll_clear(ptr);
      free(ptr);
      return 1+!printf("Incorrect input");
     }
     check=dll_insert(ptr, index, input);

     if(check==2)
     {
       dll_clear(ptr);
       free(ptr);
       return 8+!printf("Failed to allocate memory");
     }
     
     if(check==1)
     {
       printf("Index out of range\n");
     }
    break;
     case 6: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("Podaj index: ");
     check=scanf("%d",&index);
     if(check!=1)
     {
      dll_clear(ptr);
      free(ptr);
      return 1+!printf("Incorrect input");
     }
     
     wart=dll_remove(ptr, index, &err_code);
     if(err_code==1)
     {
       printf("Index out of range\n");
       break;
     }
     printf("%d\n",wart);
     break;

     case 7: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("%d\n",dll_back(ptr, NULL));
     break;
     case 8: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("%d\n",dll_front(ptr, NULL));
     break; 
     case 9: ///////////////////////////////////////////////////////////////////////
     printf("%d\n",dll_is_empty(ptr));
     break;
     case 10: ///////////////////////////////////////////////////////////////////////
     printf("%d\n",dll_size(ptr));
     break;
     case 11: ///////////////////////////////////////////////////////////////////////
     dll_clear(ptr);
     break;
     case 12: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     printf("Podaj index: ");
     check=scanf("%d",&index);
     if(check!=1)
     {
      dll_clear(ptr);
      free(ptr);
      return 1+!printf("Incorrect input");
     }
     wart=dll_at(ptr, index, &err_code);
     if(err_code==1)
     {
       printf("Index out of range\n");
       break;
     }
     printf("%d\n",wart);
     break;
     case 13: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     dll_display(ptr);
     printf("\n");
     break;
     case 14: ///////////////////////////////////////////////////////////////////////
     check=dll_is_empty(ptr);
     if(check!=0)
     {
       printf("List is empty\n");
       break;
     }
     dll_display_reverse(ptr);
     printf("\n");
     break;
     default: ///////////////////////////////////////////////////////////////////////
     printf("Incorrect input data\n");
     break;

   }

 }
 return 0;
}
