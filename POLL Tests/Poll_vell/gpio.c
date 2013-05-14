#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

 /****************************************************************
 * Constants
 ****************************************************************/
 
#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (-1) /* 3 seconds */
#define MAX_BUF 64

/****************************************************************
 * gpio_fd_open
 ****************************************************************/

int gpio_fd_open(unsigned int gpio)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);
 
  fd = open(buf, O_RDONLY | O_NONBLOCK );
  if (fd < 0) {
    perror("gpio/fd_open");
  }
  return fd;
}

/****************************************************************
 * gpio_fd_close
 ****************************************************************/

int gpio_fd_close(int fd)
{
  return close(fd);
}

typedef void (*callback)(char* str);

void start_polling(int pin, callback call){
  struct pollfd fdset[1];
  int nfds = 2;
  int gpio_fd, timeout, rc;
  char *buf[MAX_BUF];
  int len;

  int count=0;

  gpio_fd = gpio_fd_open(pin);

  timeout = POLL_TIMEOUT;
 
  while (1) {
    memset((void*)fdset, 0, sizeof(fdset));

    fdset[0].fd = gpio_fd;
    fdset[0].events = POLLPRI;

    rc = poll(fdset, nfds, timeout);      

    if (rc < 0) {
      printf("\nSomething fails!\n");
    }
      
    if (rc == 0) {
      printf(".");
    }
            
    if (fdset[0].revents & POLLPRI) {
      len = read(fdset[0].fd, buf, MAX_BUF);
      //printf("\nGPIO %d interrupted\n", pin);
      call("GPIO INTERRUPTED");
    }
    fflush(stdout);
    printf("%i\n", count);
    count++;
  }

  gpio_fd_close(gpio_fd);
}

/****************************************************************
 * Main
 ****************************************************************/
/*int main(int argc, char **argv, char **envp)
{
  if (argc < 2) {
    printf("Usage: gpio-int <gpio-pin>\n\n");
    printf("Waits for a change in the GPIO pin voltage level or input on stdin\n");
    exit(-1);
  }

  gpio = atoi(argv[1]);

  start_polling(gpio);

  
  return 0;
}*/