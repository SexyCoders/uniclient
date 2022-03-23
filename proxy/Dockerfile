FROM debian:bullseye

WORKDIR /data

EXPOSE 80 443

COPY . .

RUN apt-get update \ 
&& apt-get install -y nginx certbot python3-certbot-nginx\
&& apt-get clean \
&& mv ./conf/* /etc/nginx/conf.d/  

CMD ["service","nginx","restart"]
CMD ["tail","-f","/dev/null"]

