FROM debian:9

RUN apt-get update && apt-get install --no-install-recommends -y \
    avr-libc \
    avrdude \
    binutils-arm-none-eabi \
    binutils-avr \
    build-essential \
    dfu-programmer \
    dfu-util \
    gcc \
    gcc-arm-none-eabi \
    gcc-avr \
    git \
    libnewlib-arm-none-eabi \
    software-properties-common \
    unzip \
    wget \
    zip \
    && rm -rf /var/lib/apt/lists/*

ENV KEYBOARD=xd60/rev3
ENV KEYMAP=nic888

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

CMD make $KEYBOARD:$KEYMAP && mv .build/ build/
