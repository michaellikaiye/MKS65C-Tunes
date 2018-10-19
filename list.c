#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

/* print the entire list */
void print_list(struct song_node *n) {
  while(n) {
    printf("%s: %s |\n",n->artist,n->name);
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
