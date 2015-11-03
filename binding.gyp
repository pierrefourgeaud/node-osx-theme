{
  "targets": [{
    "target_name": "osx-theme",
    "sources": [
      "src/osx-theme.mm",
      "src/node-osx-theme.cpp"
    ],
    "include_dirs" : [],
    "cflags_cc!": [
      "-fno-rtti",
      "-fno-exceptions"
    ],
    "cflags!": [
      "-fno-exceptions"
    ],
    "conditions": [
      [
        'OS=="mac"', {
          "libraries": [ "-framework Foundation" ],
          "xcode_settings": {
            'OTHER_CFLAGS': [
              '-arch i386',
              '-arch x86_64',
              '-O0',
              '-g',
              "-ObjC++"
            ],
            'OTHER_CPLUSPLUSFLAGS': [
              '-std=c++11',
              '-stdlib=libc++',
              '-v',
              '-arch i386',
              '-arch x86_64',
              '-O0',
              '-g'
            ],
            'OTHER_LDFLAGS': [
              '-stdlib=libc++',
              '-arch i386',
              '-arch x86_64'
            ],
            'MACOSX_DEPLOYMENT_TARGET': '10.7',
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          }
        }
      ]
    ]
  }
]}