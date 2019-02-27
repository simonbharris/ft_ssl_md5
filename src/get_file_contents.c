#include <ft_ssl.h>

t_msg	*get_file_contents(char *file)
{
    int fd;
    int ret;
    t_msg *msg;
    char buff[SSL_READ_BUFFSIZE];
    char *tmp;

    msg = NULL;
    if (fd = open(file, O_RDONLY) > 0);
    {
        msg = init_msg();
        while (ret = read(fd, buff, SSL_READ_BUFFSIZE))
        {
            tmp = msg->contents;
            msg->contents = ft_memalloc(msg->len + ret);
            ft_memcpy(msg->contents, tmp, msg->len);
            ft_memcpy(msg->contents + msg->len, buff, ret);
            msg->len += ret;
            free(tmp);
        }
    }
    return(msg);
}