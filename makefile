default:
	g++ -I/home/bmp/Development/C++/Game/glfw-3.3.2/include/ -L/usr/lib/ -lGLEW -lGLU -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl src/*.cpp /home/bmp/Development/C++/Game/glfw-3.3.2/build/src/libglfw3.a