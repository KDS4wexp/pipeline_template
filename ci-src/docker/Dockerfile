FROM ubuntu

USER root

WORKDIR /build

RUN apt update && \

    # install linux packages
    apt install -y \
    build-essential \
    libmpfr-dev \
    libgmp3-dev \
    libmpc-dev \
    zlib1g-dev \
    gcc-multilib \
    wget

RUN wget http://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.gz && \
    tar -xf gcc-13.2.0.tar.gz && \
    rm gcc-13.2.0.tar.gz
    
    # prepare compiler tools
WORKDIR /build/gcc-13.2.0

RUN ./contrib/download_prerequisites

    # configure compiler
RUN ./configure --enable-bootstrap --enable-languages=c,c++ --prefix=/usr --prog                                                                                                                                                             ram-suffix=-13.2 --mandir=/usr/share/man --infodir=/usr/share/info --enable-shar                                                                                                                                                             ed --enable-threads=posix --enable-checking=release --enable-multilib --with-sys                                                                                                                                                             tem-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-uniqu                                                                                                                                                             e-object --enable-linker-build-id --with-gcc-major-version-only --enable-libstdc                                                                                                                                                             xx-backtrace --with-libstdcxx-zoneinfo=/usr/share/zoneinfo --with-linker-hash-st                                                                                                                                                             yle=gnu --enable-plugin --enable-initfini-array --with-isl --enable-offload-targ                                                                                                                                                             ets=nvptx-none --enable-offload-defaulted --enable-gnu-indirect-function --enabl                                                                                                                                                             e-cet --with-tune=generic --with-arch_64=icelake-server --build=x86_64-redhat-li                                                                                                                                                             nux --with-build-config=bootstrap-lto --enable-link-serialization=1 --with-defau                                                                                                                                                             lt-libstdcxx-abi=new --with-build-config=bootstrap-lto

    # build compiler
RUN make -j4

    # install compiler
RUN make install -j4
