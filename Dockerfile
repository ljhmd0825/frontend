FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    ccache \
    curl \
    make \
    wget \
    file \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /muos-sdk && \
    wget -q https://github.com/ysheng26/muos-docker/releases/download/toolchain/aarch64-buildroot-linux-gnu_sdk-buildroot.tar.gz -O /tmp/sdk.tar.gz && \
    tar xzf /tmp/sdk.tar.gz -C /muos-sdk --strip-components=1 && \
    rm /tmp/sdk.tar.gz && \
    cd /muos-sdk && ./relocate-sdk.sh

ENV XTOOL=/muos-sdk
ENV XHOST=aarch64-buildroot-linux-gnu
ENV XBIN=$XTOOL/bin
ENV PATH="${PATH}:$XBIN"
ENV SYSROOT=$XTOOL/$XHOST/sysroot
ENV DESTDIR=$SYSROOT
ENV CC=$XBIN/$XHOST-gcc
ENV CXX=$XBIN/$XHOST-g++
ENV AR=$XBIN/$XHOST-ar
ENV LD=$XBIN/$XHOST-ld
ENV STRIP=$XBIN/$XHOST-strip
ENV LD_LIBRARY_PATH="$SYSROOT/usr/lib"
ENV CPP_FLAGS="--sysroot=$SYSROOT -I$SYSROOT/usr/include"
ENV LD_FLAGS="-L$SYSROOT -L$SYSROOT/lib -L$SYSROOT/usr/lib -L$SYSROOT/usr/local/lib -L$SYSROOT/usr/include/sound"
ENV CPPFLAGS=$CPP_FLAGS
ENV LDFLAGS=$LD_FLAGS
ENV CFLAGS=$CPP_FLAGS
ENV CCFLAGS=$CPP_FLAGS
ENV CXXFLAGS=$CPP_FLAGS
ENV INC_DIR=$CPP_FLAGS
ENV LIB_DIR=$LD_FLAGS
ENV ARMABI=$XHOST
ENV TOOLCHAIN_DIR=$XTOOL/$XHOST
ENV PKG_CONFIG_PATH=$SYSROOT/usr/lib/pkgconfig
ENV PKG_CONF_PATH=$XBIN/pkgconf
ENV CROSS_COMPILE=$XBIN/$XHOST-
ENV SDL_CONFIG=$SYSROOT/usr/bin/sdl-config
ENV FREETYPE_CONFIG=$SYSROOT/usr/bin/freetype-config

WORKDIR /workspace
