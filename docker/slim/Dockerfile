FROM debian:bullseye

WORKDIR /data

EXPOSE 80

COPY . .
#COPY ./public/ ./public/
#COPY ./src/ .
#COPY ./composer.json .
#COPY ./apache2.conf /etc/apache2/sites-available/my-site.conf
#COPY ./init.sh /

RUN apt-get update \ 
&& apt-get install -y composer apache2 \
&& apt-get clean \
&& composer install \
&& mv ./apache2.conf /etc/apache2/sites-available/my-site.conf \
&& a2dissite 000-default \
&& a2ensite my-site \
&& a2enmod rewrite \
&& a2enmod headers \
&& service apache2 restart

CMD ["apachectl","-D","FOREGROUND"]

