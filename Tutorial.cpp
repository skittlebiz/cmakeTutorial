#include "TutorialConfig.h"
#include "subexe.h"
#include <iostream>
#ifdef USE_MYMATH
   #include "MathFunctions/MathFunctions.h"
#else
   #include <cmath>
#endif

using std::cout;
using std::endl;
int main(int argc, char** argv)
{
   sayHello();
   if (argc < 2)
   {
      cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
           << Tutorial_VERSION_MINOR << endl;
      cout << "Usage: " << argv[0] << " number" << endl;
   }
   const double inputValue = std::stod(argv[1]);
#ifdef USE_MYMATH
   double afterVal = mysqrt(inputValue);
#else
   double afterVal = std::sqrt(inputValue);
#endif
   cout << " afterVal  = " << afterVal  << endl;

   return 1;
}