FROM debian:bullseye

WORKDIR /data

EXPOSE 80

COPY . .

RUN apt-get update \ 
&& apt-get install -y composer apache2 php7.4 php7.4-mysql\
&& apt-get clean \
&& composer install \
&& mv ./apache2.conf /etc/apache2/sites-available/my-site.conf \
&& a2dissite 000-default \
&& a2enmod rewrite \
&& a2enmod headers \
&& a2ensite my-site 

CMD ["apachectl","-D","FOREGROUND"]

