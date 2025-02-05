#!/bin/sh
set -e

cd ~/dev/qmk_firmware

# See https://docs.qmk.fm/newbs_getting_started for env setup
make ergodash/rev1:yuki
make ergodash/rev1:yuki:avrdude
