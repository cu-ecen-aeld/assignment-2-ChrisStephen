#include "stdio.h"
#include "syslog.h"

int main(int argc, char **argv)
{
	FILE *fd;

	openlog(NULL, 0, LOG_USER);
	if (argc != 3)
	{
		syslog(LOG_ERR, "Usage: %s <writefile> <writestr>", argv[0]);
		closelog();
		return 1;
	}
	fd = fopen(argv[1], "w");
	if (fd == NULL)
	{
		syslog(LOG_ERR, "%s path does not exist", argv[1]);
		closelog();
		return 1;
	}
	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	fprintf(fd, "%s", argv[2]);
	fclose(fd);
	closelog();
	return 0;
}
