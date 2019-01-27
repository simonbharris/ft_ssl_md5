#include <math.h>

/*
** SEVERELY UNTESTED AND IS PROBABLY 100% BROKEN!!! :D:D:D:D
*/

#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

static const int s[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static const int k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
	0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
	0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
	0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
	0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

int g_hash[4] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476}



int get_new_length(int initial_len)
{
	int new_len;

	new_len = initial_len * 8 + 1;
	while (new_len % 512 != 448)
		new_len++;
	new_len /= 8;
	return (new_len);
}

/*
** Returns the md5 message digest
** Initial_len is reported in bytes
**
** Process new length, append a 1 bit to message, append size in bits, executes process
*/
void md5(char *initial_msg, int initial_len)
{
	unsigned char *msg = NULL;
	int bits_len;
	int new_len = get_new_length(initial_len);

	msg = calloc(new_len + 64, 1);
	// msg = ft_memalloc(new_len + 64, 1) // Change these out for libft stuff
	memcpy(msg, initial_msg, initial_len);
	// ft_memcpy(msg, initial_msg, intiial_len); // change out for libft varient

	msg[initial_len] = 128;
	bits_len = 8 * initial_len;
	memcpy(msg + new_len, &bits_len, 4);
	main_md5_iter(msg);
	free(msg);
	// TODO:
	// puthex(h0...h3);
}

void main_md5_iter(char *msg)
{
	int offset;
	for (offset = 0; offset < new_len; offset += (512/8))
	{
		uint32_t *w = (uint32_t *) (msg + offset);
		uint32_t val[4];
		init_md5_val(val);
		while(i < 64)
			main_loop_process(val)
		add_val_to_hash(val);
	}
}

// Add processed values to hash digest
void add_val_to_hash(int32_t val[4])
{
	h0 += val[0];
	h1 += val[1];
	h2 += val[2];
	h3 += val[3];
}

// Break working hash into parts
void init_md5_val(int32_t val[4])
{
	val[0] = h0;
	val[1] = h1;
	val[2] = h2;
	val[3] = h3;
}

// Part of the loop for digesting a message
void main_md5_loop_process(uint32_t val[4])
{
	int i;

	i = 0;
	while (i < 64)
	{
		uint32_t f;
		uint32_t g;

		if (i < 16)
			md5turn1(&f, &g, i);
		else if (i < 32)
			md5turn2(&f, &g, i);
		else if (i < 48)
			md5turn3(&f, &g, i);
		else
			md5turn4(&f, &g, i);
		shift_values(val, f, g, w);
		i++;
	}
}

//  Moves values around as part of the md5 algorithm
void shift_values(int32_t val[4], int32_t f, int32_t g, int32_t *w)
{
	uint32_t temp;

	temp = d;
	val[3] = val[2];
	val[2] = val[1];
	val[1] = val[1] + LEFTROTATE((val[0] + f + k[i] + w[g]), r[i]);
	a = temp;
}

// md5 turns are part fo the message digest algorithm
void md5turn1(int *f, int *g, int i)
{
	*f = h1 & h2 | ((~h1) & h3);
	*g = i;
}

void md5turn2(int *f, int *g, int i)
{
	*f = (h3 & h1) | ((~h3) & h2);
	*g = (5 * i + 1) % 16;
}

void md5turn3(int *f, int *g, int i)
{
	*f = h1 ^ h2 ^ h3;
	*g = (3 * i + 5) % 16;
}

void md5turn4(int *f, int *g, int i)
{
	*f = h2 ^ (h1 | (~h3));
	*g = (7 * i) % 16;
}
