#include <string.h>
class Factory: public ObjectFactory {
public:
	Jordan *createJordan(char *type) {
		if(strcmp(type,"Object2") == 0) {
 			return new Object2;
		}
		else if(strcmp(type,"Object1") == 0) {
			return new Object1;
		}
	}
};
