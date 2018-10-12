/* insert nodes at the front */
/* insert nodes in order */
/* alphabetical by Artist then by Song */
/* print the entire list */
/* find and return a pointer to a node based on artist and song name */
/* find and return a pointer to the first song of an artist based on artist name */
/* Return a pointer to random element in the list. */
/* remove a single specified node from the list */
/* free the entire list */
struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
} song_node;

struct song_node *insert_front(struct song_node *n, char name, char artist);//write para?
struct song_node *insert_inOrder(struct song_node *n, char name, char artist);
//finish later
