#build for macos

#install the following libraries with brew:
#   brew install glfw
#   brew install glew
GLFW_INCLUDE='/usr/local/Cellar/glfw/3.3.2/include'
GLEW_INCLUDE='/usr/local/Cellar/glew/2.2.0/include'

env = Environment(CC='g++', CCFLAGS='-O3 -I {} -I {} -g -std=c++2a'.format(GLFW_INCLUDE, GLEW_INCLUDE))
VariantDir("obj", "src", duplicate=0)
tst = env.Program('bin/tstGame',
                    source=Glob('obj/*.cpp'), 
                    LINK='g++ -framework OpenGL -framework GLUT', 
                    LIBPATH=['/usr/local/Cellar/glew/2.2.0/lib/','/usr/local/Cellar/glfw/3.3.2/lib/'], 
                    LIBS=['GLEW','GLFW','pthread'])

Default(tst)