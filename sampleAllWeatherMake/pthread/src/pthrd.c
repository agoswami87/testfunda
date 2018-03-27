#include<pthrd.h>

       void *
              thread_start(void *arg)
           {
                      struct thread_info *tinfo = arg;
                      char *uargv, *p;
           
                      printf("Thread %d: top of stack near %p; argv_string=%s\n",
                                                 tinfo->thread_num, &p, tinfo->argv_string);
           
                      uargv = strdup(tinfo->argv_string);
                      if (uargv == NULL)
                          handle_error("strdup");
           
                      for (p = uargv; *p != '\0'; p++)
                          *p = toupper(*p);
           
                      return uargv;
                  }
