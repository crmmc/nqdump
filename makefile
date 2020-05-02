all:
	g++ -std=c++17 -O3 src/main.cpp src/qm/crypt.cpp src/nm/cJSON.cpp src/nm/aes.cpp src/nm/ncmcrypt.cpp -o nqdump -ltag
	strip nqdump

install: all
	mv nqdump /usr/local/bin
