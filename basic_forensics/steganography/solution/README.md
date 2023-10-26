1. open a Kali Linux Terminal
2. use the command `steghide extract -sf secretwith_kitty.jpg -xf answer.txt`
    press [Enter] when prompted to input passphrase.
    ``sf`` specifies the file you want to investigate if it contains steganography
    `-xf` specifies the output file you want the extracted steganography secret to put in.
3. open the output file
4. find the message left by Hello Kitty and the flag ISC2CTF{h4pPy_$T3g0_wIth_K1TTy}
