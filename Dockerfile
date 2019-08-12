FROM debian:buster-slim
MAINTAINER daneyl <github.com/daneryl>

RUN apt-get update && \
    apt-get install -y --no-install-recommends ca-certificates \
                                               sudo \
                                               python3-pip \
                                               git-core && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* 

# RUN cd / && \
#     # git clone --branch 0.6.440 https://github.com/qmk/qmk_firmware.git && \
#     mkdir -p qmk_firmware/keyboards/massdrop/alt/keymaps/daneryl && \
# 		cd /qmk_firmware && \
# 		# make git-submodule


RUN mkdir -p qmk_firmware/util/

COPY qmk_firmware/util/linux_install.sh qmk_firmware/util/linux_install.sh
COPY qmk_firmware/requirements.txt qmk_firmware/requirements.txt

RUN qmk_firmware/util/linux_install.sh

WORKDIR /qmk_firmware

CMD make massdrop/alt:custom
