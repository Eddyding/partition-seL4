/* @LICENSE(MUSLC_MIT) */

#include <spawn.h>
#include <stdlib.h>
#include <errno.h>
#include "fdop.h"

int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *fa, int fd, int newfd)
{
	struct fdop *op = malloc(sizeof *op);
	if (!op) return ENOMEM;
	op->cmd = FDOP_DUP2;
	op->fd = fd;
	op->newfd = newfd;
	if ((op->next = fa->__actions)) op->next->prev = op;
	op->prev = 0;
	fa->__actions = op;
	return 0;
}
