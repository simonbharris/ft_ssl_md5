/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 04:30:29 by sharris           #+#    #+#             */
/*   Updated: 2019/03/01 04:30:29 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include "../libft/includes/ft_printf.h"

# define FTSSL_P 0x01
# define FTSSL_Q 0x02
# define FTSSL_R 0x04
# define FTSSL_S 0x08

# define SSL_READ_BUFFSIZE 2048

/*
** SHA Processors
*/

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

/*
** ---- Sructs ----
*/

typedef struct			s_msg
{
	unsigned char	*contents;
	uint64_t		len;
}						t_msg;

typedef struct			s_ssl_f
{
	char *name;
	char *(*funct)(t_msg *);
}						t_ssl_f;

typedef struct			s_ssl_opts
{
	char	c;
	int		flag;
	char	*desc;
}						t_ssl_opts;

/*
**  ------ Globals ------
*/

int						g_ft_ssl_flags;

/*
**  ******************************
**  ------ Public functions ------
**  ******************************
*/

/*
** ------ Utilities ------
*/

unsigned long long		swap_endian_uint64(long long bits);
char					quartet_to_hex(unsigned char quartet);
t_msg					*init_msg();
void					del_msg(t_msg **msg);
void					ft_ssl_usage(void);
void					ft_ssl_help(void);

/*
** ------ Input / Output ------
*/

void					load_ftssl_opts(char **argv, int *ai);
t_msg					*get_file_contents(char *file);
void					handle_stdin(const t_ssl_f *ssl_f);
void					print_explicit_format(t_ssl_f hashtype,
							char *out_digest, char *original, int is_string);

/*
** ------ MD5 ------
*/

void					process_md5(uint8_t *initial_msg, size_t initial_len,
							unsigned int hashbuff[4]);
char					*ft_md5(t_msg *msg);

/*
** ------ SHA Family ------
** SHA224 uses process_sha256
** SHA384 uses process_sha512
*/

void					process_sha256(unsigned char *msg, uint64_t new_len,
							unsigned int h[8]);
void					process_sha512(unsigned char *msg, uint64_t new_len,
							unsigned long long h[8]);

char					*ft_sha224(t_msg *initial_msg);
char					*ft_sha256(t_msg *initial_msg);
char					*ft_sha384(t_msg *initial_msg);
char					*ft_sha512(t_msg *initial_msg);

/*
** **************************
** ------   Globals   -------
** **************************
*/

/*
** ----- Option Flags ------
**
** Keep 's' flag on the last position, since this is a special case for options
** p = Print ; q = Quiet Mode ; r = reverse format ; s = string parameter
*/

static const t_ssl_opts	g_ssl_opts[] =
{
	{ 'p', FTSSL_P, "Prints stdin to screen" },
	{ 'q', FTSSL_Q, "Quiet mode, displays only hash values."},
	{ 'r', FTSSL_R, "Reverse mode, places filename or string after hash"},
	{ 's', FTSSL_S, "String parameter, the following parameter acts as string"
		" instead of file."},
	{ '\0', 0, NULL}
};

/*
** ----- Function Dispatcher ------
**
** function format: char *(*)(char *)
** Pass a message, return a digest
**
** to add more digests, simply add to this list, nowhere else needs changing.
*/

static const t_ssl_f	g_ssl_functs[] =
{
	{ "md5", &ft_md5 },
	{ "sha224", &ft_sha224 },
	{ "sha256", &ft_sha256 },
	{ "sha384", &ft_sha384 },
	{ "sha512", &ft_sha512 },
	{ NULL, NULL }
};

#endif
