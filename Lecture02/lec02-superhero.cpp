// Lecture 2 example
// James Tuck
// August 28, 2018

// This is a class that can't be deleted
// because it has a private destructor
class Superman {
private:
  int x;
  // private destructor 
  ~Superman() {}

  // However, if we call this member function,
  // Superman could delete itself
  void kryptonite() {
    delete this;
  }  

public:
};

// main function to show the idea
int main()
{
  // create Superman object
  Superman *s = new Superman();
  // Uncomment the next line and recompile to see
  // that it will generate a syntax error
  //delete s; // doesn't work!
  return 0;
}
