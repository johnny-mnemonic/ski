#ifndef _SKI_SYSCALL_API_H
#define _SKI_SYSCALL_API_H

/*
 * These APIs have to be implemented by OS backends.
 * Usually in src/<OS>/syscall-<OS>.c files.
 */

#include <stdio.h>

#include "types.h"

char *getSrcLines(ADDR ofs, unsigned *count);

void signal_invoke_handler (int in_syscall);
int signal_pending(void);
void signal_queue_info(int signal, ADDR ip);
void signal_return (void);

void initDwUnitTbl (int fd);
char * getSrcName (ADDR ofs);

void profCnt (void);

void doSyscall (HWORD num, REG arg0, REG arg1, REG arg2, REG arg3, REG arg4,
		REG arg5, REG arg6, REG arg7, REG *ret, REG *status);

void saveOpenFiles(FILE *f);
void restoreOpenFile(char *name, unsigned oflag, unsigned mode, unsigned offset);

void readConsole(char *buf);
void writeConsole(char *buf, size_t len);

/* Sets up a file descriptor mapping from fd1 to fd2 */
void setFdmap(int fd1, int fd2);

#endif /* _SKI_SYSCALL_API_H */
