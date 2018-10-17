#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

/* print the entire list */
void print_list(struct song_node *n) {
  while(n->next) {
    printf("%s: %s | \n",n->next->artist,n->next->name);
    n = n->next;
  }
}

/* print a node */
void print_node(struct song_node *n) {
  if(n != NULL)
    printf("%s: %s\n",n->artist,n->name);
}

/* insert nodes at the front */
struct song_node *insert_front(char name[100], char artist[100], struct song_node *n) {
  struct song_node *p = malloc(sizeof(struct song_node));
  strcpy(p->name,name);
  strcpy(p->artist,artist);
  p->next = n;
  return p;
}

/* insert nodes in order */
/* alphabetical by Artist then by Song */
struct song_node *insert_order(char name[100], char artist[100], struct song_node *n) {
  struct song_node *p = malloc(sizeof(struct song_node));
  strcpy(p->name,name);
  strcpy(p->artist,artist);
  if(n == NULL) {
    p->next = n;
    return p;
  }

  struct song_node *c = n;
  while(c->next != NULL && strcmp(p->artist, c->next->artist) > 0)
      c = c->next;
  if(strcmp(n->artist,p->artist))
    while(c->next != NULL && strcmp(p->name, c->next->name) > 0)
	c = c->next;
  p->next = c->next;
  c->next = p;
  return n;
}

/* find and return a pointer to a node based on artist and song name */
struct song_node *find_node(char *name, char *artist, struct song_node *n) {
  while(n != NULL) {
    if(strcmp(artist, n->artist) == 0 && strcmp(name, n->name) == 0)
      return n;
    n = n->next;
  }
  return n;
}

/* find and return a pointer to the first song of an artist based on artist name */
struct song_node *find_artist(char *artist, struct song_node *n) {
  while(n != NULL && strcmp(artist, n->artist) != 0)
    n= n->next;
  return n;
}

/* compares how far apart they are in the list */
int songcmp(char *nameA, char *artistA, char *nameB, char *artistB, struct song_node *n) {
  int a;
  int b;
  int i = 0;
  while (n) {
    if(strcmp(artistA, n->artist) == 0 && strcmp(nameA, n->name) == 0)
      a = i;
    if(strcmp(artistB, n->artist) == 0 && strcmp(nameB, n->name) == 0)
      b = i;
    n = n->next;
    i++;
  }
  return 4 * (a - b);
}

/* Return a pointer to random element in the list. */
struct song_node *random_node(struct song_node *n) {
  struct song_node *s = malloc(sizeof(struct song_node));
  s = n;
  int size = 0;
  while(s != NULL) {
    s = s->next;
    size++;
  }
  free(s);
  int move = (rand() % size);
  while(move) {
    n = n->next;
    move--;
  }
  return n;
}

/* remove a single specified node from the list */
struct song_node *remove_node(char *name, char *artist, struct song_node *n) {
  if(strcmp(artist, n->artist) == 0 && strcmp(name, n->name) == 0) {
    struct song_node *new = malloc(sizeof(struct song_node));
    new = n->next;
    free(n);
    return new;
  }
  struct song_node *c = n;
  while(c->next != NULL) {
    if(strcmp(artist, c->next->artist) == 0 && strcmp(name, c->next->name) == 0) {
      struct song_node *trash = c->next;
      c->next = c->next->next;
      free(trash);
      return n;
    }
    c = c->next;
  }
  printf("%s: %s not found\n", artist, name);
  return n;
}

/* free the entire list */
struct song_node *free_list(struct song_node *n) {
  struct song_node *temp;
  while(n) {
    temp = n;
    n = n->next;
    free(temp);
  }
  return n;
}


struct song_node *table[27];

void setup() {
  int i = 0;
  while(i != 27) {
    table[i] = malloc(sizeof(struct song_node));
    i++;
  }
}

void add(char *song, char *artist) {
  char arr[100];
  strcpy(arr, artist);
  char letter = arr[0];
  int comp = 97; // actual ascii value of a
  int i = ((int) letter) - comp;
  if (i < 27){
    insert_order(song, artist,table[i]);
  }
  else{
    insert_order(song, artist, table[26]);
  }
}



// returns pointer to a song by a certain artist
struct song_node *searchS(char *song, char *artist) {
  char arr[100];
  strcpy(arr, artist);
  char letter = arr[0];
  int i = letter - 97;

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
struct song_node *searchA(char *artist) {
  char arr[100];
  strcpy(arr, artist);
  char letter = arr[0];
  int i = letter - 97;
  
  printf("looking for [%s]\n", artist);

  if (find_artist(artist, table[i]) != NULL){
    printf("artist found! \n");
    
  }
  else{
    printf("artist not found!\n");
  }
  return find_artist(artist, table[i]);
}




//print all artists starting with a letter as well as their corresponding song
void print_letters(char *letter) {
  int i = *letter - 97;
  if (i < 27){
    print_list(table[i]);
  }
  else{
    print_list(table[26]);
  }
}

/* //prints all the songs by an author */
/* void print_songs(char *artist) { */
/*   return print_list(searchA(artist)); */
/* } */



/* print all items in  table */
void print_all() {
  int i = 0;
  while (i <= 26) {
    print_list(table[i]);
    i++;
  }
}

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

  printf("Testing print_library\n");

  print_all();
 
  printf("====================================\n\n");

  printf("Testing print_letter\n");
  printf("p list\n");
  print_letters("p");
 
  printf("====================================\n\n");

  printf("Testing find:\n");
  searchS("alive","pearl jam");
  searchS("dead","pearl jam");
  printf("====================================\n\n");

  printf("Testing find artist:");
/* looking for [pearl jam] */
/*  artist found! pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | presidents of the united states of america: peaches | */
/* looking for [pink floyd] */
/*  artist found! pink floyd: time | presidents of the united states of america: peaches | */
/* looking for [bob dylan] */
/*  artist not found */
   searchA("pearl jam");
   searchA("pink floyd");
   searchA("bob dylan");
   printf("====================================\n\n");

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






















//add very later
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

