FROM debian:bullseye

WORKDIR /data

EXPOSE 80

COPY ./dist/ .
COPY ./apache2.conf /etc/apache2/sites-available/my-site.conf

RUN apt-get update \ 
&& apt-get install -y apache2 \
&& apt-get clean \
&& a2dissite 000-default \
&& a2enmod rewrite \
&& a2enmod headers \
&& a2ensite my-site 

CMD ["apachectl","-D","FOREGROUND"]

