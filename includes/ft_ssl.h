
#ifndef FT_SSL_MD5
# define FT_SSL_MD5

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include "../libft/includes/ft_printf.h"

# define FTSSL_P 0x01
# define FTSSL_Q 0x02
# define FTSSL_R 0x04
# define FTSSL_S 0x08

# define SSL_READ_BUFFSIZE 1024

/*
** Binary rotation macros
*/

# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define RIGHTROTATE(x, c) (((x) >> (c)) | ((x) << (32 - (c))))

/*
** SHA Processors
*/

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (RIGHTROTATE(x,2) ^ RIGHTROTATE(x,13) ^ RIGHTROTATE(x,22))
# define EP1(x) (RIGHTROTATE(x,6) ^ RIGHTROTATE(x,11) ^ RIGHTROTATE(x,25))
# define SHA_S0(w) RIGHTROTATE(w[i - 15], 7) ^ RIGHTROTATE(w[i - 15], 18) ^ (w[i - 15] >> 3);
# define SHA_S1(w) RIGHTROTATE(w[i - 2], 17) ^ RIGHTROTATE(w[i - 2], 19) ^ (w[i - 2] >> 10);
/*
** ---- Sructs ----
*/

typedef struct s_msg
{
	unsigned char *contents;
	uint64_t len;
}				t_msg;

typedef struct	s_ssl_f
{
    char *name;
    char *(*funct)(t_msg *);
}				t_ssl_f;

typedef struct	s_ssl_opts
{
    char c;
    int flag;
}				t_ssl_opts;


/*
**  ------ Globals ------
*/

int g_ft_ssl_flags;

/*
**  ******************************
**  ------ Public functions ------
**  ******************************
*/

/*
** ------ Utilities ------
*/

unsigned long long swap_endian_uint64(long long bits);
char quartet_to_hex(unsigned char quartet);
t_msg *init_msg();
void del_msg(t_msg **msg);
void	ft_ssl_usage(void);
void	ft_ssl_help(void);

/*
** ------ Input / Output ------
*/

void		load_ftssl_opts(char **argv, int *ai);
t_msg	*get_file_contents(char *file);
void handle_stdin(const t_ssl_f *ssl_f);
void print_explicit_format(t_ssl_f hashtype, char* out_digest, char *original , int is_string);

/*
** ------ MD5 ------
*/

void process_md5(uint8_t *initial_msg, size_t initial_len, unsigned int hashbuff[4]);
char *ft_md5(t_msg *msg);


/*
** ------ SHA Family ------
*/

void process_sha224(unsigned char *msg, uint64_t new_len, unsigned int h[8]);
char *ft_sha224(t_msg *initial_msg);

void process_sha256(unsigned char *msg, uint64_t new_len, unsigned int h[8]);
char *ft_sha256(t_msg *initial_msg);


/*
** **************************
** ------ Dispatchers -------
** **************************
*/

/*
** ----- Option Flags ------
**
** Keep 's' flag on the last position, since this is a special case for options
** p = Print ; q = Quiet Mode ; r = reverse format ; s = string parameter
*/

static const t_ssl_opts g_ssl_opts[] =
		{
				{ 'p', FTSSL_P },
				{ 'q', FTSSL_Q },
				{ 'r', FTSSL_R },
				{ 's', FTSSL_S },
				{ '\0', 0 }
		};

/*
** ----- Function Dispatcher ------
**
** function format: char *(*)(char *)
** Pass a message, return a digest
**
** to add more digests, simply add to this list, nowhere else needs changing.
*/

static const t_ssl_f g_ssl_functs[] =
		{
				{ "md5", &ft_md5 },
				{ "sha256", &ft_sha256 },
				{ "sha224", &ft_sha224 },
				{ NULL, NULL }
		};

#endif