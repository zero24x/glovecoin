#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/GloveCoin.ico

convert ../../src/qt/res/icons/GloveCoin-16.png ../../src/qt/res/icons/GloveCoin-32.png ../../src/qt/res/icons/GloveCoin-48.png ${ICON_DST}
