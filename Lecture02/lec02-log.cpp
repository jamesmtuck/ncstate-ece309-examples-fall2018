// Lecture 2 example
// James Tuck
// August 28, 2018

// Create an object that logs messages to a file.
// On construction, it opens a file, and on destruction,
// it closes the file.

#include <stdio.h>

class Log {
  FILE *log_file;
public:
  // Construct an object
  Log(const char *filename)
  {
    // open the file
    log_file = fopen(filename,"w");
    // if we fail to open the file, write to stdout (the screen)
    if (log_file == NULL)
      log_file = stdout;

    message("logging started.\n");
  }
  // When object is destroyed, close the file
  ~Log() 
  {
    message("logging ended.\n");
    fclose(log_file);
  }
  // public member function for writing messages to the 
  // log file
  void message(const char *message) {
    fprintf(log_file,"%s", message);
  }
};

// Create a global logging object; object gets created
// before main starts
Log l("logfile.txt");

// main function to demonstrate how to use the log
// since l is a global, we can immediately start
// using it when we enter main.
int main()
{
  l.message("main is running.\n");
  l.message("main is finishing.\n");
  return 0;
}
