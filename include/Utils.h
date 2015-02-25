#ifndef _ATCUtils_
#define _ATCUtils_

#include <ctime>            // timeval
#include <unistd.h>         // STDIN_FILENO
#include <termios.h>        // tcgetattr
#include <sys/select.h>     // fd_set

struct termios oldterm, newterm;
void set_unbuffered ( void ) {
  tcgetattr( STDIN_FILENO, &oldterm );
  newterm = oldterm;
  newterm.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newterm );
}
void set_buffered ( void ) {
  tcsetattr( STDIN_FILENO, TCSANOW, &oldterm );
}

// kbhit() function
int kbhit ( void ) {
    int result;
    fd_set  set;
    struct timeval tv;

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO,&set);  /* watch stdin */
    tv.tv_sec = 0;
    tv.tv_usec = 0;             /* don't wait */

    /* quick peek at the input, to see if anything is there */
    set_unbuffered();
    result = select( STDIN_FILENO+1,&set,NULL,NULL,&tv);
    set_buffered();

    return result == 1;
}

#endif
