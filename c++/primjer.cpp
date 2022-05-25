#include <iostream>
#include <string>
#include <vector>

extern "C"
{

  const char* helloWorld()
  {
    return "Hello World";
  }


  unsigned long fibb(int number)
  {
    if(number == 1)
        return 0;
    unsigned long curr = 1, prev = 0, pom = 0;
    for(unsigned long i=2; i<number; i++)
    {
      pom = curr;
      curr += prev; // 0 1 1 2 3
      prev = pom;
    }
    return curr;
  }

}




int main(int argc, char** argv)
{
    int broj = atoi(argv[1]);
  helloWorld();
  std::cout<< fibb(broj)<< std::endl;
}