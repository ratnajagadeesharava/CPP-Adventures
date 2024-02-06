#include "lambdas.h"

auto is_divisible_by_10 = [divisor = 0](int dividend) {
	return dividend % divisor; 
	};