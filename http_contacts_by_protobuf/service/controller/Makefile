service:./*.cc ./request/*.cc ./response/*.cc ../dao/*.cc ../server/*.cc
	g++ -o $@ $^ -std=c++11 -lpthread -lprotobuf
.PHONY:clean
clean:
	rm -f service