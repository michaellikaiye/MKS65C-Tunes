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
  while(n) {
    printf("%s: %s | \n",n->artist,n->name);
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
  struct song_node *s = n;
  if (s == NULL){
    return NULL;
  }
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
    printf("artist found!\n");
    while (n->next != NULL){
       n = n -> next;
      if (strcmp(n->artist, artist) == 0)
	printf(" %s : %s  | \n", n->artist, n->name);
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


int main() {
  srand(time(NULL));
 printf("MUSIC LIBRARY TESTS\n");
   printf("====================================\n\n");
  
  add("thunderstruck","ac/dc"); 
  add("alive", "pearl jam");
  add("even flow", "pearl jam");
  add("yellow ledbetter", "pearl jam");
  add("time", "pink floyd");
  add("paranoid android", "radiohead");
  add("street spirit (fade out)", "radiohead");
  add("peaches", "president of the united states of america");
   printf("Testing print_library\n");
   print_all();
 
  printf("====================================\n\n");
   printf("Testing print_letter\n");
  printf("p list\n");
  print_letters('p');
  printf("testing print_songs");
  print_songs("pearl jam");
  printf("====================================\n\n");
   printf("Testing find:\n");
  searchS("alive","pearl jam");
  searchS("dead","pearl jam");
  printf("====================================\n\n");
   printf("Testing find artist:\n");
   searchA("pearl jam");
  searchA("pink floyd");
  searchA("bob dylan");
  printf("====================================\n\n");
   printf("Testing remove:\n");
   remove_song("alive","pearl jam");
  print_all();
  remove_song("time","pink floyd");
  print_all();
  printf("====================================\n\n");
    
  printf("Testing shuffle:\n");
  print_shuffle();
  printf("====================================\n\n");
   printf("Testing clear_library:\n");
   clear_library();
  print_all();
   printf("====================================\n\n");
   printf("Adding songs to empty library");
  add("alive", "pearl jam");
  add("time", "pink floyd");
  add("even flow", "pearl jam");
  add("yellow ledbetter", "pearl jam");
  add("time", "pink floyd");
  print_all();
   printf("====================================\n\n");
   printf("Testing print_artist:\n");
  searchA("pearl jam");
  searchA("ac/dc");
   printf("====================================\n\n");
   printf("Testing shuffle\n");
  print_shuffle();
   printf("====================================\n\n");
}
