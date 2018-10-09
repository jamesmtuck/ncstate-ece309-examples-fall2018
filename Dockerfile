# ECE 309 container for easy use on Windows, Linux, MacOS

FROM gcc

LABEL maintainer="jtuck@ncsu.edu"

RUN apt-get update && apt-get install -y graphviz doxygen git 

ADD . /ece309
WORKDIR /ece309

