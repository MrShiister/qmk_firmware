FROM mcr.microsoft.com/devcontainers/base:ubuntu26.04

USER root

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends usbutils udev libinput-tools \
    && rm -rf /var/lib/apt/lists/*

USER vscode
RUN curl -fsSL https://install.qmk.fm | sh
