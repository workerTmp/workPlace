clang -c ftest.c  
clang -o ttt -g -fsanitize=address,fuzzer     ftest.o /opt/dovecot/liball1.a  

sudo apt-get install -y gettext iftop pandoc  
(git clone https://github.com/dovecot/core.git dovecot && cd dovecot/&& ./autogen.sh&& ./configure --enable-maintainer-mode&& make&&  sudo make install)  

python3 libadd.py /opt/dovecot/  




cflow  --tree --brief  dovecot/src/lib-mail/mail-html2text.c   
