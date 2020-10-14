#build for macos
#for a release build type: 'scons' or 'scons DBG=0'
#for a debug build type: 'scons DBG=1'
# append -c to clean targets, eg, to clean debug targets: scons DBG=1 -c

#install the following libraries with brew:
#   brew install glfw
#   brew install glew
GLFW_INCLUDE='/usr/local/Cellar/glfw/3.3.2/include'
GLEW_INCLUDE='/usr/local/Cellar/glew/2.2.0/include'

import os

DBG = int(ARGUMENTS.get('DBG', 0))
BLD = 'dbg' if DBG == 1 else 'rel'
OPT = 0 if DBG == 1 else 3

CCFLAGS='-O{} -I {} -I {} -g -std=c++2a'.format(OPT, GLFW_INCLUDE, GLEW_INCLUDE)

env = Environment(CC='g++', CCFLAGS=CCFLAGS)
VariantDir(os.sep.join(['obj', BLD]), "src", duplicate=0)
tst = env.Program(os.sep.join(['bin', BLD, 'tstGame']),
                    source=Glob(os.sep.join(['obj', BLD, '*.cpp'])), 
                    LINK='g++ -framework OpenGL -framework GLUT', 
                    LIBPATH=['/usr/local/Cellar/glew/2.2.0/lib/','/usr/local/Cellar/glfw/3.3.2/lib/'], 
                    LIBS=['GLEW','GLFW','pthread'])

Default(tst)