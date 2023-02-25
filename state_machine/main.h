#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>

enum e_state
{
	LETTER,
	FLAG,
	CONV,
	ERROR,
	END
};

# define FLAG_HH	"hh"
# define FLAG_LL	"ll"
# define FLAG_H		"h"
# define FLAG_L		"l"
# define FLAG_ZERO	"0"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "

# define ALLCONV	"diouxXpcs%"

# define NB_FLAG	7
# define NB_CONV	10

# define TRUE	1
# define FALSE	0

# define HH			0x000001
# define LL			0x000002
# define H			0x000004
# define L			0x000008
# define ZERO		0x000010
# define HASH		0x000020
# define SPACE		0x000040

# define D_CONV		0x000100
# define I_CONV		0x000200
# define O_CONV		0x000400
# define U_CONV		0x000800
# define X_CONV		0x001000
# define XMAJ_CONV	0x002000
# define P_CONV		0x004000
# define C_CONV		0x008000
# define S_CONV		0x010000
# define PER_CONV	0x020000

typedef struct s_state_machine
{
	enum e_state	state;
	va_list			ap;
	char			buffer[4096];
	int				len;
	char			*out;
	int				out_size;
	int				flag;
}				t_state_machine;

typedef int		(*t_function)(char *, t_state_machine *);
typedef void	(*t_conversion)(t_state_machine *);

void	do_conversion(t_state_machine *machine);

#endif 

/*
flag = 0b00000000

00001000
00000000

00001000
00000001


00001001
00001000

00001000


	ajout		flag |= HH
	enleve		flag &= ~HH

	test		if (flag & HH)
*/
