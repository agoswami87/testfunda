#include<pthrd.h>
int
       main(int argc, char *argv[])
           {
                      int s, tnum, opt, num_threads;
                      struct thread_info *tinfo;
                      pthread_attr_t attr;
                      int stack_size;
                      void *res;
                        printf("is it printing"); 
                      /* The "-s" option specifies a stack size for our threads */
           
                      stack_size = -1;
                      while ((opt = getopt(argc, argv, "s:")) != -1) {
                                     switch (opt) {
                                                    case 's':
                                                        stack_size = strtoul(optarg, NULL, 0);
                                                        break;
                                     
                                                    default:
                                                        printf("Usage: %s [-s stack-size] arg...\n",
                                                                                           argv[0]);
                                                        exit(EXIT_FAILURE);
                                                    }
                                 }
           
                      num_threads = argc - optind;
           
                      /* Initialize thread creation attributes */
           
                      s = pthread_attr_init(&attr);
                      if (s != 0)
                          handle_error_en(s, "pthread_attr_init");
           
                      if (stack_size > 0) {
                                     s = pthread_attr_setstacksize(&attr, stack_size);
                                     if (s != 0)
                                         handle_error_en(s, "pthread_attr_setstacksize");
                                 }
           
                      /* Allocate memory for pthread_create() arguments */
           
                      tinfo = calloc(num_threads, sizeof(struct thread_info));
                      if (tinfo == NULL)
                          handle_error("calloc");
           
                      /* Create one thread for each command-line argument */
           
                      for (tnum = 0; tnum < num_threads; tnum++) {
                                     tinfo[tnum].thread_num = tnum + 1;
                                     tinfo[tnum].argv_string = argv[optind + tnum];
                      
                                     /* The pthread_create() call stores the thread ID into
                                      *                   corresponding element of tinfo[] */
                      
                                     s = pthread_create(&tinfo[tnum].thread_id, &attr,
                                                                               &thread_start, &tinfo[tnum]);
                                     if (s != 0)
                                         handle_error_en(s, "pthread_create");
                                 }
           
                      /* Destroy the thread attributes object, since it is no
                       *               longer needed */
           
                      s = pthread_attr_destroy(&attr);
                      if (s != 0)
                          handle_error_en(s, "pthread_attr_destroy");
           
                      /* Now join with each thread, and display its returned value */
           
                      for (tnum = 0; tnum < num_threads; tnum++) {
                                     s = pthread_join(tinfo[tnum].thread_id, &res);
                                     if (s != 0)
                                         handle_error_en(s, "pthread_join");
                      
                                     printf("Joined with thread %d; returned value was %s\n",
                                                                    tinfo[tnum].thread_num, (char *) res);
                                     free(res);      /* Free memory allocated by thread */
                                 }
           
                      free(tinfo);
                      exit(EXIT_SUCCESS);
                  }
