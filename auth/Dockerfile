FROM debian:bullseye

WORKDIR /data

EXPOSE 80

COPY ./oauth2 .
COPY ./apache2.conf /etc/apache2/sites-available/my-site.conf

RUN apt-get update \ 
&& apt-get install -y composer apache2 php7.4 php7.4-mysql php7.4-redis\
&& apt-get clean \
&& composer install \
&& a2dissite 000-default \
&& a2enmod rewrite \
&& a2enmod headers \
&& a2ensite my-site 

CMD ["apachectl","-D","FOREGROUND"]

