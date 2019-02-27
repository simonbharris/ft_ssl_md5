#include <ft_ssl.h>

static const uint32_t g_md5_r[] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
    22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static const uint32_t g_md5_k[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void init_hash(unsigned int hashbuff[4])
{
	hashbuff[0] = 0x67452301;
	hashbuff[1] = 0xefcdab89;
	hashbuff[2] = 0x98badcfe;
	hashbuff[3] = 0x10325476;
}

void init_abcd(int abcd[4], unsigned int hashbuff[4])
{
	abcd[0] = hashbuff[0];
	abcd[1] = hashbuff[1];
	abcd[2] = hashbuff[2];
	abcd[3] = hashbuff[3];
}

void add_chunk_result(int abcd[4], unsigned int hashbuff[4])
{
	hashbuff[0] += abcd[0];
	hashbuff[1] += abcd[1];
	hashbuff[2] += abcd[2];
	hashbuff[3] += abcd[3];
}

unsigned char *expand_msg(uint8_t *initial_msg, size_t initial_len, int *new_len)
{
	int bits_len;
	unsigned char *msg;

	*new_len = initial_len * 8 + 1;
	while (*new_len % 512 != 448)
		*new_len += 1;
	*new_len /= 8;
	msg = (unsigned char *)ft_strnew(*new_len + 64);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = 128;
	bits_len = 8 * initial_len;
	ft_memcpy(msg + *new_len, &bits_len, 4);
	return (msg);
}

void md5_turn(int i, int *f, int *g, int abcd[4])
{
    if (i < 16)
    {	
        *f = (abcd[1] & abcd[2]) | ((~abcd[1]) & abcd[3]);
        *g = i;
    }
    else if (i < 32)
    {
        *f = (abcd[3] & abcd[1]) | ((~abcd[3]) & abcd[2]);
        *g = (5 * i + 1) % 16;
    }
    else if (i < 48)
    {
        *f = abcd[1] ^ abcd[2] ^ abcd[3];
        *g = (3 * i + 5) % 16;
    }
    else
    {
        *f = abcd[2] ^ (abcd[1] | (~abcd[3]));
        *g = (7 * i) % 16;
    }
}

void md5_digest_turn(int i, int *w, int abcd[4])
{
	int f;
	int g;

    md5_turn(i, &f, &g, abcd);
	uint32_t temp = abcd[3];
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] = abcd[1] + LEFTROTATE((abcd[0] + f + g_md5_k[i] + w[g]),
								   g_md5_r[i]);
	abcd[0] = temp;
}

void md5_mainloop(uint8_t *msg, int new_len, unsigned int hashbuff[4])
{
	int abcd[4];
	int *w;
	int offset;
	int i;

	offset = 0;
	while (offset < new_len)
	{
		w = (int *)(msg + offset);
		init_abcd(abcd, hashbuff);
		i = 0;
		while (i < 64)
			md5_digest_turn(i++, w, abcd);
		add_chunk_result(abcd, hashbuff);
		offset += (512 / 8);
	}
	ft_memdel((void **)&msg);
}

void process_md5(uint8_t *initial_msg, size_t initial_len,
                 unsigned int hashbuff[4])
{
	unsigned char *msg;
	int new_len;

	msg = NULL;
	init_hash(hashbuff);
	msg = expand_msg(initial_msg, initial_len, &new_len);
	md5_mainloop(msg, new_len, hashbuff);
}
