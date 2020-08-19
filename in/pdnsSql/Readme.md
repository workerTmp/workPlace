## test1 pipe bin  
sudo pdns_server --no-config --daemon=no --local-port=53 --launch=gmysql --gmysql-user=root --gmysql-password=password --launch+=pipe --pipe-command=pdns/modules/pipebackend/backend.pl --loglevel=7  
dnsdist -C /opt/dnsdist.conf --local=0.0.0.0:5300 -v  

## proxy value  
dig @127.0.0.1 -p 531 values-lua.proxy.tests.powerdns.com.  +tcp  

sudo dnsdist -C /opt/dnsdist2.conf --local=127.0.0.1:531 -v  
sudo pdns_recursor --local-address=127.0.0.1 --allow-from=127.0.0.1 --local-port=9090 --proxy-protocol-from=127.0.0.1  


## pdns recursor RPZ  
sudo bash  
ulimit -n 65536    
pdns_server --no-config --daemon=no --local-port=54 --launch=gmysql --gmysql-user=root --gmysql-password=password  
mkdir /var/run/pdns-recursor  
pdns_recursor --local-address=127.0.0.1 --allow-from=127.0.0.1 --local-port=9090 --forward-zones=mydomain.local=127.0.0.1:54 
dig @127.0.0.1 -p 9090 tut.by


