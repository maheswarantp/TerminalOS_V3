# Install prereqs
sudo apt install bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo
sudo apt install grub2-common grub-pc

# Targets
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"


# wget binutils
wget https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.gz
mkdir build-binutils
tar -xzvf binutils-2.40.tar.gz
rm -rf binutils-2.40.tar.gz

# wget gcc
wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz
mkdir build-gcc
tar -xzvf gcc-12.2.0.tar.gz
rm -rf gcc-12.2.0.tar.gz

# build binutils
cd build-binutils
../binutils-2.40/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
cd ../


# build gcc
cd build-gcc
which -- $TARGET-as || echo $TARGET-as is not in PATH

../gcc-12.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
cd ../

# PUT $HOME/opt/cross/bin in PATH SOMEHOW

echo 'export PATH="$HOME/opt/cross/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

rm -rf build-*
rm -rf binutils-*

i686-elf-gcc --version
i686-elf-ld --version
