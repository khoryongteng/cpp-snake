FROM ubuntu:22.04

ARG REQUIRED_PACKAGES=" \
    build-essential \
    cmake \
    ninja-build \
    git \
    pkg-config \
"

ARG RAYLIB_PACKAGES=" \
    libasound2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcursor-dev \
    libxinerama-dev \
    libwayland-dev \
    libxkbcommon-dev \
"

RUN apt-get update && apt-get install -y \
    $REQUIRED_PACKAGES \
    $RAYLIB_PACKAGES \
    && rm -rf /var/lib/apt/lists/*