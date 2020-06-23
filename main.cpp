#include<iostream>
#include<exception> // std::exception, std::out_of_range
#include<cstring> // strlen, isdigit
#include<cerrno> // errno, strerror

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m" 
#define PURPLE "\033[95m" 

#include "collect.h"
#include "stacksack.h"
#include "stacksack.cpp"

void verify_arguments(int&, char**);
void select_for_packing(const char&, Stacksack&);
const char * get_error_msg(unsigned);

class Exception : public std::exception {
	const char * _type;
	const char * _help;
	Exception();
public:
	Exception(const char*, const char* err = "fatal error") throw();
	const char * what() const throw();
};


int main(int argc, char * argv[])
{
	unsigned seed; // throws(out_of_range)
	int termination_code = 0;
	try {
		verify_arguments(argc, argv); // throws(Exception)
		const unsigned size = std::stoi(argv[1]); // throws(out_of_range)
		seed = std::stoi(argv[2]); // throws(out_of_range)
		Stacksack my_stacksack;
		my_stacksack.set_size(size);

		while (my_stacksack.get_open_status()) // Returns false if prior obj didn't fit.
			select_for_packing(generate(seed), my_stacksack); // throws(Exception)

		my_stacksack.report();

	} catch (const Exception & e) {
		std::cerr << e.what() << std::endl;
		termination_code = EXIT_FAILURE;
	} catch (std::out_of_range & oor) {
		Exception out_of_range(strerror(errno));
		std::cerr << out_of_range.what() << std::endl;
		termination_code = errno;
	} catch (...) {
		Exception unknown(strerror(errno));
		std::cerr << unknown.what() << std::endl;
		termination_code = errno;
	}

		return termination_code;
}

/*
const auto object_builder = [&](int seed) {
	switch(generate(seed)) {
	case 'A': return A();
	case 'B': return B();
	case 'C': return C();
	case 'D': return D();
	case 'E': return E();
	case 'F': return F();
	case 'G': return G();
	default:
		throw Exception(get_error_msg(222), "unexpected object");
		break;
	}
};
*/
void select_for_packing(const char & type, Stacksack & stacksack)
{
	switch(type) {
	case 'A':
		stacksack.pack(A());
		break;
	case 'B':
		stacksack.pack(B());
		break;
	case 'C':
		stacksack.pack(C());
		break;
	case 'D':
		stacksack.pack(D());
		break;
	case 'E':
		stacksack.pack(E());
		break;
	case 'F':
		stacksack.pack(F());
		break;
	case 'G':
		stacksack.pack(G());
		break;
	default:
		throw Exception(get_error_msg(222), "unexpected object");
		break;
	}
}

/* * * Error checking and exception handling definitions * * */

auto warn = [](const char * msg) -> void {
	std::cout << BOLD << "KAP: " << PURPLE << "warning: " << RESET << msg << std::endl;
	std::cout << "relunctantly proceeding with stacksack compilation\n..." << std::endl;
};

const char * get_error_msg(unsigned errnum)
{
	switch (errnum) {
	case 201:
		return "requires 2 arguments size and seed; eg. $ ~ ./KAP 23 42";
	case 202:
		return "size must be greater than zero";
	case 203:
		return "size and seed must be natural numbers";
	case 222:
		return "tried to pack undefined object type";
	default:
		return "see if you can do that again";
	}
}

void verify_arguments(int & c, char **argv)
{
	if (c != 3)
		throw Exception(get_error_msg(201), "invalid arguments");
	else if (abs(std::stoi(argv[1])) < 1)
		throw Exception(get_error_msg(202), "invalid size");
	for (int j = 1; j < 3; j++) {
		for (unsigned i = 0; i < strlen(argv[j]); i++)
			if (!isdigit(argv[j][i]))
				throw Exception(get_error_msg(203), "invalid number(s)");
			// Will also exit if the number entered is negative because
			// a negative sign is a non-digit char.
		if (argv[j][0] == '0' && strlen(argv[j]) > 1)
			warn("leading zeros are not welcome here");
	}		
}

Exception::Exception(const char * msg, const char * err) throw() : _type(err), _help(msg) {}

const char * Exception::what() const throw()
{
	std::cerr << BOLD << "KAP: " << RED << _type << ": " << RESET << _help << std::endl;
	return "stacksack compilation terminated.";
}
