#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/HotShotCoin.ico

convert ../../src/qt/res/icons/HotShotCoin-16.png ../../src/qt/res/icons/HotShotCoin-32.png ../../src/qt/res/icons/HotShotCoin-48.png ${ICON_DST}
