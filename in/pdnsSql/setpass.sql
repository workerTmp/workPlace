UPDATE mysql.user SET authentication_string=PASSWORD('password') WHERE User='root';
FLUSH PRIVILEGES;
