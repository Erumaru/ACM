#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int k = inf.readInt(1, 50, "k");
    inf.readEoln();
    inf.readToken("[a-z]{1,100000}", "s");
    inf.readEoln();
    inf.readEof();
}