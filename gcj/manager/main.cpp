// Based on fushar's post
//
// So, for example, here is how I work on problem A:
//   Write the solution as A.cpp.
//   Build it into A.
//   Download the small input file.
//   Run “gcj A small” and watch the tee output.
//   Submit the output file and source code.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf [1024];

int fail()
{
	printf("Usage: coj <problem> (small [<attempt>] | large [<type>])\n");
	printf("Examples:\n");
	printf("\tcoj A small\n");
	printf("\tcoj A small l\n");
	printf("\tcoj B large\n");
	printf("\tcoj B large l\n");
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc >= 3 && !strcmp(argv[2], "small")) {
		int attempt = 0;
		if (argc == 4) {
			sscanf(argv[3], "%d", &attempt);
		}
		else if (argc > 4) {
			return fail();
		}
		sprintf(
			buf, 
			"./%s < %s-small-attempt%d.in | tee %s-small-attempt%d.out",
			argv[1],
			argv[1],
			attempt,
			argv[1],
			attempt);
		system(buf);
	}
	else if (argc >= 3 && !strcmp(argv[2], "large")) { 
		if (argc == 3) {
			sprintf(
				buf,
				"./%s < %s-large.in | tee %s-large.out",
				argv[1],
				argv[1],
				argv[1]);
		}
		else if (argc == 4) {
			sprintf(
				buf,
				"./%s < %s-large-%s.in | tee %s-large-%s.out",
				argv[1],
				argv[1],
				argv[3],
				argv[1],
				argv[3]);
		}
		system(buf);
	}
	else {
		return fail();
	}

	return 0;
}


