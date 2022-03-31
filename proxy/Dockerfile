FROM debian:bullseye

WORKDIR /data

EXPOSE 80 443

COPY . .

RUN apt-get update \ 
&& apt-get install -y nginx certbot python3-certbot-nginx\
&& apt-get clean 

#CMD ["service","nginx","restart"]
CMD ["nginx","-g","daemon off;"]
#CMD ["tail","-f","/dev/null"]

