#include "iif.h"
#include <iostream>
using namespace std;
using namespace iif;

int loopFunction(int _reserved_input_[]) {
	int x = _reserved_input_[0];
	int n = _reserved_input_[1];

	iif_assume(x==0 && n>0);

	while(x<n) {
		recordi(x, n);
		x++;
		
	}
	recordi(x, n);

	iif_assert(x==n);

	return 0;
}

int main(int argc, char** argv) {
	iifround = atoi(argv[1]);
	initseed = atoi(argv[2]);
	iifContext context("/home/lijiaying/Research/zilu/tmp/11.var", loopFunction, "loopFunction", "/home/lijiaying/Research/zilu/tmp/11.ds");
	context.addLearner("linear");
	return context.learn("/home/lijiaying/Research/zilu/tmp/11.cnt", "/home/lijiaying/Research/zilu/tmp/11");
}

