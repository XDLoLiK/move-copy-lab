#ifndef LOCATION_HPP
#define LOCATION_HPP

#define __LOCATION__ {__FILE__, __LINE__, __FUNCTION__}

struct Location_t {
	const char* file = nullptr;
	int line = 0;
	const char* func = nullptr;
};

#endif // LOCATION_HPP
