#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//constants
int MAX = 256;

//linked list
struct movie
{
  //movie values
  char title[MAX];
  int year;
  char languages[MAX];
  double rating;
  
  movie* next;
}

//function definitions
int processMovieFile(char* filePath, movie** head);
int menu(void);
void specifiedYear(movie** head, int size);
void highestRated(movie** head, int size);
void specificLanguage(movie** head, int size);

int main(void)
{
  //variables
  movie* head = NULL;
  int size;
  int option;

  size = proccessMovieFile("movies_sample_1.csv", &head);

  do 
  {
    //get users option
    option = menu();

    //error message
    if(option > 4 || option < 1)
    {
      printf("You entered an incorrect choice. Try again.\n");
    }
    //run users option
    if(option == 1)
    {
      specifiedYear(&head, size);
    }
    if(option == 2)
    {
      highestRated(&head, size);
    }
    if(option == 3)
    {
      specificLanguage(&head, size);
    }
  } while(option != 4);

  return 0;
}

//fills linked list with movie data and prints out some information
//Uses code from movies.c example code
int processMovieFile(char* filePath, movie** head)
{
  char* currLine = NULL;
  size_t len = 0;
  ssize_t read;
  int count = 0;

  FILE* movieFile = fopen(filePath, "r");
  if (!movieFile) {
      printf("Error opening file");
      return 0;
  }

  // skip header line
  getline(&currLine, &len, movieFile);

  while ((read = getline(&currLine, &len, movieFile)) != -1) {
        movie* newmovie = malloc(sizeof(movie));
        if (!newmovie) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        //remove newline if present
        if (currLine[strlen(currLine)-1] == '\n') {
            currLine[strlen(currLine)-1] = '\0';
        }

        //parse line: title, year, languages, rating
        char* token = strtok(currLine, ",");
        strncpy(newmovie.title, token, MAX);

        token = strtok(NULL, ",");
        newmovie.year = atoi(token);

        token = strtok(NULL, ",");
        strncpy(newmovie.languages, token, MAX);

        token = strtok(NULL, ",");
        newmovie.rating = atof(token);

        newmovie->next = NULL;

        //insert movie at end of list
        if (*head == NULL) {
            *head = newmovie;
        } else {
            movie* temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newmovie;
        }

        count++;
    }

    free(currLine);
    fclose(movieFile);
    printf("Processed file %s and parsed data for %d movies\n", filePath, count);
  
    return count;
}

//prints and gets menu option
int menu(void)
{
  int option;

  printf("\n1. Show movies released in the specified year\n");
  printf("2. Show highest rated movie for each year\n");
  printf("3. Show the title and year of release of all movies in a specific language\n");
  printf("4. Exit from the program\n");

  printf("\nEnter a choice from 1 to 4: ");
  scanf("%d", &option);

  return option;
}

//show movies released in the specified year
void specifiedYear(movie** head, int size)
{
  movie* curr = *head
  int year;
  bool ifMovie = false;

  //get user input
  printf("Enter the year for which you want to see movies: ");
  scanf("%d", &year);

  //loop through the list
  for(int i = 0; i < size; i++)
  {
    if(curr.year == year)
    {
      printf("%s\n", curr.title);

      ifMovie = true;
    }
    
    curr = curr->next;
  }

  //check if there are no movies for the users year
  if(ifMovie == false)
  {
    printf("No data about movies released in the year %d\n", year);
  }
}

//show highest rated movie for each year
void highestRated(movie** head, int size)
{
 movie* curr = *head;
 movie* topMovies = NULL;

    while (curr != NULL)
    {
        movie* search = topMovies;
        bool found = false;

        while (search != NULL)
        {
            if (search->year == curr->year)
            {
                found = true;
                //compare ratings, update if current movie is better
                if (curr.rating > search.rating)
                {
                    strncpy(search.title, curr.title, MAX);
                    strncpy(search.languages, curr.languages, MAX);
                    search.rating = curr.rating;
                }
                break;
            }
            search = search->next;
        }

        //if no movie recorded for this year yet, add it to topMovies list
        if (!found)
        {
            movie* newNode = malloc(sizeof(struct movie));
            if (!newNode) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            strncpy(newNode.title, curr.title, MAX);
            strncpy(newNode.languages, curr.languages, MAX);
            newNode.year = curr.year;
            newNode.rating = curr.rating;
            newNode.next = topMovies;
            topMovies = newNode;
        }

        curr = curr->next;
    }

    //print the top rated movie for each year
    movie* printer = topMovies;
    while (printer != NULL)
    {
        printf("%d %.1f %s\n", printer.year, printer.rating, printer.title);
        printer = printer->next;
    }

    //free the topMovies list
    while (topMovies != NULL)
    {
        movie* temp = topMovies;
        topMovies = topMovies->next;
        free(temp);
    }
}

//show the title and year of release of all movies in a specific language
void specificLanguage(movie** head, int size)
{
  movie* curr = *head
  char lan[MAX];
  bool ifMovie = false;

  //get user input
  printf("Enter the language for which you want to see movies: ");
  scanf("%s", &lang);

  //loop through the list
  for(int i = 0; i < size; i++)
  {
    if(strstr(curr.languages, lang) != NULL)
    {
      printf("%d %s\n", curr.year, curr.title);

      ifMovie = true;
    }
    
    curr = curr->next;
  }

  //check if there are no movies for the users language
  if(ifMovie == false)
  {
    printf("No data about movies released in %s\n", lang);
  }
}



