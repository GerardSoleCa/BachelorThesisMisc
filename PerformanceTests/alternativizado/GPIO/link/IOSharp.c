#include "IOSharp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>

/* SPI */
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

/*

   ____ ____ ___ ___    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
  / ___|  _ |_ _/ _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
 | |  _| |_) | | | | | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
 | |_| |  __/| | |_| | |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
  \____|_|  |___\___/  |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/
                                                                     

*/

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

  len = sprintf(buf, SYSFS_GPIO_DIR "/gpio%d/value", gpio);

  fd = open(buf, O_RDWR);
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

uint64_t compute_time(){
    time_t current_time;
    //char* c_time_string;
 
    /* Obtain current time as seconds elapsed since the Epoch. */
    current_time = time(NULL);

    //printf("currenttime: %lf\n", ((double)current_time-25569.0)*86400.0);
    //return ((uint64_t)((double)current_time-25569.0)*86400.0);
    return (long) current_time;
    /*if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to compute the current time.");
    }*/
 
    /* Convert to local time format. */
   /* c_time_string = ctime(&current_time);
 
    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.");
    }*/
 
    /* Print to stdout. */
   /* (void) printf("Current time is %s", c_time_string);*/
}


uint64_t start_polling(int pin){
  //pin = 4;
  //printf("Start Polling\n");
  struct pollfd fdset;
  int nfds = 1;
  int gpio_fd, timeout, rc;
  char *buf[MAX_BUF], c;
  int len, count, i;
  long t;

  //int count=0;
  gpio_fd = gpio_fd_open(pin);

  // Clear any initial pending interrupt
  ioctl (gpio_fd, FIONREAD, &count) ;
  for (i = 0 ; i < count ; ++i)
  read (gpio_fd, &c, 1) ;

  timeout = POLL_TIMEOUT;

  //while (count <2) {
    //memset((void*)fdset, 0, sizeof(fdset));

    fdset.fd = gpio_fd;
    fdset.events = POLLPRI;

    read(fdset.fd,&buf,64);
    rc = poll(&fdset, 1, timeout);      

    //if (rc < 0) {
    //  printf("\nSomething fails!\n");
    //}

    //if (rc == 0) {
    //  printf(".");
    //}

    //if (fdset.revents & POLLPRI && rc > 0) {
      //len = read(fdset.fd, buf, MAX_BUF);
      //t = compute_time();
      //printf("\nGPIO %d interrupted\n", pin);
      //call("GPIO INTERRUPTED");
      read(fdset.fd,&buf,64);
    //}
    //fflush(stdout);
    //printf("%i\n", count);
    //count++;
  //}

    gpio_fd_close(gpio_fd);
    return t;
}

/*

  ____  ____ ___   _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
 / ___||  _ |_ _| |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
 \___ \| |_) | |  | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
  ___) |  __/| |  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
 |____/|_|  |___| |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ 
                                                                     

*/
static const char *device = "/dev/spidev0.0";
static int fd=-1;



static void pabort(const char *s)
{
  perror(s);
  abort();
}

void InternalWriteReadByte(unsigned char writeBuffer[], int writeOffset, int writeCount, unsigned char readBuffer[], int readOffset, int readCount, int startReadOffset, SPI_CONFIG spi)
{
  uint8_t mode;
  int ret;

  if(fd==-1){
    fd = open(device, O_RDWR);
    if (fd < 0)
      pabort("can't open device");
  }

  if(spi.mode == 0)
    mode = SPI_MODE_0;
  else if(spi.mode == 1)
    mode = SPI_MODE_1;
  else if(spi.mode == 2)
    mode = SPI_MODE_2;
  else
    mode = SPI_MODE_3;

  ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1)
    pabort("can't set spi mode");

  ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
  if (ret == -1)
    pabort("can't get spi mode");

  
  struct spi_ioc_transfer tr = {
    .tx_buf = (unsigned long)writeBuffer,
    .rx_buf = (unsigned long)readBuffer,
    .len = writeCount,
    .delay_usecs = spi.delay,
    .speed_hz = spi.speed,
    .cs_change = spi.cs_change,
    .bits_per_word = 8,
  };

  ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
  //close(fd);
}

void InternalWriteReadShort(unsigned short writeBuffer[], int writeOffset, int writeCount, unsigned short readBuffer[], int readOffset, int readCount, int startReadOffset, SPI_CONFIG spi)
{
  uint8_t mode;
  int ret;

  if(fd==-1){
    fd = open(device, O_RDWR);
    if (fd < 0)
      pabort("can't open device");
  }

  if(spi.mode == 0)
    mode = SPI_MODE_0;
  else if(spi.mode == 1)
    mode = SPI_MODE_1;
  else if(spi.mode == 2)
    mode = SPI_MODE_2;
  else
    mode = SPI_MODE_3;

  ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1)
    pabort("can't set spi mode");

  ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
  if (ret == -1)
    pabort("can't get spi mode");

  
  struct spi_ioc_transfer tr = {
    .tx_buf = (unsigned long)writeBuffer,
    .rx_buf = (unsigned long)readBuffer,
    .len = writeCount,
    .delay_usecs = spi.delay,
    .speed_hz = spi.speed,
    .cs_change = spi.cs_change,
    .bits_per_word = 16,
  };

  ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
  //close(fd);
}

int is_valid_fd(int fd)
{
    return fcntl(fd, F_GETFL) != -1 || errno != EBADF;
}
