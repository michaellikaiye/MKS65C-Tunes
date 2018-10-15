#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"library.h"

// returns pointer to a song by a certain artist
struct song_node *searchS(char *song, char *artist) {
  struct song_node * temp = *table;
  printf("Searching for song %s by artist %s:\n", song, artist);
  while (temp != NULL && find_node(song, artist, temp) == NULL){
    temp  = temp -> next;
  }
  return find_node(song, artist, temp);
}


// returns pointer to a certain artist
struct song_node *searchA(char *artist) {
  struct song_node * temp = *table;
  printf("Searching for artist %s:\n", artist);
  while (temp != NULL && find_artist(artist, temp) == NULL){
    temp  = temp -> next;
  }
  return find_artist(artist, temp);
}


//EDIT
//print all artists starting with a letter as well as their corresponding song
void print_letters(char letter) {
  struct song_node * temp = *table;

  
  return print_list(temp);
}

//prints all the songs by an author
void print_songs(char *artist) {
  return print_list(searchA(artist));
}

//print all items in  table
void print_all() {
  struct song_node * temp = *table;
  while (temp != NULL){
    print_list(temp);
    temp  = temp -> next;
  }

}

//EDIT
//prints the elements starting from a random pointer
void print_shuffle() {
  return print_list( random_node (table) );
}

//EDIT
//deletes a song from the table
void delete(char *song) {
  struct song_node * temp = *table;

  while (temp != NULL && !strcmp(temp.name,song) ){
    temp  = temp -> next;
  }  
  remove_node(song, temp);
}

//clears the entire table
void clear() {
  struct song_node * temp = *table;
  while (table != NULL){
    free_list(*table);
    *table = temp -> next;
  }
}
