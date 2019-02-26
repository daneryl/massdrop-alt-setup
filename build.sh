#!/bin/sh

docker run --rm \
  -v $(pwd):/qmk_firmware/keyboards/massdrop/alt/keymaps/daneryl/:Z \
  -v $(pwd)/.build:/qmk_firmware/.build/:Z \
  massdrop-alt-setup_keyboard
