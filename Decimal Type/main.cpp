#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>


typedef struct decimal
{
    int value;
    int point;
	bool is_negative;
} decimal;

float decimal_to_float(decimal x);

int main(void) {
	decimal a;
	a.value = 12345;
	a.point = 3;
	decimal_to_float(a);
	return 0;
}

//fifo or lifo????
float decimal_to_float(decimal x) {
    int value = x.value;
    std::string result;
	int count = 0;
    std::string dec;
    std::string tmp = std::to_string(x.value);
	int length = std::to_string(value).length();
    if (x.point != 0) {
        while (count <= x.point) {
            dec = dec + tmp[length - count];
			count++;

        }
    }
	tmp = tmp.substr(0 , length - x.point);
	
	std::reverse(dec.begin(), dec.end());
	result = tmp + "." + dec;
	std::cout << "result:" << result;
	return std::stof(result);
}


