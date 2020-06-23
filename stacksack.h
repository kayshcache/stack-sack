#ifndef _STACKSACK_H_
#define _STACKSACK_H_

#include<string>
#include<map>

#include "collect.h"

template <typename T>
class Space {
	T _total;
	T _available;
public:
	void allocate(T size) { _total = size; _available = size; }
	T total() { return _total; }
	T available() { return _available; }
	T used() { return _total - _available; }
	// This is a functor that checks available space, adds
	// an object if there is, returns false if there is not.
	bool operator() (T object_size) {
		if (object_size > _available) {
			return false;
		}
		_available -= object_size;
		return true;
	}
};

class Stacksack {
	Space<int> _space;
	bool _is_open;
	std::string _packed;
	std::map<const std::string, int> _object_details;
	void display_sizes();
	void display_object_details();
	void record_detail(std::string);
	const char& push_to_pack(const char&);
public:
	template <typename T> void pack(T) noexcept;
	void set_size(const size_t&);
	bool get_open_status() { return _is_open; }
	void report();
};

#endif // _STACKSACK_H_
