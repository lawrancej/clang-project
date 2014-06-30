#!/bin/bash 

printf "[multilib]\nInclude = /etc/pacman.d/mirrorlist" >> /etc/pacman.conf
yes | pacman -Syu # YOLO
yes | pacman -S cmake clang
yes | pacman -S gcc-multilib