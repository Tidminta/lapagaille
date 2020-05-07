FROM	debian:buster

USER root

WORKDIR	usr/src/testing_dir

#Nginx prerequisites
RUN	apt-get install curl gnupg2 ca-certificates lsb-release

#To set up the apt repository for stable nginx packages
RUN echo "deb http://nginx.org/packages/debian `lsb_release -cs` nginx" \
    | sudo tee /etc/apt/sources.list.d/nginx.list

#import an official nginx signing key so apt could verify the packages authenticity
RUN curl -fsSL https://nginx.org/keys/nginx_signing.key | sudo apt-key add -

RUN	apt-get update

RUN	apt-get upgrade

RUN	apt-get install -y nginx
