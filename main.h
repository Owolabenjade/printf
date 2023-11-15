#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmat - Struct op
 *
 * @fmat: The format.
 * @fn: The funct associated.
 */
struct fmat
{
	char fmat;
	int (*fn)(va_list, char[], int, int, int, int);
};

<<<<<<< HEAD

/**
 * typedef struct fmat fmat_t - Struct op
 *
 * @fmat: The format.
 * @fm_t: The funct associated.
 */
typedef struct fmat fmat_t;

int _printf(const char *format, ...);
int hndlePrint(const char *fmat, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FNCTNS ******************/

/* Funtions to print chars and strings */
int prntChar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printStrng(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntPcent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int prntInt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntBnary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntUnsignd(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntOct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntHexD(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prntHexUpper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int prntHexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Funct to print non printable characters */
int prntNonPrntable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funct to print memory address */
int prntPointa(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funct to handle other specifiers */
int getFlags(const char *format, int *i);
int getWidth(const char *format, int *i, va_list list);
int getPrecision(const char *format, int *i, va_list list);
int getSize(const char *format, int *i);

/*Funct to print string in reverse*/
int printRverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Funct to print a string in rot 13*/
int prntRot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
=======
int _printf(const char *format, ...);
#endif
>>>>>>> f6cc1b212d4f024b1d8be92b62b92e120d517fa2
