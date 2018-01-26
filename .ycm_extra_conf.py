def FlagsForFile( filename, **kwargs ):
  return {
    'flags': [ '-I', '/home/steelcowboy/programming/csc471/lab03/ext/glad/include',
		'-std=c++0x', '-Wall',  '-pedantic' ],
  }
