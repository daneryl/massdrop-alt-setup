#!/bin/sh

docker run --rm \
  -v $(pwd)/keymap:/qmk_firmware/keyboards/massdrop/alt/keymaps/custom/:Z \
  -v $(pwd)/qmk_firmware/:/qmk_firmware/:Z \
  -v $(pwd)/.build:/qmk_firmware/.build/:Z \
  qmk_firmware
