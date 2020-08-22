clang -c ftest.c  
clang -o ttt -g -fsanitize=address,fuzzer     ftest.o /opt/dovecot/liball1.a  

sudo apt-get install -y gettext iftop pandoc  
(git clone https://github.com/dovecot/core.git dovecot && cd dovecot/&& ./autogen.sh&& ./configure --enable-maintainer-mode&& make&&  sudo make install)  

python3 libadd.py /opt/dovecot/  

#create corpus zip file
python3 pars.py allfile 124/ fuzz_test-mail-html2text  


cflow  --tree --brief  dovecot/src/lib-mail/mail-html2text.c   
