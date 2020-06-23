#include "stacksack.h"

/////////////// HELPER //////////////////
auto make_detail_key = [](const char & c, const size_t & i) -> std::string {
	std::string detail_key { c, ' ', ':', ' ' };
	detail_key.append(std::to_string(i));
	return detail_key;
};

/////////////// CONSTRUCTOR /////////////
/* Opted for no custom constructor for RAII reasons of safety
 * New Stacksack objects must be setup after instantiation
 * using the Stacksack::set_size() public method.
*/

/////////////// PUBLIC METHODS //////////////////
template <typename T>
void Stacksack::pack(T obj) noexcept
{
	const size_t sizeof_object = sizeof(obj);
	if (_space(sizeof_object))
		record_detail(make_detail_key(push_to_pack(obj.getName()), sizeof_object));
	else
		_is_open = false;
}

void Stacksack::set_size(const size_t & size)
{
	_space.allocate(size);
	_is_open = _space.available() > 0 ? true : false;
}

void Stacksack::report()
{
	display_sizes();
	std::cout << _packed <<  std::endl;
	display_object_details();
}

////////////// PRIVATE METHODS //////////////////
void Stacksack::display_sizes()
{
	std::cout << "Stacksack size: " << _space.total() << std::endl;
	std::cout << "Added object size: " << _space.used() << std::endl;
}

void Stacksack::display_object_details()
{
	if (_object_details.empty())
		std::cout << "No object details recorded" << std::endl;
	else
		for (const auto & kvp : _object_details)
			std::cout << kvp.first << ", " << kvp.second << std::endl;
}

void Stacksack::record_detail(std::string detail_key)
{
	// Return from map::insert is a pair<iter*, bool>, the
	// iter* can be used to locate the element and increment
	// the count of objects if found to be previously added.
	auto result_pair = _object_details.insert({ detail_key, 1 });
	if (!result_pair.second)
		result_pair.first->second++;
}

const char & Stacksack::push_to_pack(const char & instance_t)
{
	_packed.push_back(instance_t);
	return _packed.back();
}
