#build for macos
#for a release build type: 'scons' or 'scons DBG=0'
#for a debug build type: 'scons DBG=1'
# append -c to clean targets, eg, to clean debug targets: scons DBG=1 -c

#install the following libraries with brew:
#   brew install glfw
#   brew install glew
import os

env = Environment(CC='g++')

if env['PLATFORM'] == 'darwin': #macos
    GLFW_DIR='/usr/local/Cellar/glfw/3.3.2'
    GLEW_DIR='/usr/local/Cellar/glew/2.2.0'
    LIBS=['GLEW','GLFW','pthread']
    LINK='g++ -framework OpenGL -framework GLUT'
elif env['PLATFORM'] == 'posix': #linux
    GLFW_DIR='/usr/local' # must 'make install' GLFW 
    GLEW_DIR='/usr/'
    LINK='g++'
    LIBS=['GLEW','GLFW3','pthread']
else:
    print("Error, unsupported platform->", env['PLATFORM'])
    exit()

GLFW_INCLUDE=os.sep.join([GLFW_DIR,'include'])
GLEW_INCLUDE=os.sep.join([GLEW_DIR,'include'])
GLFW_LIB=os.sep.join([GLFW_DIR,'lib'])
GLEW_LIB=os.sep.join([GLEW_DIR,'lib'])

DBG = int(ARGUMENTS.get('DBG', 0))
BLD = 'dbg' if DBG == 1 else 'rel'
OPT = 0 if DBG == 1 else 3

CCFLAGS='-O{} -I {} -I {} -g -std=c++2a'.format(OPT, GLFW_INCLUDE, GLEW_INCLUDE)

VariantDir(os.sep.join(['obj', BLD]), "src", duplicate=0)
tst = env.Program(os.sep.join(['bin', BLD, 'tstGame']),
                    source=Glob(os.sep.join(['obj', BLD, '*.cpp'])),
                    CCFLAGS=CCFLAGS,
                    LINK=LINK,
                    LIBPATH=[GLFW_LIB,GLEW_LIB],
                    LIBS=LIBS)

Default(tst)