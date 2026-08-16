FROM ubuntu:latest 

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    curl \
    rustc \
    cargo \
    build-essential \
    git \
    bash \
    cmake \
    unzip \
    wget \
    qtbase5-dev \
    qt6-base-dev \
    libqt5svg5-dev \
    qt5-qmake \
    qttools5-dev-tools && \
    rm -rf /var/lib/apt/lists/*

RUN git clone --recurse-submodules https://github.com/tempestkaguya/melancholy /app

WORKDIR /app

RUN chmod +x run.sh && ./run.sh