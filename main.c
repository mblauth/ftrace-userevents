#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void marker(int fd, char const * buf);

int main(int argc, char ** argv) {
  int fd = open("/sys/kernel/debug/tracing/trace_marker", O_WRONLY);
  if (fd == -1) {
    printf("opening marker-interface failed, debugfs not mounted?\n");
    exit(1);
  }

  for (int i = 0; i < INT_MAX; i++);
  marker(fd, "foo\n");
  for (int i = 0; i < INT_MAX; i++);
  marker(fd, "bar\n");
  for (int i = 0; i < INT_MAX; i++);
  close(fd);
}

void marker(int fd, char const * buf) {
  size_t length = strlen(buf);
  if (write(fd, buf, length) != length) {
    printf("setting marker failed\n");
  }
}

