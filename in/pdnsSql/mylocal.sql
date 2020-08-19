USE powerdns
INSERT INTO domains (name, type) values ('my.local', 'NATIVE');
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'my.local','51.0.1.21','A',120,NULL);
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'my.local','localhost ahu@ds9a.nl 1','SOA',86400,NULL);
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'my.local','dns-us1.powerdns.net','NS',86400,NULL);
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'my.local','dns-eu1.powerdns.net','NS',86400,NULL);
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'mail.my.local','192.0.2.12','A',120,NULL);
INSERT INTO records (domain_id, name, content, type,ttl,prio) VALUES (1,'my.local','mail.my.local','MX',120,25);
