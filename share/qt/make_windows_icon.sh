#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/DubNextstep.ico

convert ../../src/qt/res/icons/DubNextstep-16.png ../../src/qt/res/icons/DubNextstep-32.png ../../src/qt/res/icons/DubNextstep-48.png ${ICON_DST}
