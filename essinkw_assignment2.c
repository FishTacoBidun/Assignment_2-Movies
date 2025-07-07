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
int menu(void);
void specifiedYear(Node** head, int size);
void highestRated(Node** head, int size);
void specificLanguage(Node** head, int size);

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
  char* currLine = NULL;
  size_t len = 0;
  ssize_t read;
  int count = 0;

  FILE* movieFile = fopen(filePath, "r");
  if (!movieFile) {
      perror("Error opening file");
      return 0;
  }

  // skip header line
  getline(&currLine, &len, movieFile);

  while ((read = getline(&currLine, &len, movieFile)) != -1) {
        Node* newNode = malloc(sizeof(Node));
        if (!newNode) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        //remove newline if present
        if (currLine[strlen(currLine)-1] == '\n') {
            currLine[strlen(currLine)-1] = '\0';
        }

        //parse line: title, year, languages, rating
        char* token = strtok(currLine, ",");
        strncpy(newNode->title, token, MAX);

        token = strtok(NULL, ",");
        newNode->year = atoi(token);

        token = strtok(NULL, ",");
        strncpy(newNode->languages, token, MAX);

        token = strtok(NULL, ",");
        newNode->rating = atof(token);

        newNode->next = NULL;

        //insert node at end of list
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        count++;
    }

    free(currLine);
    fclose(movieFile);
    printf("Processed file %s and parsed data for %d movies\n", filePath, count);
  
    return count;
}

//get menu option
int menu(void)
{
  int option;

  printf("1. Show movies released in the specified year\n");
  printf("2. Show highest rated movie for each year\n");
  printf("3. Show the title and year of release of all movies in a specific language\n");
  printf("4. Exit from the program\n");

  printf("\nEnter a choice from 1 to 4: ");
  scanf("%d", &option);

  return option;
}

//show movies released in the specified year
void specifiedYear(Node** head, int size)
{

}

//show highest rated movie for each year
void highestRated(Node** head, int size)
{

}

//show the title and year of release of all movies in a specific language
void specificLanguage(Node** head, int size)
{

}



