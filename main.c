#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"library.h"
#include"list.h"

/* LINKED LIST TESTS */
/* ==================================== */

/* Testing print_list: */
/*  ac/dc: thunderstruck | pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* ==================================== */

/* Testing print_node: */
/*  ac/dc: thunderstruck */
/* ==================================== */

/* Testing find_node: */
/* looking for [pearl jam: even flow] */
/*  node found! pearl jam: even flow */
/* looking for [pearl jam: daughter] */
/*  node not found */
/* ==================================== */

/* Testing find_artist: */
/* looking for [pink floyd] */
/*  artist found! pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* looking for [pearl jam] */
/*  artist found! pearl jam: alive | pearl jam: even flow | pearl jam: yellow ledbetter | pink floyd: time | radiohead: paranoid android | radiohead: street spirit (fade out) |  */
/* looking for [presidents of the united states of america] */
/*  artist not found */
/* ==================================== */

/* Testing songcmp (helper function): */
/* Comparing [pearl jam: even flow] to [pearl jam: even flow] */
/*  0 */
/* Comparing [pearl jam: even flow] to [pearl jam: alive] */
/*  4 */
/* Comparing [pearl jam: alive] to [pearl jam: even flow] */
/*  -4 */
/* Comparing [pearl jam: even flow] to [pink floyd: time] */
/*  -4 */
/* ==================================== */

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
