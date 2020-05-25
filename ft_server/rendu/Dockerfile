FROM	debian:buster

MAINTAINER	tiddy42 <tidminta@student.42.fr> 

USER root

WORKDIR	/tmp

EXPOSE	80
EXPOSE	443

#Maj gestionnaire de paquets
RUN	apt update
RUN	apt upgrade -y

#Installation des outils necessaires
RUN	apt install -y procps
RUN	apt install -y vim 
RUN	apt install -y wget 
RUN	apt install -y curl gnupg2 ca-certificates lsb-release

#Installation LEMP
RUN	apt install -y nginx
RUN	apt install -y default-mysql-server
RUN	apt install -y php-fpm php-mysql 
RUN	apt install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
RUN	apt install -y php-json php-mbstring
RUN	rm /var/www/html/index.nginx-debian.html 

#Installation phpmyadmin
RUN	mkdir /var/www/html/phpmyadmin
RUN	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN	tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
COPY	./srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
RUN	chmod 660 /var/www/html/phpmyadmin/config.inc.php
RUN	chown -R www-data:www-data /var/www/html/phpmyadmin

#Installation  et config wordpress
RUN	mkdir /var/www/html/wordpress
RUN	curl -LO https://wordpress.org/latest.tar.gz
RUN	tar xzvf latest.tar.gz --strip-components=1 -C /var/www/html/wordpress
RUN	chown -R www-data:www-data /var/www/html/wordpress

#Certificat ssl
RUN	openssl req -x509 -nodes -days 365 \
	-subj "/C=FR/ST=IFD/O=42 Paris/CN=tidminta@student.42.fr" -addext "subjectAltName=DNS:localhost" \
	-newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

#copies de fichiers
COPY	./srcs/services_starting.sh /tmp/services_starting.sh
COPY	./srcs/default /etc/nginx/sites-available/default

#Creation batabase	CMD ["/bin/sh", "/tmp/services_starting.sh"]
CMD 	sh services_starting.sh; sleep infinity
