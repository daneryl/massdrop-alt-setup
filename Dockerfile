FROM debian:buster-slim
MAINTAINER Ankur Gupta <github.com/agupta231>

RUN apt-get update && \
    apt-get install -y --no-install-recommends ca-certificates \
                                               gcc \
                                               unzip \
                                               wget \
                                               zip \
                                               gcc-avr \
                                               binutils-avr \
                                               avr-libc \
                                               dfu-programmer \
                                               dfu-util \
                                               gcc-arm-none-eabi \
                                               binutils-arm-none-eabi \
                                               libnewlib-arm-none-eabi \
                                               make \
                                               git-core && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* 

RUN cd / && \
    git clone --branch 0.6.301 https://github.com/qmk/qmk_firmware.git && \
    mkdir -p qmk_firmware/keyboards/massdrop/alt/keymaps/daneryl && \
		cd /qmk_firmware && \
		make git-submodule

WORKDIR /qmk_firmware
CMD make massdrop/alt:daneryl 
