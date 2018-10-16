#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"list.c"


struct song_node *table[27];

void setup(){
  int i = 0;
  while (i < 27){
    table[i] = NULL;
    i++;
  }
}

void add(char *song, char *artist) {
  char arr[100];
  strcpy(arr, artist);
  char letter = arr[0];
  int comp = 97; // actual ascii value of a
  int i = (int) letter - comp;
  if (i < 27){
    insert_order(song, artist, table[i]);
  }
  else{
    insert_order(song, artist, table[26]);
  }
}

/* // returns pointer to a song by a certain artist */
/* struct song_node *searchS(char *song, char *artist) { */
/*   struct song_node * temp = *table; */
/*   printf("Searching for song %s by artist %s:\n", song, artist); */
/*   while (temp != NULL && find_node(song, artist, temp) == NULL){ */
/*     temp  = temp -> next; */
/*   } */
/*   return find_node(song, artist, temp); */
/* } */


/* // returns pointer to a certain artist */
/* struct song_node *searchA(char *artist) { */
/*   struct song_node * temp = *table; */
/*   printf("Searching for artist %s:\n", artist); */
/*   while (temp != NULL && find_artist(artist, temp) == NULL){ */
/*     temp  = temp -> next; */
/*   } */
/*   return find_artist(artist, temp); */
/* } */


/* //EDIT */
/* //print all artists starting with a letter as well as their corresponding song */
/* void print_letters(char letter) { */
/*   struct song_node * temp = *table; */

  
/*   return print_list(temp); */
/* } */

/* //prints all the songs by an author */
/* void print_songs(char *artist) { */
/*   return print_list(searchA(artist)); */
/* } */

//print all items in  table
void print_all() {
  while ((*table)++ ){
    print_list(*table);
  }
}

/* EDIT */
/* prints the elements starting from a random pointer */
/* void print_shuffle() { */
/*   return print_list( random_node (table) ); */
/* } */

/* EDIT */
/* deletes a song from the table */
/* void delete(char *song) { */
/*   struct song_node * temp = *table; */

/*   while (temp != NULL && !strcmp(temp.name,song) ){ */
/*     temp  = temp -> next; */
/*   }   */
/*   remove_node(song, temp); */
/* } */

/* clears the entire table */
/* void clear() { */
/*   struct song_node * temp = *table; */
/*   while (table != NULL){ */
/*     free_list(*table); */
/*     *table = temp -> next; */
/*   } */
/* } */

int main() {

  printf("MUSIC LIBRARY TESTS\n");

  setup();
  
  printf("====================================\n\n");

  add("thunderstruck","ac/dc");
  add("alive", "pearl jam");
  add("even flow", "pearl jam");
  add("yellow ledbetter", "pearl jam");
  add("time", "pink floyd");
  add("paranoid android", "radiohead");
  add("street spirit (fade out)", "radiohead");
  print_all();

 
  /* printf("Testing print_library\n"); */
  /* printf("a list\n"); */
  /* printf(" ac/dc: thunderstruck |\n"); */
  /* printf("p list\n"); */
  /* printf("pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | presidents of the united states of america: peaches |\n"); */
  /* printf("r list\n"); */
  /* printf(" radiohead: paranoid android | radiohead: street spirit (fade out) |\n"); */
  /* printf("====================================\n"); */

/* Testing print_letter */
/* p list */
/*  pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | presidents of the united states of america: peaches |  */
/* ==================================== */

/* Testing find: */
/* looking for [pearl jam: alive] */
/*  song found! pearl jam: alive */
/* looking for [pearl jam: time] */
/*  song not found */
/* ==================================== */

/* Testing find artist: */
/* looking for [pearl jam] */
/*  artist found! pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | presidents of the united states of america: peaches |  */
/* looking for [pink floyd] */
/*  artist found! pink floyd: time | presidents of the united states of america: peaches |  */
/* looking for [bob dylan] */
/*  artist not found */
/* ==================================== */

/* Testing remove_song */
/* removing: [pearl jam: alive] */
/* a list */
/*  ac/dc: thunderstruck |  */
/* p list */
/*  pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | presidents of the united states of america: peaches |  */
/* r list */
/*  radiohead: paranoid android | radiohead: street spirit (fade out) |  */

/* removing: [pearl jam: yellow ledbetter] */
/* a list */
/*  ac/dc: thunderstruck |  */
/* p list */
/*  pearl jam: even flow | pink floyd: time | presidents of the united states of america: peaches |  */
/* r list */
/*  radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* ==================================== */

/* Testing clear_library: */
/* freeing node: ac/dc - thunderstruck */
/* freeing node: pearl jam - even flow */
/* freeing node: pink floyd - time */
/* freeing node: presidents of the united states of america - peaches */
/* freeing node: radiohead - paranoid android */
/* freeing node: radiohead - street spirit (fade out) */

/* Library after clear: */
/* ==================================== */

/* Adding songs to empty library */
/* a list */
/*  ac/dc: thunderstruck |  */
/* p list */
/*  pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time |  */
/* ==================================== */

/* Testing print_artist: */
/* Printing [pearl jam] */
/* [pearl jam: alive] */
/* [pearl jam: even flow] */
/* [pearl jam: yellow ledbetter] */

/* Printing [ac/dc] */
/* [ac/dc: thunderstruck] */
/* ==================================== */

/* Testing shuffle */
/* ac/dc: thunderstruck */
/* ac/dc: thunderstruck */
/* pearl jam: yellow ledbetter */
/* ==================================== */
  
}
