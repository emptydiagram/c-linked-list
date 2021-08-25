#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct linked_list_int
{
  struct linked_list_int_node *first;
  struct linked_list_int_node *last;
  size_t size;
};

struct linked_list_int_node
{
  int value;
  struct linked_list_int_node *next;
};

struct linked_list_int_node* create_node_from_value(int val)
{
  struct linked_list_int_node *newNode = malloc(sizeof(struct linked_list_int_node));
  if (newNode == NULL)
  {
    return NULL;
  }
  newNode->value = val;
  newNode->next = NULL;
  return newNode;
}

struct linked_list_int* add_node_to_empty_list(struct linked_list_int *lst, int val)
{
  if (lst == NULL || lst->first != NULL || lst->last != NULL)
  {
    return lst;
  }

  struct linked_list_int_node* newNode = create_node_from_value(val);
  if (newNode == NULL)
  {
    printf("Error creating linked list node\n");
    return NULL;
  }
  lst->first = lst->last = newNode;
  lst->size = 1;
  return lst;
}


struct linked_list_int* create_list_from_value(int val)
{
  // printf("\ncreating list from value:\n %d", val);
  struct linked_list_int *newLL = malloc(sizeof(struct linked_list_int));
  if (newLL == NULL)
  {
    printf("Error creating linked list\n");
    return NULL;
  }
  newLL->first = newLL->last = NULL;
  return add_node_to_empty_list(newLL, val);
}

struct linked_list_int* add_to_list(struct linked_list_int* lst, int val, bool addToBeginning)
{
  if (lst == NULL)
  {
    return create_list_from_value(val);
  }

  // if first and last are null, treat it as an empty list
  if (lst->first == NULL && lst->last == NULL)
  {
    return add_node_to_empty_list(lst, val);
  }

  struct linked_list_int_node* newNode = create_node_from_value(val);
  if (newNode == NULL)
  {
    printf("Error creating linked list\n");
    return NULL;
  }

  if (lst->first == lst->last)
  {
    if (addToBeginning)
    {
      lst->first = newNode;
    }
    else
    {
      lst->last = newNode;
    }
    lst->first->next = lst->last;
    lst->size += 1;
    return lst;
  }

  if (addToBeginning)
  {
    newNode->next = lst->first;
    lst->first = newNode;
  }
  else
  {
    lst->last->next = newNode;
    lst->last = newNode;
  }
  lst->size += 1;
  return lst;
}

void print_linked_list(struct linked_list_int *lst)
{
  struct linked_list_int_node *curr = lst->first;
  printf("( ");
  while (curr != NULL)
  {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  printf(")\n");
}

int main(void)
{
  printf("hi\n");
  struct linked_list_int *lst = create_list_from_value(5);
  print_linked_list(lst);
  add_to_list(lst, 6, false);
  print_linked_list(lst);
  add_to_list(lst, 7, false);
  print_linked_list(lst);
  add_to_list(lst, 8, false);
  print_linked_list(lst);
}