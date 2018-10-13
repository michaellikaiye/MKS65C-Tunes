#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
  printf("%s: %s | ",n->artist,n->name);
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

  struct song_node *c = malloc(sizeof(struct song_node));
  c = n;
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
  struct song_node *c = malloc(sizeof(struct song_node));
  c = n;
  while(c != NULL && strcmp(artist, c->artist) != 0 && strcmp(name, c->name) != 0)
    c= c->next;
  return c;
}

/* find and return a pointer to the first song of an artist based on artist name */
struct song_node *find_artist(char *artist, struct song_node *n) {
  struct song_node *c = malloc(sizeof(struct song_node));
  c = n;
  while(c != NULL && strcmp(artist, c->artist) != 0)
    c= c->next;
  return c;
}

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
struct song_node *randomS(struct song_node *n) {
  return n;
}

/* remove a single specified node from the list */
struct song_node *removeS(struct song_node *head, struct song_node *no) {
  return head;
}

/* free the entire list */
struct song_node *clear(struct song_node *n) {
  return n;
}

int main() {
  printf("LINKED LIST TESTS\n");
  printf("====================================\n\n");
  
  printf("Testing print_list:\n");
  struct song_node *s0 = NULL;
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
  struct song_node *s1 = find_node("thuderstruck", "ac/dc", s0);
  print_node(s1);
  printf("\n====================================\n\n");

  printf("Testing find_node:\n");
  printf("looking for [pearl jam: even flow]\n");
  printf("node found! ");
  struct song_node *s2 = find_node("even flow", "pearl jam", s0);
  print_node(s2);
  printf("\nlooking for [pearl jam: daughter]\n");
  printf("node not found\n");
  struct song_node *s3 = find_node("daughter", "pearl jam", s0);
  print_node(s3);
  printf("\n====================================\n\n");

  printf("Testing find_artist:\n");
  printf("looking for [pink floyd]\n");
  printf("artist found! ");
  struct song_node *s4 = find_artist("pink floyd", s0);
  print_list(s4);
  printf("\nlooking for [pearl jam]\n");
  printf("artist found! ");
  struct song_node *s5 = find_artist("pearl jam", s0);
  print_list(s5);
  printf("\nlooking for [presidents of the united states of america]\n");
  struct song_node *s6 = find_artist("presidents of the united states of america", s0);
  printf("artist not found\n");
  print_list(s6);
  printf("====================================\n\n");

 printf("Testing songcmp (helper function):\n");
 printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
 printf("%d", songcmp("even flow", "pearl jam", "even flow", "pearl jam", s0));
 printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n");
 printf("%d", songcmp("even flow", "pearl jam", "alive", "pearl jam", s0));
 printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n");
 printf("%d", songcmp("alive", "pearl jam", "even flow", "pearl jam", s0));
 printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n");
 printf("%d", songcmp("even flow", "pearl jam", "time", "pink floyd", s0));
 printf("\n====================================\n");

/* Testing random: */
/* radiohead: paranoid android */
/* radiohead: street spirit (fade out) */
/* radiohead: street spirit (fade out) */
/* radiohead: paranoid android */
/* ==================================== */

/* Testing remove: */
/* Removing [pearl jam: alive] */
/*  ac/dc: thunderstruck | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* Removing [pearl jam: yellow ledbetter] */
/*  ac/dc: thunderstruck | pearl jam: even flow | pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* Removing [pink floyd: alive] */
/*  pearl jam - alive not found */
/* ac/dc: thunderstruck | pearl jam: even flow | pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* ==================================== */

/* Testing free_list */
/* freeing node: ac/dc - thunderstruck */
/* freeing node: pearl jam - even flow */
/* freeing node: pink floyd - time */
/* freeing node: radiohead - paranoid android */
/* freeing node: radiohead - street spirit (fade out) */
/* list after free_list: */
  
  return 0;
}
