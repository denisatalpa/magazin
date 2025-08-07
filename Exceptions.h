#pragma once
#include <string>

class Exception
{
protected:
	std::string message;
	int code;

public:
	Exception(const std::string& message, int code) : message(message), code(code) {}
	virtual ~Exception() = default;

	const std::string& get_message() const { return this->message; }
	const int& get_code() const { return this->code; }
};

template<int exception_code>
class Derived_Exception : public Exception
{
public:
	Derived_Exception(const std::string& message) : Exception(message, exception_code) {}
	virtual ~Derived_Exception() override = default;
};

#define DEFINE_EXCEPTION(exception_name, exception_code) using exception_name = Derived_Exception<exception_code>

DEFINE_EXCEPTION(File_Exception, 1);
DEFINE_EXCEPTION(Cantitate_Depasita_Exception, 2);
DEFINE_EXCEPTION(Produs_Exception, 3);
DEFINE_EXCEPTION(Nr_Maxim_Comenzi, 4);
DEFINE_EXCEPTION(Nr_Maxim_Adrese, 5);
DEFINE_EXCEPTION(Tip_Comanda_Invalid, 6);