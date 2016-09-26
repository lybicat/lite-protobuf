from setuptools import setup, Extension


setup(name='liteproto',
      version='1.0',
      description='Lightweighted protobuf decode/encode library',
      test_suite='test_liteproto',
      ext_modules=[
          Extension('liteproto',
              sources=['liteproto.cc'],
              libraries=['protobuf'])
          ])

