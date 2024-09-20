#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct rlimit  old;
	if (getrlimit(RLIMIT_CPU, &old) == -1)
	       err(EXIT_FAILURE, "prlimit-1");
	printf("Previous limits: soft=%jd; hard=%jd\n",
           (intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);
}
