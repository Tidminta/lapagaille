#!/bin/bash
service nginx start
service mysql start
service php7.3-fpm start
mysql -e "CREATE DATABASE IF NOT EXISTS wordpress; CREATE USER IF NOT EXISTS wordpress_user@localhost IDENTIFIED BY 'password'; GRANT ALL PRIVILEGES ON wordpress.* TO wordpress_user@localhost; FLUSH PRIVILEGES;"
