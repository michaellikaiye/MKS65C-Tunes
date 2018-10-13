/* list.h */

struct song_node { 
  char name[100];
  char artist[100];
  struct song_node *next;
};

/* print the entire list */
void print_list(struct song_node *n);

/* print a node */
void print_node(struct song_node *n);

/* insert nodes at the front */
struct song_node *insert_front(char name[100], char artist[100], struct song_node *n);

/* insert nodes in order */
/* alphabetical by Artist then by Song */
struct song_node *insert_order(char name[100], char artist[100], struct song_node *n);

/* find and return a pointer to a node based on artist and song name */
struct song_node *find_node(char *song, char *artist, struct song_node *n);

/* find and return a pointer to the first song of an artist based on artist name */
struct song_node *find_artist(char *artist, struct song_node *n);

/* Return a pointer to random element in the list. */
struct song_node *random(struct song_node *n);

/* remove a single specified node from the list */
struct song_node *remove(struct song_node head, struct song_node no);

/* free the entire list */
struct song_node *clear(struct song_node n);
