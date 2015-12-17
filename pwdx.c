#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int check_pid_argument(char *input)
{
	int skip = 0;
	long pid;
	char *end = NULL;

	pid = strtol(input + skip, &end, 10);

	return 0;
}

int main(int argc, char *argv[])
{
	int ch;
	int retval = 0, i;
	int alloclen = 128;
	char *pathbuf;

	};



	argc -= optind;
	argv += optind;


	for (i = 0; i < argc; i++) {
		char *s;
		ssize_t len, buflen;
		char *buf;
		buflen = 10 + strlen(argv[i]) + 1;
		buf = xmalloc(buflen);

		if (argv[i][0] != '/')
			snprintf(buf, buflen, "/proc/%s/cwd", argv[i]);
		else
			snprintf(buf, buflen, "%s/cwd", argv[i]);

		while ((len = readlink(buf, pathbuf, alloclen)) == alloclen) {
			alloclen *= 2;
			pathbuf = realloc(pathbuf, alloclen);
		}

			 if (len < 0) {
                	        s = strerror( errno);
                       		 retval =1 ;
                        fprintf(stderr, "%s: %s\n", argv[i], s);
                        continue;
                } else {
                        pathbuf[len] = 0;
                        s = pathbuf;
                }

                printf("%s: %s\n", argv[i], s);
        }
        free(pathbuf);
        return retval;
}

