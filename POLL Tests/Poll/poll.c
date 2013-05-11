#include <stdio.h>
#include <fcntl.h>
#include <poll.h>

 /****************************************************************
 * Constants
 ****************************************************************/
 
//#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define SYSFS_GPIO_DIR "GPIO"
#define POLL_TIMEOUT (30 * 1000) /* 3 seconds */
#define MAX_BUF 64

int main(int argc, char **argv, char **envp){

  struct pollfd fdset[2];
  int nfds = 2;
  int gpio_fd, timeout, rc;
  char *buf[MAX_BUF];
  unsigned int gpio;
  int len;

  if (argc < 2) {
    printf("Usage: gpio-int <gpio-pin>\n\n");
    printf("Waits for a change in the GPIO pin voltage level or input on stdin\n");
    exit(-1);
  }


  gpio = atoi(argv[1]);
  gpio_fd = gpio_fd_open(gpio);

  timeout = POLL_TIMEOUT;
      
  fdset[0].fd = gpio_fd;
  fdset[0].events = POLLPRI | POLLERR;

printf("timeout: %i\n", timeout);
  rc = poll(fdset, nfds, timeout);  

  if (rc < 0) {
      printf("\npoll() failed!\n");
      return -1;
  }
      
  if (rc == 0) {
      printf(".");
  }
            
  if (fdset[0].revents & POLLPRI) {
      len = read(fdset[1].fd, buf, MAX_BUF);
      printf("\npoll() GPIO %d interrupt occurred\n", gpio);
  }

  if (fdset[0].revents & POLLIN) {
      (void)read(fdset[0].fd, buf, 1);
      printf("POLLIN");
  }

  printf("%i\n", rc);
  printf("%i\n", fdset[0].revents);
    /*struct pollfd pfd;
    pfd.fd = open("GPIO", O_RDONLY|O_NONBLOCK);
    pfd.events = POLLIN | POLLPRI;
    int a = poll(&pfd, 1, -1);
    printf("%i\n", a);
    return 0;*/
}

int gpio_fd_open(unsigned int gpio)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR /*"/gpio%d/value"*/, gpio);
 
  fd = open(buf, O_RDONLY | O_NONBLOCK );
  if (fd < 0) {
    perror("gpio/fd_open");
  }
  return fd;
}

int gpio_fd_close(int fd)
{
  return close(fd);
}