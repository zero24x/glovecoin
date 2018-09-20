#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/HotshotCoin.ico

convert ../../src/qt/res/icons/HotshotCoin-16.png ../../src/qt/res/icons/HotshotCoin-32.png ../../src/qt/res/icons/HotshotCoin-48.png ${ICON_DST}
