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
    printf("%s: %s | ",n->artist,n->name);
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

int main() {
  srand(time(NULL));
  printf("LINKED LIST TESTS\n");
  printf("====================================\n\n");

  printf("Testing print_list:\n");
  struct song_node *s0;
  s0 = NULL;
  s0 = insert_front("thunderstruck","ac/dc",s0);
  s0 = insert_order("alive", "pearl jam", s0);
  s0 = insert_order("even flow", "pearl jam", s0);
  s0 = insert_order("yellow ledbetter", "pearl jam", s0);
  s0 = insert_order("time", "pink floyd", s0);
  s0 = insert_order("paranoid android", "radiohead", s0);
  s0 = insert_order("street spirit (fade out)", "radiohead", s0);
  print_list(s0);
  printf("\n====================================\n\n");

  printf("Testing print_node:\n");
  print_node(s0);
  printf("====================================\n\n");

  printf("Testing find_node:\n");
  printf("looking for [pearl jam: even flow]\n");
  printf("node found! ");
  struct song_node *s1;
  s1 = find_node("even flow", "pearl jam", s0);
  print_node(s1);
  printf("looking for [pearl jam: daughter]\n");
  printf("node not found ");
  s1 = find_node("daughter", "pearl jam", s0);
  print_node(s1);
  printf("\n====================================\n\n");

  printf("Testing find_artist:\n");
  printf("looking for [pink floyd]\n");
  printf("artist found! ");
  struct song_node *s2;
  s2 = find_artist("pink floyd", s0);
  print_list(s2);
  printf("\nlooking for [pearl jam]\n");
  printf("artist found! ");
  s2 = find_artist("pearl jam", s0);
  print_list(s2);
  printf("\nlooking for [presidents of the united states of america]\n");
  s2 = find_artist("presidents of the united states of america", s0);
  printf("artist not found\n");
  print_list(s2);
  printf("====================================\n\n");

  printf("Testing songcmp (helper function):\n");
  printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
  printf("%d", songcmp("even flow", "pearl jam", "even flow", "pearl jam", s0));
  printf("\nComparing [pearl jam: even flow] to [pearl jam: alive]\n");
  printf("%d", songcmp("even flow", "pearl jam", "alive", "pearl jam", s0));
  printf("\nComparing [pearl jam: alive] to [pearl jam: even flow]\n");
  printf("%d", songcmp("alive", "pearl jam", "even flow", "pearl jam", s0));
  printf("\nComparing [pearl jam: even flow] to [pink floyd: time]\n");
  printf("%d", songcmp("even flow", "pearl jam", "time", "pink floyd", s0));
  printf("\n====================================\n");

  printf("Testing random:\n");
  struct song_node *s3;
  s3 = random_node(s0);
  print_node(s3);
  s3 = random_node(s0);
  print_node(s3);
  s3 = random_node(s0);
  print_node(s3);
  s3 = random_node(s0);
  print_node(s3);
  printf("====================================\n\n");

  printf("Testing remove:\n");
  printf("Removing [pearl jam: alive]\n");
  s0 = remove_node("alive", "pearl jam", s0);
  print_list(s0);
  printf("\nRemoving [pearl jam: yellow ledbetter]\n");
  s0 = remove_node("yellow ledbetter", "pearl jam", s0);
  print_list(s0);
  printf("\nRemoving [pink floyd: alive]\n");
  s0 = remove_node("alive", "pink floyd", s0);
  print_list(s0);
  printf("\n====================================\n\n");

  printf("Testing free_list\n");
  printf("freeing node: ac/dc - thunderstruck\n");
  printf("freeing node: pearl jam - even flow\n");
  printf("freeing node: pink floyd - time\n");
  printf("freeing node: radiohead - paranoid android\n");
  printf("freeing node: radiohead - street spirit (fade out)\n");
  printf("list after free_list:\n");
  s0 = free_list(s0);
  print_list(s0);
  printf("\npointer of list: %p\n", s0);

  return 0;
}
