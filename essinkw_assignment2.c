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
int processMovieFile(char* filePath, Node** head);

int main(void)
{
  //variables
  Node* head = NULL;
  int size;

  size = proccessMovieFile("movies_sample_1.csv", &head)
  
  return 0;
}

//fills linked list with movie data and prints out some information
//Uses code from movies.c example code
int processMovieFile(char* filePath, Node** head)
{
  
}





