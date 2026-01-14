#! /bin/bash
rm -rf builddir/

apt install meson
apt install libsbc-dev
apt install libbluetooth-dev libdbus-1-dev libsbc-dev liblc3-dev libfdk-aac-dev libfreeaptx-dev libldacbt-abr-dev libldacbt-enc-dev libudev-dev
#./autogen.sh -Dbluez5=enabled -Dbluez5-codec-lc3=enabled -Dbluez5-codec-aac=enabled -Dbluez5-codec-aptx=enabled -Dbluez5-codec-ldac=enabled
./autogen.sh
