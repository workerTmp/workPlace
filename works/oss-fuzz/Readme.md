clang++ -c ftest.c  
clang++ -g -fsanitize=address,fuzzer     ftest.o dovecot/liball1.a  



python3 libadd.py /opt/dovecot/  




cflow  --tree --brief  dovecot/src/lib-mail/mail-html2text.c   
