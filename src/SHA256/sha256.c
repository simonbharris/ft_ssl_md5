#include <ft_ssl.h>
#include <stdio.h>

//    Initialize array of round constants:
//    (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311):
static const int k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

unsigned long long swap_endian_uint64(long long bits)
{

    return(
            ((bits & 0xff00000000000000ULL) >> 56) |
            ((bits & 0x00ff000000000000ULL) >> 40) |
            ((bits & 0x0000ff0000000000ULL) >> 24) |
            ((bits & 0x000000ff00000000ULL) >>  8) |

            ((bits & 0x00000000ff000000ULL) <<  8) |
            ((bits & 0x0000000000ff0000ULL) << 24) |
            ((bits & 0x000000000000ff00ULL) << 40) |
            ((bits & 0x00000000000000ffULL) << 56)
    );
}

static char quartet_to_hex(unsigned char quartet)
{
    quartet = quartet & 0xf;
    if (quartet < 10)
        return (quartet + '0');
    else
        return ((quartet - 10) + 'a');
}

unsigned int getword(unsigned char *msg, int offset)
{
    int out;

    out = 0;
    for (int i = 0; i < 4; i++)
    {
        out |= msg[offset + i] << (24 - i * 8);
    }
    return (out);
}

static char *sha256tostr(unsigned int hashbuff[8])
{
    char *out;
    int i;
    uint8_t *p;

    i = 0;
    out = ft_strnew(64);
    while (i < 8)
    {
        p = (uint8_t *)&hashbuff[i];
        for (int j = 0; j < 4; j++)
        {
            out[i * 8 + j * 2] = quartet_to_hex((p[3-j] >> 4));
            out[i * 8 + j * 2 + 1] = quartet_to_hex(p[3-j]);
        }
        i++;
    }
    return (out);
}

static unsigned char *expand_msg(uint8_t *initial_msg, size_t initial_len, size_t *new_len)
{
    unsigned char *msg;
    uint64_t bits_len;

    //    Pre-processing message
    *new_len += 1;
    while (*new_len % 64 != 56)
        *new_len += 1;
    msg = (unsigned char *)malloc(sizeof(unsigned char) * (*new_len + 8));
    ft_bzero(msg, *new_len+8);
    ft_memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = (unsigned char) 128;
    bits_len = initial_len * 8;
    bits_len = swap_endian_uint64(bits_len);
    ft_memcpy(msg + *new_len, &bits_len, 8);
    return (msg);
}

char *ft_sha256(unsigned char *initial_msg)
{

//    Initialize hash values:
//    (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19):
    unsigned int h[8];
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

	uint64_t bits_len;

    int new_len;
    int initial_len = ft_strlen((char *)initial_msg);
    uint8_t *msg;

//    Pre-processing message
	new_len += 1;
	while (new_len % 64 != 56)
		new_len += 1;
	msg = (unsigned char *)malloc(sizeof(unsigned char) * (new_len + 8));
    ft_bzero(msg, new_len+8);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = (unsigned char) 128;
	bits_len = initial_len * 8;
    bits_len = swap_endian_uint64(bits_len);
	ft_memcpy(msg + new_len, &bits_len, 8);

    for (int offset = 0; offset < new_len; offset += 512/8)
    {
        unsigned int ah[8];
        unsigned int w[64];

//        TODO: https://en.wikipedia.org/wiki/SHA-2
        // copy chunk into word
        for (int i = offset; offset + i < offset + 64; i++)
        {
            if (i < 16)
                w[i] = getword(msg, offset + i * 4);
            else
            {
                int s0 = RIGHTROTATE(w[i - 15], 7) ^ RIGHTROTATE(w[i - 15], 18) ^ (w[i - 15] >> 3);
                int s1 = RIGHTROTATE(w[i - 2], 17) ^ RIGHTROTATE(w[i - 2], 19) ^ (w[i - 2] >> 10);
                w[i] = w[i - 16] + s0 + w[i - 7] + s1;
            }
        }


        ah[0] = h[0];
        ah[1] = h[1];
        ah[2] = h[2];
        ah[3] = h[3];
        ah[4] = h[4];
        ah[5] = h[5];
        ah[6] = h[6];
        ah[7] = h[7];

        for (int i = 0; i < 64; ++i)
        {
            unsigned int tmp1 = ah[7] + EP1(ah[4]) + CH(ah[4],ah[5],ah[6]) + k[i] + w[i];
            unsigned int tmp2 = EP0(ah[0]) + MAJ(ah[0],ah[1],ah[2]);
//            printf("%8.8x %8.8x %8.8x %8.8x %8.8x %8.8x %8.8x %8.8x\n", ah[0], ah[1], ah[2], ah[3], ah[4], ah[5], ah[6], ah[7]);
            ah[7] = ah[6];
            ah[6] = ah[5];
            ah[5] = ah[4];
            ah[4] = ah[3] + tmp1;
            ah[3] = ah[2];
            ah[2] = ah[1];
            ah[1] = ah[0];
            ah[0] = tmp1 + tmp2;
        }

        h[0] += ah[0];
        h[1] += ah[1];
        h[2] += ah[2];
        h[3] += ah[3];
        h[4] += ah[4];
        h[5] += ah[5];
        h[6] += ah[6];
        h[7] += ah[7];
    }
    char *digest = sha256tostr(h);
    return (digest);
}

int main(void)
{
    char *digest = ft_sha256("a");
    printf("%s\n", digest);
    return(0);
}



/*
e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
eae683379c5492c7c78206a8cb7abae05f05e1abe550cbf82d4de474b7effee7

 128197ca cabd1bca b331c2fa 4ddc239a f8ef86a7 724e7c14 857780b9 bb48eeaf
 ca978112 ca1bbdca fac231b3 9a23dc4d a786eff8 147c4e72 b9807785 afee48bb
SHA256("")
0x e3b0c442 98fc1c14 9afbf4c8 996fb924 27ae41e4 649b934c a495991b 7852b855
   9ec312ad 05258623 a031a732 391411d0 79029e3a fb0cb864 ec48e63c 849e165d

a := h0
b := h1
c := h2
d := h3
e := h4
f := h5
g := h6
h := h7
*/