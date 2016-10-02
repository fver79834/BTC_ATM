#ifndef UTIL_H
#define UTIL_H
#define PRINT_SPAM 0
#define PRINT_DEBUG 1
#define PRINT_NOTICE 2
#define PRINT_WARNING 3
#define PRINT_ERROR 4
#define PRINT_CRITICAL 5
#define P_SPAM PRINT_SPAM
#define P_DEBUG PRINT_DEBUG
#define P_NOTICE PRINT_NOTICE
#define P_WARN PRINT_WARNING
#define P_ERR PRINT_ERROR
#define P_CRIT PRINT_CRITICAL
#include "exception"
#include "cstring"
#include "mutex"
#include "iostream"
#include "execinfo.h"
#include "sstream"
extern void sleep_ms(int ms, bool force = false);
extern int search_for_argv(std::string);
extern std::string get_argv(int a);
extern void print(std::string data, int level);
extern long double get_mul_to_btc(std::string currency);
extern long double get_btc_rate(std::string currency);
extern int system_(std::string str);
extern int system_write(std::string command, std::string file);
extern int system_wait_for_file(std::string command, std::string file);
#define LOCK_RUN(a, b)							\
	a.lock();							\
	if(search_for_argv("--spam") != -1){ \
		std::cout << "[SPAM] " << #a << " lock locked for " #b << std::endl; \
	}								\
	try{								\
		b;							\
	}catch(std::exception e){					\
		std::cerr << "Caught " << e.what() << " in LOCK_RUN" << std::endl; \
		a.unlock();						\
		throw e;						\
	}								\
	a.unlock();							\
	if(search_for_argv("--spam") != -1){ \
		std::cout << "[SPAM] " << #a << " lock unlocked" << std::endl; \
	}								\
// print var
#define P_V(a, b) print((std::string)#a + " == '" + std::to_string(a) + "'", b);
// print var string
#define P_V_S(a, b) print((std::string)#a + " == '" + a + "'", b);
// print var char
#define P_V_C(a, b) print((std::string)#a + " == '" + std::string(&a, 1) + "'", b);
// cannot use print here
#endif
