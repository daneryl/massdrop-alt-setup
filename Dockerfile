FROM bitnami/minideb:latest
MAINTAINER daneyl <github.com/daneryl>


RUN apt-get clean
RUN apt-get update
RUN apt-get install -y sudo
RUN apt-get install -y build-essential

RUN mkdir -p qmk_firmware/util/

COPY qmk_firmware/util/linux_install.sh qmk_firmware/util/linux_install.sh
COPY qmk_firmware/requirements.txt qmk_firmware/requirements.txt

RUN qmk_firmware/util/linux_install.sh

WORKDIR /qmk_firmware

CMD make massdrop/alt:custom
