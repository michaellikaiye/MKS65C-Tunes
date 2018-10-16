/* dont know if necessary */
/* struct song_node { */
/*   char name[100]; */
/*   char artist[100]; */
/*   struct song_node *next; */
/* } song_node; */

struct song_node *table[27];

/* Sets up table with null values */
void setup();

/* Add song nodes. */
void add(char *song, char *artist);

/* Search for a song given song and artist name (return a pointer). */
struct song_node *searchS(char *song, char *artist);

/* Search for an artist. */
struct song_node *searchA(char *artist);

/* Print out all the entries under a certain letter. */
void print_letters(char letter);

/* Print out all the songs of a certain artist */
void print_songs(char *artist);

/* Print out the entire library. */
void print_all();

/* Shuffle - print out a series of randomly chosen songs. */
void print_shuffle();

/* Delete a song */
void delete(char *song);

/* Clear the library. */
void clear();
