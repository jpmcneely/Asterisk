#!/bin/bash

# asterisk-1.8.28-cert
# asterisk-app_flite
# dahdi-linux
# dahdi-tools
# libpri

rm -rf /usr/src/dahdi-linux
rm -rf /usr/src/dahdi-tools
rm -rf /usr/src/libpri
rm -rf /usr/src/asterisk-1.8.28-cert
rm -rf /usr/src/asterisk-app_flite

echo "Copying asterisk-1.8.28-cert source..."
cp -a asterisk-1.8.28-cert /usr/src/
echo "Copying asterisk-app_flite source..."
cp -a asterisk-app_flite /usr/src/
echo "Copying dahdi-linux source..."
cp -a dahdi-linux /usr/src/
echo "Copying dahdi-tools source..."
cp -a dahdi-tools /usr/src/
echo "Copying libpri source..."
cp -a libpri /usr/src/

# Build DAHDI Linux
echo
echo -n "Build DAHDI Linux Drivers [Y/n]? "
read R1
if [ ! $R1 ]; then
  R1="Y"
else
  R1=`echo $R1 | tr '[:lower:]' '[:upper:]'`
fi
if [ $R1 = "N" ]; then
  echo "Not Building DAHDI Linux Drivers"
else
  echo "Building DAHDI Linux Drivers"
  cd /usr/src/dahdi-linux
  make all
  make install
fi

# Build DAHDI Tools
echo
echo -n "Build DAHDI Tools [Y/n]? "
read R2
if [ ! $R2 ]; then
  R2="Y"
else
  R2=`echo $R2 | tr '[:lower:]' '[:upper:]'`
fi
if [ $R2 = "N" ]; then
  echo "Not Building DAHDI Tools"
else
  echo "Building DAHDI Tools"
  cd /usr/src/dahdi-tools
  ./configure --prefix=/usr
  make
  make install
  make config
fi

# Build libpri
echo
echo -n "Build PRI Library (libpri) [Y/n]? "
read R3
if [ ! $R3 ]; then
  R3="Y"
else
  R3=`echo $R3 | tr '[:lower:]' '[:upper:]'`
fi
if [ $R3 = "N" ]; then
  echo "Not Building PRI Library (libpri)"
else
  echo "Building PRI Library (libpri)"
  cd /usr/src/libpri
  make
  make install
fi

# Build Asterisk
echo
echo "Building Asterisk..."
echo
cd /usr/src/asterisk-1.8.28-cert
./configure --prefix=/usr

echo
echo "*************************************************************************"
echo "Provide option info"
echo "if you want to have MP3 support, you need to manually turn on 'format_mp3'"
echo "on the first page."
echo "*************************************************************************"
echo
echo "Press ENTER to begin..."
echo
read DUMMY
echo
echo "Preparing Menu..."
echo

make menuselect
make
make install
make config
ldconfig
make samples

# Build app_flite
echo "Building Asterisk app_flite TTS Application..."
cd /usr/src/asterisk-app_flite
make
make install
make samples

# Add user
# TODO: Need to check for existing user.
useradd -m -s /bin/bash -c "Asterisk PBX" asterisk
chown asterisk:asterisk /var/run/asterisk
chown -R asterisk:asterisk /etc/asterisk
chown -R asterisk:asterisk /var/{lib,log,spool}/asterisk
chown -R asterisk:asterisk /usr/lib/asterisk
echo "Set password for asterisk user:"
passwd asterisk

# Set up mysql
# TODO: Need to check for existing user.
echo "Creating MySQL Asterisk user..."
mysqladmin -u root -p create asterisk
mysql -u root -p -e "GRANT ALL PRIVILEGES ON asterisk.* TO asteriskuser@localhost IDENTIFIED BY '${ASTERISK_DB_PW}';"
mysql -u root -p -e "flush privileges;"

# EOF

