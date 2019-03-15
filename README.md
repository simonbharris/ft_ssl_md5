# ft_ssl_md5
The purpose of this project is to merge some functionality from the BSD standalone `md5` program and the `openssl digest functions.

## Usage
usage: ft_ssl command [-pqr] [-s string] [files ...] . 

Options:  
-p -- Prints stdin to screen . 
-q -- Quiet mode, displays only hash values.  
-r -- Reverse mode, places filename or string after hash . 
-s -- String parameter, the following parameter acts as string instead of file.  

Standard commands:  
  [Not yet implemented] . 

Message Digest commands:  
   md5 . 
   sha224 . 
   sha256 . 
   sha384 . 
   sha512 . 
   
Cipher commands:  
  [Not yet implemented] . 
  
## Examples 

--- Basic Input

ft_ssl md5 helloworld.txt . 
MD5 (helloworld.txt) = e59ff97941044f85df5297e1c302d260

--- String option

ft_ssl md5 -s hello . 
MD5 ("hello") = 5d41402abc4b2a76b9719d911017c592

---- Reverse option

ft_ssl md5 -r helloworld.txt . 
e59ff97941044f85df5297e1c302d260 helloworld.txt

ft_ssl md5 -rs helloWorld . 
1a833da63a6b7e20098dae06d06602e1 "helloWorld"

---- Quiet option

ft_ssl sha224 -q -s hello . 
ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193


---- Stdin without print

echo "Hello World" | ./ft_ssl sha384 . 
acbfd470c22c0d95a1d10a087dc31988b9f7bfeb13be70b876a73558be664e5858d11f9459923e6e5fd838cb5708b969

--- Print option

echo "Hello World" | ./ft_ssl sha256 -p . 
Hello World . 
d2a84f4b8b650937ec8f73cd8be2c74add5a911ba64df27458ed8229da804a26

--- Multiple inputs

// Note:  Attempting to use stdin with declared files does not work unless -p option is used

echo "hello world" | md5 -p -s hello -s world . 
hello world . 
6f5902ac237024bdd0c176cb93063dc4 . 
MD5 ("hello") = 5d41402abc4b2a76b9719d911017c592 . 
MD5 ("world") = 7d793037a0760186574b0282f2f435e7 . 
