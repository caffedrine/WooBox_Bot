#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <random>
#include <ctime>

#include "util.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

std::string to_string(int val)
{
    std::ostringstream ss;
    ss << val;
    std::string str = ss.str();
    return str;
}

int to_int(std::string str)
{
	return atoi(str.c_str());
}

int getRandom(int min, int max)
{
    static boost::random::mt19937 gen(static_cast<unsigned> (std::time(0)));
    boost::random::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

