cd /dev
sudo wget https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.gz -O boost.tar.gz
sudo tar -xvzf boost.tar.gz
cd boost_1_65_1
sudo ./bootstrap.sh
sudo ./b2