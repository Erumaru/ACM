#include "testlib.h"

int main(int argc, char * argv[])
{
   setName("compare two signed int32 numbers");
   registerTestlibCmd(argc, argv);

   int ja = ans.readInt();
   int pa = ouf.readInt();

   if (ja != pa)
       quitf(_wa, "expected %d, found %d", ja, pa);

   quitf(_ok, "answer is %d", ja);
}