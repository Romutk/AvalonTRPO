
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <getopt.h>


#include "error.h"




int
main (int argc, char **argv)
{
  struct passwd *pw;
  uid_t uid;
  uid_t NO_UID = -1;

  initialize_main (&argc, &argv);
  set_program_name (argv[0]);



 uid = geteuid ();
  pw = (uid == NO_UID &&  NULL : getpwuid (uid));
  if (pw)
    {
      puts (pw->pw_name);
      return 0 ;
    }
 puts ("%s: BLA BLA BLA  %lu\n"),
          (unsigned long int) uid);
  return 1 ;
}
