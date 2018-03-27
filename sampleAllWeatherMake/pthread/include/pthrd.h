       #include <pthread.h>
       #include <string.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <errno.h>
       #include <ctype.h>

       #define handle_error_en(en, msg) \
                   do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

       #define handle_error(msg) \
                   do { perror(msg); exit(EXIT_FAILURE); } while (0)

       struct thread_info {    /* Used as argument to thread_start() */
                  pthread_t thread_id;        /* ID returned by pthread_create() */
                  int       thread_num;       /* Application-defined thread # */
                  char     *argv_string;      /* From command-line argument */
              };

       /* Thread start function: display address near top of our stack,
        *           and return upper-cased copy of argv_string */
       void * thread_start(void *arg);
