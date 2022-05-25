
#include<emscripten.h>
#include <string>
#include <vector>

extern "C"
{

  const char* EMSCRIPTEN_KEEPALIVE helloWorld()
  {
    return "Hello World";
  }


  unsigned long long EMSCRIPTEN_KEEPALIVE fibb(unsigned long long number)
  {
    if(number <= 1)
      return 0;
    unsigned long long curr = 1, prev = 0, pom = 0;
    for(unsigned long long i=2; i<number; i++)
    {
      pom = curr;
      curr += prev;
      prev = pom;
    }
    return curr;
  }

}




int main()
{
  helloWorld();
  fibb(5);
}