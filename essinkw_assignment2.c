#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//constants
int MAX = 256;

//linked list
struct Node
{
  //movie values
  char title[MAX];
  int year;
  char languages[MAX];
  double rating;
  
  Node* next
}

//function definitions
void fillList();

int main(void)
{
  //variables
  Node* head = NULL;
  int size;

  return 0;
}

void fillList();
