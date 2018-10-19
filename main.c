#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include "library.h"
#include "list.h"

int main() {
  srand(time(NULL));
  /* printf("LINKED LIST TESTS\n"); */
  /* printf("====================================\n\n"); */

  /* printf("Testing print_list:\n"); */
  /* struct song_node *s0; */
  /* s0 = NULL; */
  /* s0 = insert_front("thunderstruck","ac/dc",s0); */
  /* s0 = insert_order("alive", "pearl jam", s0); */
  /* s0 = insert_order("even flow", "pearl jam", s0); */
  /* s0 = insert_order("yellow ledbetter", "pearl jam", s0); */
  /* s0 = insert_order("time", "pink floyd", s0); */
  /* s0 = insert_order("paranoid android", "radiohead", s0); */
  /* s0 = insert_order("street spirit (fade out)", "radiohead", s0); */
  /* print_list(s0); */
  /* printf("\n====================================\n\n"); */

  /* printf("Testing print_node:\n"); */
  /* print_node(s0); */
  /* printf("====================================\n\n"); */

  /* printf("Testing find_node:\n"); */
  /* printf("looking for [pearl jam: even flow]\n"); */
  /* printf("node found! "); */
  /* struct song_node *s1; */
  /* s1 = find_node("even flow", "pearl jam", s0); */
  /* print_node(s1); */
  /* printf("looking for [pearl jam: daughter]\n"); */
  /* printf("node not found "); */
  /* s1 = find_node("daughter", "pearl jam", s0); */
  /* print_node(s1); */
  /* printf("\n====================================\n\n"); */

  /* printf("Testing find_artist:\n"); */
  /* printf("looking for [pink floyd]\n"); */
  /* printf("artist found! "); */
  /* struct song_node *s2; */
  /* s2 = find_artist("pink floyd", s0); */
  /* print_list(s2); */
  /* printf("\nlooking for [pearl jam]\n"); */
  /* printf("artist found! "); */
  /* s2 = find_artist("pearl jam", s0); */
  /* print_list(s2); */
  /* printf("\nlooking for [presidents of the united states of america]\n"); */
  /* s2 = find_artist("presidents of the united states of america", s0); */
  /* printf("artist not found\n"); */
  /* print_list(s2); */
  /* printf("====================================\n\n"); */

  /* printf("Testing songcmp (helper function):\n"); */
  /* printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n"); */
  /* printf("%d", songcmp("even flow", "pearl jam", "even flow", "pearl jam", s0)); */
  /* printf("\nComparing [pearl jam: even flow] to [pearl jam: alive]\n"); */
  /* printf("%d", songcmp("even flow", "pearl jam", "alive", "pearl jam", s0)); */
  /* printf("\nComparing [pearl jam: alive] to [pearl jam: even flow]\n"); */
  /* printf("%d", songcmp("alive", "pearl jam", "even flow", "pearl jam", s0)); */
  /* printf("\nComparing [pearl jam: even flow] to [pink floyd: time]\n"); */
  /* printf("%d", songcmp("even flow", "pearl jam", "time", "pink floyd", s0)); */
  /* printf("\n====================================\n"); */

  /* printf("Testing random:\n"); */
  /* struct song_node *s3; */
  /* s3 = random_node(s0); */
  /* print_node(s3); */
  /* s3 = random_node(s0); */
  /* print_node(s3); */
  /* s3 = random_node(s0); */
  /* print_node(s3); */
  /* s3 = random_node(s0); */
  /* print_node(s3); */
  /* printf("====================================\n\n"); */

  /* printf("Testing remove:\n"); */
  /* printf("Removing [pearl jam: alive]\n"); */
  /* s0 = remove_node("alive", "pearl jam", s0); */
  /* print_list(s0); */
  /* printf("\nRemoving [pearl jam: yellow ledbetter]\n"); */
  /* s0 = remove_node("yellow ledbetter", "pearl jam", s0); */
  /* print_list(s0); */
  /* printf("\nRemoving [pink floyd: alive]\n"); */
  /* s0 = remove_node("alive", "pink floyd", s0); */
  /* print_list(s0); */
  /* printf("\n====================================\n\n"); */

  /* printf("Testing free_list\n"); */
  /* printf("freeing node: ac/dc - thunderstruck\n"); */
  /* printf("freeing node: pearl jam - even flow\n"); */
  /* printf("freeing node: pink floyd - time\n"); */
  /* printf("freeing node: radiohead - paranoid android\n"); */
  /* printf("freeing node: radiohead - street spirit (fade out)\n"); */
  /* printf("list after free_list:\n"); */
  /* s0 = free_list(s0); */
  /* print_list(s0); */
  /* printf("\npointer of list: %p\n", s0); */

  

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

  printf("Adding songs to empty library\n");
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
  
  return 0;
}
