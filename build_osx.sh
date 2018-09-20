qmake RELEASE=1 USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1 *.pro
make
export QTDIR=/opt/local/libexec/qt5/
T=$(contrib/qt_translations.py $QTDIR/translations src/qt/locale)
python contrib/macdeploy/macdeployqtplus -add-qt-tr $T -dmg -fancy contrib/macdeploy/fancy.plist HotshotCoin.app