#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "list.h"
#include "library.h"

// our music library
struct song_node *table[27];


// adds a song to our table in alphabetical order
void add(char song[100], char artist[100]) {
  char letter = artist[0];
  int i = (int) (letter - 'a');
  if (table[i] == NULL){
    table[i] = malloc(sizeof(struct song_node));
  }
  if (i >= 0 && i < 27)
    insert_order(song, artist, table[i]);
  else
    insert_order(song, artist, table[26]);
}



// returns pointer to a song by a certain artist
struct song_node *searchS(char song[100], char artist[100]) {
  char letter = artist[0];
  int i = (int)(letter - 'a');

  printf("looking for [%s: %s]\n", artist, song);

  if (find_node(song, artist, table[i]) != NULL){
    printf("song found! %s: %s\n", artist, song);
  }
  else{
    printf("song not found!\n");
  }

  return find_node(song, artist, table[i]);
}




// returns pointer to a certain artist
struct song_node *searchA(char artist[100]) {
  char letter = artist[0];
  int i = (int)(letter - 'a');
  struct song_node *n = table[i];
  
  printf("looking for [%s]\n", artist);

  if (find_artist(artist, n) != NULL){
    printf("artist found!");
    while (n != NULL){
      if (strcmp(n->artist, artist) == 0)
	printf(" %s : %s  | \n", n->artist, n->name);
      n = n -> next;
    }
  }
  else{
    printf("artist not found!");
  }
  printf("\n");
  return find_artist(artist, table[i]);
}




//print all artists starting with a letter as well as their corresponding song
void print_letters(char letter) {
  int i = (int)(letter - 'a');
  if (i < 27){
    print_list(table[i]->next);
  }
  else{
    print_list(table[26]->next);
  }
}

//prints all the songs by an author
void print_songs(char artist[100]) {
  char letter = artist[0];
  int i = (int)(letter - 'a');
  struct song_node *n = table[i];
  while(n != NULL && strcmp(artist, n->artist) != 0)
    n = n->next;
  while(n != NULL && strcmp(artist, n->artist) == 0) {
    printf("%s: %s\n",n->artist,n->name);
    n = n->next;
  }
}



/* print all items in  table */
void print_all() {
  printf("\nMusic library:\n");
  int i = 0;
  while (i <= 26) {
    if (table[i] != NULL)
      print_list(table[i]->next);
    i++;
  }
  printf("\n");
}

/* prints a random sequence of songs of random length */
void print_shuffle() {
  printf("\nrandom shuffle:\n");
  int var = rand() % 15 + 3;
  int i;
  struct song_node *n;

  while(var > 0) {
    i = rand() % 27;
    n = random_node(table[i]);
    
    if (n != NULL) {
      print_node(n->next);
      var--;
    }

  }
}

// removes a song from our music library
void remove_song(char song[100], char artist[100]) {
  char letter = artist[0];
  int i = (int)(letter - 'a');
  remove_node(song, artist, table[i]);
  printf("Removed %s: %s \n", artist, song);
}

// clears the entire library
void clear_library() {
  int i = 0;
  struct song_node *temp;
  for(i; i < 27; i++) {
    temp = table[i];
    while (temp != NULL && temp->next != NULL){
      temp = temp->next;
      printf("freeing node: %s - %s\n", temp->artist, temp->name);
    }
    table[i] = free_list(table[i]);
  }
}
