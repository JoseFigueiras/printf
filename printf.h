#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAGS "-0."
# define CONVERSIONS "cspdiuxX%"

typedef unsigned int		t_uint;
typedef unsigned long long	t_u64;

typedef struct 				s_flags
{
	char		flag;
	int			width;
	int			dot;
	int			precision;
	char		size[9];
	char		type;
	void		*save;
}							t_flags;

extern int					g_chars_printed;

int							ft_printf(const char *format, ...);

t_flags						init_flags(void);
int							is_valid(t_flags flags);

int							is_match(const char c, const char *sample);
void						str_push(char *str, const char c);
size_t						size_match(t_flags *flags, char *str);	//returns 0
int							abs(int num);

int							putstr(const char *str);
char						*pad_left(char *str, int final_len, char c);
char						*pad_right(char *str, int final_len, char c);
char						*pad_ptr(char *str, int final_len);
char						*crop(char *str, size_t final_len);
int							printf_char(va_list valist, t_flags flags);
int							printf_str(va_list valist, t_flags flags);
int							printf_ptr(va_list valist, t_flags flags);
int							printf_int(va_list valist, t_flags flags);
int							printf_uint(va_list valist, t_flags flags);
int							printf_hex(va_list valist, t_flags flags);
int							printf_HEX(va_list valist, t_flags flags);
int							printf_percent(void);

#endif
