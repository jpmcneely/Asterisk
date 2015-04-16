# Asterisk
Asterisk Build for FW LUG

Base OS is Debian Linux 7.7 (Wheezy) for amd64

As Root:

1. Run get-pkgs

2. Create asterisk user: 

     useradd -d /var/lib/asterisk -m -c "Asterisk PBX" -s /bin/bash asterisk
	 
3. Set asterisk user password:

     passwd asterisk	 
	 
4. Add asterisk user to sudo group

5, Run asterisk-build.sh
