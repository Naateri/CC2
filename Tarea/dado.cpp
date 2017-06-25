#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Dado{
public:
	operator()(int n){
		srand(time(NULL));
		return 1 + rand()%n;
	}
};
