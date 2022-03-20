FROM debian:buster

WORKDIR /data

COPY ./public/ ./public/
COPY ./src/ .
COPY ./composer.json .
COPY ./apache2.conf /etc/apache2/sites-available/my-site.conf
COPY ./init.sh /

RUN apt update && apt install -y composer apache2 && composer install && a2ensite my-site
RUN service apache2 start

# CMD ["service", "apache2", "start"]
# CMD ["tail", "-f", "/dev/null"]
CMD ["/init.sh"]

# --volume /var/lib/lib:/var/lib/lib \
#                        --volume /var/lib/datacenter:/data \
#                        --volume /var/lib/phpcpp:/phpcpp \
#                        --volume /var/lib/uniclient_src:/uniclient \
#                        --volume /etc/uniclient/:/etc/uniclient \
#                        --volume /etc/sexycoders/keys/datacenter/:/root/.ssh/ \